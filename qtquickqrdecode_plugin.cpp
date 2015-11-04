#include "qtquickqrdecode_plugin.h"
#include "ddqrdecoder.h"

#include <qqml.h>

void QtQuickQRDecodePlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    qmlRegisterType<DDQRDecoder>(uri, 1, 0, "DDQRDecoder");
}


