<img src="configurations/default/linux/share/hicolor/128x128/apps/tonium.png"  align="right" />

# Tonium - Ton Wallet

## What is Tonium

Tonium is a open-source, free and cross platform TON wallet written and developed using C++, Qt framework,TonLib and QtAseman framework and released under the MIT license.

It's a cross platform Wallet designed and developed for Desktop and Smart phones. All primary operating systems like **Linux**💻, **Windows💻**, **macOS**💻, **iOS**📱 and **Android**📱 are fully supported by the Tonium.



<img src="images/adv.png"  align="center" />



## Main Features

- All v4R2, v4R1, v3R2 and v3R1 wallets are supported
- Ton Connect v2 supported
- Fully touch and gesture supported on the Desktop touch screen devices and Smart phones
- QR Scanner
- Biometric Login on the supported platforms
- Auto lock, Lock timer and Blured task manager's thumbnails on iOS
- Multi Language (English, Spanish, Japanese, Chinese, Persian, Russian and ...)
  - Both RTL and LTR layout directions supported
- Dark mode and Light mode
- Deep link supported (using QR scanner, Command line arguments and ...)
- Dynamic Back-end
  - Currently TonLib backends developed. But technicaly Tonium support's different back-end using different libraries.
- Both Wayland and X11 are supported

## Download

You can download Tonium for Linux, Windows, macOS, iOS and Android from releases part of the github.

| Target  |                           Download                           | Note                                                         |
| ------- | :----------------------------------------------------------: | ------------------------------------------------------------ |
| Linux   | [X86_64](https://github.com/realbardia/toncoin-wallet/releases/download/1.0.1/Tonium-1.0.1-x86_64-Linux.AppImage) | Built using Qt5 static and gcc on Debian buster. (Tested and worked on debian and ubuntu, both wayland and x11). |
| Windows | [X86_64](https://github.com/realbardia/toncoin-wallet/releases/download/1.0.1/Tonium-1.0.1-x86_64-Windows.zip) | Built using Qt5 and Mingw. Because of the technical reasons currently Frameless feature disabled on Qt6 build and QR Scanner disabled on Qt5 |
| macOS   | [X86_64](https://github.com/realbardia/toncoin-wallet/releases/download/1.0.1/Tonium-1.0.1-x86_64-macOS.zip) | Built using Qt6 static for x86_64 processors.                |
| iOS     | [arm64](https://github.com/realbardia/toncoin-wallet/releases/download/1.0.1/Tonium-1.0.1-arm64-iOS.ipa) | Built using Qt5. You can install/side-load it using [altstore.io](https://altstore.io/) |
| Android | [arm64](https://github.com/realbardia/toncoin-wallet/releases/download/1.0.1/Tonium-1.0.1-x86_64-Android.apk) | Built using Qt5, NDK platform 23 and SDK 23                  |

## Library and Tools:

- [Qt framework]() (library) (Both Qt5 and Qt6 are supported on all platforms)
  - Personal recommend: Use Qt6 on the desktop to build Tonium and Qt5 on the smart phones
- [TonLib](https://github.com/ton-blockchain/ton) (library)
- [QtAseman](https://github.com/Aseman-Land/QtAseman) (embedded)
- [OpenSSL](https://www.openssl.org/) (library)
- [ZLib](https://zlib.net/) (library)
- [QZXing](https://github.com/ftylitak/qzxing) (embedded)
- [LottieQuick](https://github.com/dseight/lottiequick/) (embedded)
- [rlottie](https://github.com/Samsung/rlottie) (embedded)
- [TON desktop wallet](https://github.com/ton-blockchain/wallet-desktop) (embed some codes)

## How to Build

### Dependencies

To build Tonium you must install dependecies that not embedded on the source. like TonLib, OpenSSL and ...

#### Qt Framework

First you needs Qt framework. To install Qt you could download Qt online installer from https://download.qt.io/official_releases/online_installers/ and install it using a Graphical interface. You can also install it using below commands on the Ubuntu:

```bash
sudo apt-get install qtbase5-dev qt5-default "qml-module-qt*"
```

#### TonLib

There is no pre-built for all target platform and architectures binaries of the TonLib on the internet. 

But I create a repository and upload some of them [here](https://github.com/realbardia/tonlib-builds/releases/tag/2023_May_22).

So you must build and compile it from Documents. On the Ubuntu and many other systems you can install it using below command:

```bash
git clone "https://github.com/ton-blockchain/ton.git" --depth 1 --recursive
cd ton
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=release -DCMAKE_INSTALL_PREFIX=/usr -DTON_ONLY_TONLIB=1 -DBUILD_SHARED_LIBS=OFF ..
make -j4
sudo make install
```

#### OpenSSL and ZLib:

There are many tutorial and documents and pre-built binaries of these libraries on the net. But you could install them using below commands on the Ubuntu:

```bash
sudo apt-get install libssl-dev libcrypt-dev zlib1g-dev
```



### Build Tonium

Tonium building process is easy. on the command line, clone it and build it using below commands:

```bash
git clone "https://github.com/realbardia/toncoin-wallet" --recursive --depth 1
cd toncoin-wallet
mkdir build && cd build
qmake -r .. TON_LIB_PATH=/usr TON_SOURCE_PATH=/where/tonlib/source_code/cloned OPENSSL_LIB_PATH=/usr ZLIB_PATH=/usr
make -j4
make install
```

Where:

- `TON_LIB_PATH` is root path that TonLib installed
- `TON_SOURCE_PATH` is TonLib source-code path
- `OPENSSL_LIB_PATH` is root path that OpenSSL installed (No need if installed on the default location)
- `ZLIB_PATH` is root path that ZLib installed (No need if installed on the default location)



And If you want to build Tonium using QtCreator, Just open Tonium using QtCreator, Navigate to the Projects tab on the left side of the QtCreator and on the qmake's **additional arguments** part, add above extra arguments.

**Note:** You can also set above arguments as system environment variables instead of qmake arguments.

## Run

Just run it

