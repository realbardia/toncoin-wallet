#include "ziptools.h"

#include <QFile>

#include <iostream>
#include <fstream>
#include <zlib.h>

using namespace TON::Tools;

bool ZipTools::uncompress(const QString &in_path, const QString &out_path)
{
    QFile in_file(in_path.left(5) == QStringLiteral("qrc:/")? in_path.mid(3) : in_path);
    if (!in_file.open(QFile::ReadOnly))
        return false;

    QFile out_file(out_path);
    if (!out_file.open(QFile::WriteOnly))
        return false;

    // Initialize the zlib stream
    z_stream stream;
    stream.zalloc = Z_NULL;
    stream.zfree = Z_NULL;
    stream.opaque = Z_NULL;
    stream.avail_in = 0;
    stream.next_in = Z_NULL;
    if (inflateInit2(&stream, 16+MAX_WBITS) != Z_OK) {
        qCritical("Failed to initialize zlib stream");
        return false;
    }

    // Read and uncompress the data
    char buffer[1024];
    while (!in_file.atEnd())
    {
        auto data = in_file.readAll();
        stream.avail_in = data.size();
        stream.next_in = (Bytef*)data.data();
        do {
            stream.avail_out = sizeof(buffer);
            stream.next_out = (Bytef*)buffer;
            int ret = inflate(&stream, Z_NO_FLUSH);
            if (ret == Z_STREAM_ERROR) {
                qCritical("zlib stream error");
                inflateEnd(&stream);
                return false;
            }

            out_file.write(buffer, sizeof(buffer) - stream.avail_out);
        } while (stream.avail_out == 0);

        // Finalize the zlib stream
        if (inflateEnd(&stream) != Z_OK) {
            qCritical("Failed to finalize zlib stream");
            return false;
        }
    }

    in_file.close();
    out_file.close();
    return true;
}
