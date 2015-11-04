## QRDeCode Powered QML Module
Designing cool, interactive interfaces. DuoDuoZhijiao came up with a much better answer for QRDeCode: `QML`, a declarative language perfect for designing UIs (and much more). Here's a sample of how QRDeCode Plugin For QML looks like:

![Add Logo](http://7qn7mv.com1.z0.glb.clouddn.com/_ddui111.png)

![No Logo](http://7qn7mv.com1.z0.glb.clouddn.com/_ddui22.png)

```QML
import QtQuick 2.3
import duoduo.decode.components 1.0
DDQRDecoder{
    id:decode
    enabledDecoders: DDQRDecoder.DecoderFormat_QR_CODE
    onDecodingStarted: {
        console.log("扫描开始 ");
        title.text = "扫描中...";
    }
    onDecodingFinished: {
        console.log("扫描结果-----: "+succeeded);
    }
    onTagFound: {
        console.log("扫描结束："+tag);
        title.text = tag;
    }
    onDecodeimageerror:{
        console.log("图片损坏："+error);
    }
}
```

This project aims at bringing the power of qrdecode  to decode the QR code Image or QML Item in QtQuick App.


# Summary
* [How to build](#how-to-build)
* [How to use with QRDeCode](#how-to-use-with-qml-plugins)
* [How to extend](#how-to-extend)
* [Todo](#todo)

## How to Build
#### Add the source code  to your local machine on Mac Windows Linux.
#### Make Sure Setting your env for Qt SDK
#### Use Command
Git clone it.
Build it

```
make clean(mingw32-make clean)
qmake
make （mingw32-make mingw) | nmake(vc)
sudo make install (*unix)
```
## Use QtCreator
You may use qtcreator to build it.


## How to use with QRDeCode
Note that for the following, you need to have `Qt SDK` for Qt5.x or later installed.

#### QRDeCode
You can use QRDeCode to decode your qrencode UI or image file.

```QML
import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import duoduo.encode.components 1.0
import duoduo.decode.components 1.0
ApplicationWindow {
    title: qsTr("WelCome To QtQuick")
    width: 228
    height: 428
    visible: true
    flags: Qt.FramelessWindowHint
    Text {
        id: title
        text: qsTr("WelCome To QtQuick")
        width: parent.width
        height: 30
        anchors.top: parent.top
        anchors.topMargin: 10
        font.pixelSize: 16
        font.family: "Comic Sans MS"
        horizontalAlignment: Text.AlignHCenter
        color: ww.qrForeground
    }
    //编码
    QREnCode{
        id:ww
        width: 128
        height: 128
        qrData: "QQGroup:312125701"
        qrForeground: "#00c853"
        qrLogo: "logo256.png"
        anchors.centerIn: parent
    }
    //解码
    DDQRDecoder{
        id:decode
        enabledDecoders: DDQRDecoder.DecoderFormat_QR_CODE
        onDecodingStarted: {
            console.log("扫描开始 ");
            title.text = "扫描中...";
        }
        onDecodingFinished: {
            console.log("扫描结果-----: "+succeeded);
        }
        onTagFound: {
            console.log("扫描结束："+tag);
            title.text = tag;
        }
        onDecodeimageerror:{
            console.log("图片损坏："+error);
        }
    }
    MainForm {
        anchors.bottom: parent.bottom
        width: parent.width
        height: 30
        button1.onClicked: {
            decode.decodeImageQML(ww)
        }
        button2.onClicked: {
            decode.decodeImageFromFile("xxxxx/20151607182842.png");
        }
    }
}

```

#### Implemented  QML Extension USE C++ (QQmlExtensionPlugin)
Implemented a QML Extension module that:
- Refer to [http://doc.qt.io/qt-5/qqmlextensionplugin.html](http://doc.qt.io/qt-5/qqmlextensionplugin.html).

#### Implemented properties
- processingTime           (decode elapsed time)
- enabledDecoders     (set decode mode)

#### Implemented signals
- void decodingStarted();
- void decodingFinished(bool succeeded);
- void tagFound(QString tag);
- void enabledFormatsChanged();
- void decodeimageerror(bool error);

#### Implemented slots and functions
- decodeImage(QImage image, int maxWidth=-1, int maxHeight=-1, bool smoothTransformation = false) (decode  image object )
- decodeImageFromFile(QString imageFilePath, int maxWidth=-1, int maxHeight=-1, bool smoothTransformation = false) (decode local image or resource file)
- decodeImageQML(QObject *item) (The decoding function accessible from QML)
- decodeSubImageQML(QObject* item,const double offsetX = 0 , const double offsetY = 0,const double width = 0, const double height = 0)  (Able to set the decoding * of a portion of the image.)
- getProcessTimeOfLastDecoding() (get elapsed time)

## FeedBack

Contact information

- Email(373955953#qq.com, Change#to@)
- QQ: 39559539234
- QQ Group:312125701
- github: [寒山-居士](https://github.com/toby20130333)


## Thanks

[https://github.com/SonyPony/QZXing](https://github.com/SonyPony/QZXing)

## About Author

```
  var duoduozhijiao = {
    nickName  : "寒山-居士",
    site : "http://www.heilqt.com",
    blog : "http://blog.heilqt.com"
  }
  ```
