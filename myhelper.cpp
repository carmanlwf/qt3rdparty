#include "myhelper.h"

MyHelper::MyHelper()
{

}

bool MyHelper::comand(const QStringList &args)
{
    QProcess p;
    p.start("cmd.exe",args);
    if (p.waitForStarted())
    {
        p.waitForFinished();
        // qDebug() <<QString::fromLocal8Bit(p.readAllStandardOutput());
        return true;
    }
    else
    {
        // qDebug() << "Failed to start Install";
        return  false;
    }
}

QString MyHelper::size(qint64 bytes)
{
    QString strUnit;
    double dSize = bytes * 1.0;
    if (dSize <= 0)
    {
        dSize = 0.0;
    }
    else if (dSize < 1024)
    {
        strUnit = "Bytes";
    }
    else if (dSize < 1024 * 1024)
    {
        dSize /= 1024;
        strUnit = "KB";
    }
    else if (dSize < 1024 * 1024 * 1024)
    {
        dSize /= (1024 * 1024);
        strUnit = "MB";
    }
    else
    {
        dSize /= (1024 * 1024 * 1024);
        strUnit = "GB";
    }

    return QString("%1 %2").arg(QString::number(dSize, 'f', 2)).arg(strUnit);
}

QString MyHelper::speed(double speed)
{
    QString strUnit;
    if (speed <= 0)
    {
        speed = 0;
        strUnit = "Bytes/S";
    }
    else if (speed < 1024)
    {
        strUnit = "Bytes/S";
    }
    else if (speed < 1024 * 1024)
    {
        speed /= 1024;
        strUnit = "KB/S";
    }
    else if (speed < 1024 * 1024 * 1024)
    {
        speed /= (1024 * 1024);
        strUnit = "MB/S";
    }
    else
    {
        speed /= (1024 * 1024 * 1024);
        strUnit = "GB/S";
    }

    QString strSpeed = QString::number(speed, 'f', 2);
    return QString("%1 %2").arg(strSpeed).arg(strUnit);
}

QString MyHelper::timeFormat(int seconds)
{
    QString strValue;
    QString strSpacing(" ");
    if (seconds <= 0)
    {
        strValue = QString("%1s").arg(0);
    }
    else if (seconds < 60)
    {
        strValue = QString("%1s").arg(seconds);
    }
    else if (seconds < 60 * 60)
    {
        int nMinute = seconds / 60;
        int nSecond = seconds - nMinute * 60;

        strValue = QString("%1m").arg(nMinute);

        if (nSecond > 0)
            strValue += strSpacing + QString("%1s").arg(nSecond);
    }
    else if (seconds < 60 * 60 * 24)
    {
        int nHour = seconds / (60 * 60);
        int nMinute = (seconds - nHour * 60 * 60) / 60;
        int nSecond = seconds - nHour * 60 * 60 - nMinute * 60;

        strValue = QString("%1h").arg(nHour);

        if (nMinute > 0)
            strValue += strSpacing + QString("%1m").arg(nMinute);

        if (nSecond > 0)
            strValue += strSpacing + QString("%1s").arg(nSecond);
    }
    else
    {
        int nDay = seconds / (60 * 60 * 24);
        int nHour = (seconds - nDay * 60 * 60 * 24) / (60 * 60);
        int nMinute = (seconds - nDay * 60 * 60 * 24 - nHour * 60 * 60) / 60;
        int nSecond = seconds - nDay * 60 * 60 * 24 - nHour * 60 * 60 - nMinute * 60;

        strValue = QString("%1d").arg(nDay);

        if (nHour > 0)
            strValue += strSpacing + QString("%1h").arg(nHour);

        if (nMinute > 0)
            strValue += strSpacing + QString("%1m").arg(nMinute);

        if (nSecond > 0)
            strValue += strSpacing + QString("%1s").arg(nSecond);
    }

    return strValue;
}

char *MyHelper::Wchar_tToString(wchar_t *wchar)
{
    wchar_t * wText = wchar;
    DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,wText,-1,NULL,0,NULL,FALSE);// WideCharToMultiByte的运用
    char *psText; // psText为char*的临时数组，作为赋值给std::string的中间变量
    psText = new char[dwNum];
    WideCharToMultiByte (CP_OEMCP,NULL,wText,-1,psText,dwNum,NULL,FALSE);// WideCharToMultiByte的再次运用
    //szDst = psText;// std::string赋值
    //delete []psText;// psText的清除
    return  psText;
}

DWORD MyHelper::GetProcessidFromName(const char *name)
{
    PROCESSENTRY32 pe;
    DWORD id=0;
    HANDLE hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    pe.dwSize=sizeof(PROCESSENTRY32);
    if(!Process32First(hSnapshot,&pe))
        return 0;
    while(1)
    {
        pe.dwSize=sizeof(PROCESSENTRY32);
        if(Process32Next(hSnapshot,&pe)==FALSE)
            break;
        if(strcmp((Wchar_tToString(pe.szExeFile)),name)==0)
        {
            id=pe.th32ProcessID;

            break;
        }

    }
    CloseHandle(hSnapshot);
    return id;
}

WINBOOL MyHelper::KillProcess(DWORD ProcessId)
{
    HANDLE hProcess=OpenProcess(PROCESS_TERMINATE,FALSE,ProcessId);
    if(hProcess==NULL)
        return FALSE;
    if(!TerminateProcess(hProcess,0))
        return FALSE;
    return TRUE;
}

bool MyHelper::ExistPath()
{

    QSettings settings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\DataManageTools.exe",QSettings::NativeFormat);
    QString value = settings.value("value", "error").toString();//读
     if(!value.isEmpty())
         return true;
     return  false;
}

QString MyHelper::GetPath(bool is_folder)
{
    QSettings settings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\DataManageTools.exe",QSettings::NativeFormat);
    QString value = settings.value("value").toString();//读

    if (is_folder)
    {
       // return QDir::filePath(value);
        QFileInfo f(value);
        return  f.dir().path();
    }

    return value;

}

bool MyHelper::copyFileToPath(QString sourceDir, QString toDir, bool coverFileIfExist)
{
    //复制配置文件
       toDir.replace("\\","/");
       if (sourceDir == toDir){
           return true;
       }
       if (!QFile::exists(sourceDir)){
           return false;
       }
       QDir *createfile     = new QDir;
       bool exist = createfile->exists(toDir);
       if (exist){
           if(coverFileIfExist){
               createfile->remove(toDir);
           }
       }//end if

       if(!QFile::copy(sourceDir, toDir))
       {
           return false;
       }
       return true;
}

bool MyHelper::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{

}

QString MyHelper::exeVersion(const QString &exePath)
{
    QFileInfo fileInfo(exePath);
    if (!fileInfo.exists())
        return "";

    DWORD dwHandle;
    DWORD dwLen = GetFileVersionInfoSize(exePath.toStdWString().c_str(), &dwHandle);

    LPVOID lpData = new BYTE[dwLen];
    if(!GetFileVersionInfo(exePath.toStdWString().c_str(), dwHandle, dwLen, lpData))
    {
        delete[] lpData;
        return "";
    }

    VS_FIXEDFILEINFO *lpBuffer = NULL;
    UINT uLen;
    if(!VerQueryValue(lpData,
                      QString("\\").toStdWString().c_str(),
                      (LPVOID*)&lpBuffer,
                      &uLen))
    {
        delete[] lpData;

        return "";
    }

    return QString::number((lpBuffer->dwFileVersionMS >> 16) & 0xffff) + "." +
            QString::number((lpBuffer->dwFileVersionMS) & 0xffff) + "." +
            QString::number((lpBuffer->dwFileVersionLS >> 16) & 0xffff) + "." +
            QString::number((lpBuffer->dwFileVersionLS) & 0xffff);
}

int MyHelper::Compress(char *pSrcFile, char *pDstFile)
{

    return  LzmaCompress(pSrcFile,  pDstFile);
}

int MyHelper::Uncompress(char *pSrcFile, char *pDstFile)
{
    return LzmaUncompress(pSrcFile,  pDstFile);
}

BaseClass MyHelper::Convert(const QByteArray &res)
{
    BaseClass  entity ;
    entity.head=res.left(20);
    entity.len=res.mid(21,4).toInt();
    int datalen=res.size();

    // 判断长度
    if(datalen==entity.len )
    {
        entity.pack_type=res.mid(25,2).toShort();
        entity.timestamp=res.mid(27,19);
        entity.version=res.mid(46,3);

        entity.data=res.mid(49,datalen-49-266);
        entity.sign_type=res.mid(datalen-266,10);
        entity.sign=res.right(256);

        // 判断加密
        if (entity.sign==RSAHelper::RSAEncryptString("pubkey","seed",entity.data.toStdString().c_str()))
        {
            /*
             switch (entity.pack_type)
             {

             case "Register":
                 ActionRegiser a;
                 a.recvjson(entity.data);
                 break;
             case "Heart_beat":
                 ActionRegiser a;
                 a.recvjson(entity.data);
                 break;
             case "In":
                 ActionRegiser a;
                 a.recvjson(entity.data);
                 break;
             case "Out":
                 ActionRegiser a;
                 a.recvjson(entity.data);
                 break;
             case "Pay":
                 ActionRegiser a;
                 a.recvjson(entity.data);
                 break;
             case "Recharge":
                 ActionRegiser a;
                 a.recvjson(entity.data);
                 break;
             case "OnlinePay":
                 ActionRegiser a;
                 a.recvjson(entity.data);
                 break;
             default:
                 break;
             }
  */

            return  entity;
        }
        else
        {

            qDebug()<<"加密比对错误";
        }

    }
    else
    {
        qDebug()<<"数据包长度不正确";
    }
    return  entity;

}

QByteArray MyHelper::BackPackage(const QString &park_id, unsigned int len, const QString &action, int result, const QString &recdata, const QString &recsign)
{
    //用于暂存我们要发送的数据
       QByteArray block;
       block+=park_id.rightJustified(16);
       qDebug()<<"len0"<<block.size();
       block+= QByteArray::number(len).rightJustified(4);
       qDebug()<<"len1"<<block.size();
       block+=action.rightJustified(20);
       qDebug()<<"len2"<<block.size();
       block+=QByteArray::number(result);
       qDebug()<<"len3"<<block.size();
       block+=recdata;
       qDebug()<<"len4"<<block.size();
       block+=recsign;
       qDebug()<<"len5"<<block.size();

       //发送数据成功后，显示提示
        return  block;//d.toLocal8Bit();
}

QByteArray MyHelper::DownPackage(const QString &park_id, unsigned int len, unsigned short pack_type, const QString &timestamp, const QString &version, const QString &data, const QString &sign_type, const QString &sign)
{
    //用于暂存我们要发送的数据
       QByteArray block,ba;

       block+=park_id.rightJustified(16);
       qDebug()<<"len0"<<block.size();
       block+= QByteArray::number(len).rightJustified(4);
       qDebug()<<"len1"<<block.size();
       block+=ba.setNum(pack_type).rightJustified(2);
       qDebug()<<"len2"<<block.size();
       block+=timestamp.rightJustified(19);
       qDebug()<<"len3"<<block.size();
       block+=version.rightJustified(3);
       qDebug()<<"len4"<<block.size();
       block+=data;
       qDebug()<<"len5"<<block.size();
       block+=sign_type.rightJustified(10);
       qDebug()<<"len6"<<block.size();
       block+=sign.rightJustified(256);
       qDebug()<<"len6"<<block.size();

       return  block;
}

QString MyHelper::JsontoStr(const QJsonObject &json)
{
    // 构建 Json 文档
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);

    return  strJson;

}

QString XMLHelper::GetNodeValue(const QString &nodename)
{

    //loadfile();

    if(FilePath.isEmpty())
        FilePath="Update.xml";
    QString strFile(FilePath);
    QFile file(strFile);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {  // 以只读模式打开
        qDebug() << QString("Cannot read file %1(%2).").arg(strFile).arg(file.errorString());
        return "error " ;
    }
    xml.setDevice(&file);

    if(xml.readNextStartElement())
    {
        QString elename= xml.name().toString() ;
        Q_ASSERT(xml.isStartElement() && xml.name().toString() == elename);
        while (xml.readNextStartElement())
        {
            QString myelename= xml.name().toString() ;
            if (xml.name().toString() == nodename)
            {
                Q_ASSERT(xml.isStartElement() && xml.name().toString() == nodename);
                return  xml.readElementText();
            }
            else
            {
                xml.skipCurrentElement();  // 跳过当前元素
            }
        }
    }
    else
    {
        return "nofind ";
    }



}

QString XMLHelper::GetAttributesValue(const QString &nodename, const QString &Attributesname)
{

    //load
    if(FilePath.isEmpty())
        FilePath="Update.xml";

    QString strFile(FilePath);
    QFile file(strFile);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {  // 以只读模式打开
        qDebug() << QString("Cannot read file %1(%2).").arg(strFile).arg(file.errorString());
        return  "error ";
    }
    xml.setDevice(&file);
    // loadfile();

    if(xml.readNextStartElement())
    {
        QString elename= xml.name().toString() ;
        Q_ASSERT(xml.isStartElement() && xml.name().toString() == elename);
        while (xml.readNextStartElement())
        {
            QString myelename= xml.name().toString() ;
            if (xml.name().toString() == nodename)
            {
                Q_ASSERT(xml.isStartElement() && xml.name().toString() == nodename);
                QXmlStreamAttributes attributes = xml.attributes();
                if (attributes.hasAttribute(Attributesname))
                {
                    return attributes.value(Attributesname).toString();
                }
                else
                {
                    xml.raiseError("XML file format error.");
                }
            }
            else
            {
                xml.skipCurrentElement();  // 跳过当前元素
            }
        }
    }
    else
    {
        return  "nofind";

    }



}

void XMLHelper::SetNodeValue(const QString &nodename, const QString &nodevalue)
{
    //load
    if(FilePath.isEmpty())
        FilePath="Update.xml";
    QString strFile(FilePath);
    QFile file(strFile);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << QString("Cannot read file %1(%2).").arg(strFile).arg(file.errorString());
        return;
    }

    if (!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    //update
    QDomElement root = doc.documentElement();
    // qDebug() << root.tagName();
    QDomNode node ;  // 返回根节点的第一个子节点
    /**********遍历元素 **********/
    QDomNodeList list = root.childNodes();
    for (int i = 0; i < list.count(); i++)
    {
        node = list.at(i);
        if (node.isElement())
        {
            if( nodename==node.nodeName())
            {
                //node.setNodeValue(nodevalue);
                QDomNode oldnode = node.firstChild();     //标签之间的内容作为节点的子节点出现，得到原来的子节点
                node.firstChild().setNodeValue(nodevalue);   //用提供的value值来设置子节点的内容
                QDomNode newnode = node.firstChild();     //值修改过后
                node.replaceChild(newnode,oldnode);      //调用节点的replaceChild方法实现修改功能

            }
        }
    }
//save
    QFile filexml(strFile);
    if( !filexml.open( QFile::WriteOnly | QFile::Truncate) )
    {
        qWarning("error::ParserXML->writeOperateXml->file.open\n");
        // return false;

    }
    QTextStream ts(&filexml);
    ts.reset();
    ts.setCodec("utf-8");
    doc.save(ts, 4, QDomNode::EncodingFromTextStream);
    filexml.close();

}

void XMLHelper::SetAttributesValue(const QString &nodename, const QString &Attributesname, const QString &Attributevalue)
{
    //load
    if(FilePath.isEmpty())
        FilePath="Update.xml";
    QString strFile(FilePath);
    QFile file(strFile);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << QString("Cannot read file %1(%2).").arg(strFile).arg(file.errorString());
        return;
    }

    if (!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    //update
    QDomElement root = doc.documentElement();
    // qDebug() << root.tagName();
    QDomNode node ;  // 返回根节点的第一个子节点

    /**********遍历元素 **********/
    QDomNodeList list = root.childNodes();
    for (int i = 0; i < list.count(); i++)
    {
        node = list.at(i);

        if (node.isElement())
        {

            if( nodename==node.nodeName())
            {
                node.toElement().setAttribute(Attributesname,Attributevalue);

            }
        }
    }

    QFile filexml(strFile);
    if( !filexml.open( QFile::WriteOnly | QFile::Truncate) )
    {
        qWarning("error::ParserXML->writeOperateXml->file.open\n");
        // return false;

    }
    QTextStream ts(&filexml);
    ts.reset();
    ts.setCodec("utf-8");
    doc.save(ts, 4, QDomNode::EncodingFromTextStream);
    filexml.close();


}

QString XMLHelper::errorString() const
{
    return QString("Error:%1  Line:%2  Column:%3")
            .arg(xml.errorString())
            .arg(xml.lineNumber())
            .arg(xml.columnNumber());
}

void XMLHelper::loadfile()
{
    if(FilePath.isEmpty())
        FilePath="Update.xml";

    QString strFile(FilePath);
    QFile file(strFile);
    if (!file.open(QFile::ReadOnly| QFile::Text))
    {  // 以只读模式打开
        qDebug() << QString("Cannot read file %1(%2).").arg(strFile).arg(file.errorString());
        return  ;
    }

    //
    xml.setDevice(&file);

    if (!doc.setContent(&file))
    {
        file.close();
        return;
    }


}



// 生成RSA密钥对
void RSAHelper::GenerateRSAKey(unsigned int keyLength, const char *privFilename, const char *pubFilename, const char *seed)
{
    RandomPool randPool;

    randPool.Put((byte *)seed, strlen(seed));
    RSAES_OAEP_SHA_Decryptor priv(randPool, keyLength);

    HexEncoder privFile(new FileSink(privFilename));

    priv.DEREncode(privFile);

    privFile.MessageEnd();
    RSAES_OAEP_SHA_Encryptor pub(priv);

    HexEncoder pubFile(new FileSink(pubFilename));
    pub.DEREncode(pubFile);
    pubFile.MessageEnd();
}

// RSA加密
QString RSAHelper::RSAEncryptString(const char *pubFilename, const char *seed, const char *message)
{

        FileSource pubFile(pubFilename, true, new HexDecoder);

        RSAES_OAEP_SHA_Encryptor pub(pubFile);

       // qDebug()<<"pub:"<<(QString)pub;
        RandomPool randPool;
        randPool.Put((byte *)seed, strlen(seed));
        string result;
        StringSource(message, true, new PK_EncryptorFilter(randPool, pub, new HexEncoder(new StringSink(result))));

        return  QString(result.c_str());
}

// RSA解密
QString RSAHelper::RSADecryptString(const char *privFilename, const char *ciphertext)
{
         FileSource privFile(privFilename, true, new HexDecoder);

         RSAES_OAEP_SHA_Decryptor priv(privFile);
        // qDebug()<<"pri:"<<(QString) priv;
         string result;

         StringSource(ciphertext, true, new HexDecoder(new PK_DecryptorFilter(GlobalRNG(), priv, new StringSink(result))));

         return QString(result.c_str());
}

// 定义全局的随机数池
RandomPool & RSAHelper::GlobalRNG()
{
    static RandomPool randomPool;
          return randomPool;
}


MqttHelper::MqttHelper(QObject *parent):QObject(parent)
{
     _number=0;
      _client = new QMQTT::Client(QHostAddress::LocalHost, 1883);
   _Subscriber= new QMQTT::Client(QHostAddress::LocalHost, 1883);


   connect(_client,_client->connected, this, &MqttHelper::Subscribe);
   connect(&_timer, &QTimer::timeout, this, &MqttHelper::onTimeout);
   connect(_client, _client->disconnected, this, &MqttHelper::onDisconnected);

   connect(_Subscriber, _Subscriber->connected, this, &MqttHelper::Subscribe);
   connect(_Subscriber, _Subscriber->subscribed, this, &MqttHelper::onSubscribed);
   connect(_Subscriber, _Subscriber->received, this, &MqttHelper::onReceived);
   Connect();

}

void MqttHelper::Connect()
{

      QHostAddress host("120.24.249.69");
       quint16 port = 1883;

       _client->setHost(host);
       _client->setPort(port);
      // _client->setClientId("client_id_1");
       _client->setUsername("parkhero");
       _client->setPassword("123456");
      // _client->connectToHost();


       _Subscriber->setHost(host);
       _Subscriber->setPort(port);
       _Subscriber->setUsername("parkhero");
       _Subscriber->setPassword("123456");

       _client->connectToHost();
       _Subscriber->connectToHost();

           qDebug()<<"connet ";

}

void MqttHelper::Subscribe()
{
    if (_client->isConnectedToHost())
    {
       _client->subscribe("qmqtt/exampletopic", 0);
       _timer.start(1000);
       qDebug()<<" c: Subscribe";
    }
    if (_Subscriber->isConnectedToHost())
    {
      _Subscriber->subscribe("qmqtt/exampletopic", 0);
      qDebug()<<" s: Subscribe";
    }

}

void MqttHelper::publish()
{
    QString payload = "{\"cmd\":1}";
    qDebug() << payload;
    QMQTT::Message msg(0,"cmd",payload.toLatin1());
    if(_client->isConnectedToHost())
    {
        _client->publish(msg);
    }
    else
    {
        qDebug() << "not connected";
    }
}

void MqttHelper::MqttMsgSubscribed()
{

}

QString MqttHelper::MqttMsgPublishReceived()
{

}

void MqttHelper::ConnectionClosed()
{
       if (_client->isConnectedToHost())
       {
           _client->disconnectFromHost();

       }
       if (_Subscriber->isConnectedToHost())
       {
          _Subscriber->disconnectFromHost();

       }
}

void MqttHelper::onTimeout()
{
    QMQTT::Message message(_number, "qmqtt/exampletopic",
                           QString("Number is %1").arg(_number).toUtf8());
   _client->publish(message);
    _number++;
    if(_number >= 10)
    {
        _timer.stop();
       // disconnectFromHost();
    }
}

void MqttHelper::onDisconnected()
{
    QTimer::singleShot(0, qApp, &QCoreApplication::quit);
}

void MqttHelper::onSubscribed(const QString &topic)
{
    qDebug()<< "subscribed " << topic << endl;
}

void MqttHelper::onReceived(const QMQTT::Message &message)
{
   qDebug() << "publish received: \"" << QString::fromUtf8(message.payload());

}

void LogInfo::myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 加锁
    static QMutex mutex;
    mutex.lock();

    QByteArray localMsg = msg.toLocal8Bit();

    QString strMsg("");
    switch(type)
    {
    case QtDebugMsg:
        strMsg = QString("Debug:");
        break;
    case QtWarningMsg:
        strMsg = QString("Warning:");
        break;
    case QtCriticalMsg:
        strMsg = QString("Critical:");
        break;
    case QtFatalMsg:
        strMsg = QString("Fatal:");
        break;
    }

    // 设置输出信息格式
    QString strDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString strMessage = QString("Message:%1 File:%2  Line:%3  Function:%4  DateTime:%5")
            .arg(localMsg.constData()).arg(context.file).arg(context.line).arg(context.function).arg(strDateTime);


    //文件夹与文件判断
    QDir dir;
    dir=QDir(dir.absolutePath()+"/log");
    if(!dir.exists())
    {

        dir.mkdir(dir.absolutePath());//只创建一级子目录，即必须保证上级目录存在

    }
    QString mfilename;
    mfilename= dir.absolutePath()+"/"+QDateTime::currentDateTime().toString("yyyy-MM-dd")+"log.txt";
    // 输出信息至文件中（读写、追加形式）
    QFile file(mfilename);
    file.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream(&file);
    stream << strMessage << "\r\n";
    file.flush();
    file.close();

    // 解锁
    mutex.unlock();
}
