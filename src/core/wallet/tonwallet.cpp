#include "tonwallet.h"

#include <tonlib/Client.h>

#include <QDir>
#include <QDebug>
#include <QThread>
#include <QQueue>
#include <QMutex>
#include <QMutexLocker>
#include <QRandomGenerator>

#define GENERATE_ID QRandomGenerator::global()->generate64()

#define ERR(OBJ) \
    [](const ton::tl_object_ptr<tonlib_api::error> &err){ \
        Error e; \
        e.code = err->code_; \
        e.message = QString::fromStdString(err->message_); \
        return e; \
    }(ton::move_tl_object_as<tonlib_api::error>(OBJ.object))

using tonlib_api::make_object;
using namespace TON::Wallet;

class TonWallet::Engine: public QThread
{
public:
    typedef std::function<void(tonlib::Client::Response)> ResposeCallback;

    Engine(QObject *parent) : mParent(parent) {}
    virtual ~Engine() {}

    void append(tonlib_api::object_ptr<tonlib_api::Function> func, const ResposeCallback &responseCallback) {
        auto req = std::make_shared<tonlib::Client::Request>();
        req->id = GENERATE_ID;
        req->function = std::move(func);

        mMutex.lock();
        mCallbacks[req->id] = responseCallback;
        mRequests << req;
        mMutex.unlock();
    }

    void doTerminate() {
        mTerimnated = true;
    }

protected:
    void run() override {
        tonlib::Client client;

        while (!mTerimnated)
        {
            mMutex.lock();
            const auto requestsCount = mRequests.count();
            mMutex.unlock();

            auto resp = client.receive(requestsCount? 0.001 : 0.2);
            if (resp.id)
            {
                auto resp_ptr = std::make_shared<tonlib::Client::Response>(std::move(resp));

                mMutex.lock();
                auto callback = mCallbacks.take(resp.id);
                mMutex.unlock();

                QMetaObject::invokeMethod(mParent, [resp_ptr, callback](){
                    callback(std::move(*resp_ptr));
                }, Qt::QueuedConnection);
            }

            if (requestsCount)
            {
                mMutex.lock();
                auto req = mRequests.takeFirst();
                client.send(std::move(*req));
                mMutex.unlock();
            }
        }

        mRequests.clear();
    }

private:
    QObject *mParent;

    QQueue<std::shared_ptr<tonlib::Client::Request>> mRequests;
    QHash<quint64, ResposeCallback> mCallbacks;

    QMutex mMutex;
    bool mTerimnated = false;
};


TonWallet::TonWallet(QObject *parent)
    : Abstracts::AbstractWallet(parent)
{
    SET_VERBOSITY_LEVEL(0);

    mEngine = new Engine(this);
    mEngine->start();
}

TonWallet::~TonWallet()
{
    mEngine->doTerminate();
    mEngine->quit();
    mEngine->wait();
    delete mEngine;
}

void TonWallet::init(const QString &keysDir, const std::function<void(bool done, const Error &error)> &callback)
{
    QDir().mkpath(keysDir);

    tonlib_api::object_ptr<tonlib_api::KeyStoreType> ks_type = make_object<tonlib_api::keyStoreTypeDirectory>(keysDir.toStdString());

    auto init_obj = make_object<tonlib_api::init>(make_object<tonlib_api::options>(nullptr, std::move(ks_type)));

    mEngine->append(std::move(init_obj), [callback](tonlib::Client::Response resp){
        if (resp.object->get_id() == tonlib_api::error::ID)
            callback(false, ERR(resp));
        else
            callback(true, Error());
    });
}
