#ifndef ZIPTOOLS_H
#define ZIPTOOLS_H

#include <QString>

namespace TON::Tools
{

class ZipTools
{
public:
    static bool uncompress(const QString &input, const QString &output);
};

}

#endif // ZIPTOOLS_H
