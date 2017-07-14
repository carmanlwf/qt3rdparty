
#include <QApplication>
// #include "psapi.h"
#include<windows.h>
#include<QDebug>
#include<QProcess>
#include"winnt.h"
#include"winreg.h"
#include"tlhelp32.h"
//判断进程是否存在返回为0就是存在
#include"myhelper.h"
#include"mytcpserver.h"
#include"baseclass.h"
#include<QTextCodec>
#include"parklotupdate.h"
#include<QSettings>
#include<QDir>
#include<QFileInfo>
#include<QProcess>
#include<QThread>
#include <qmqtt.h>
#include <QCoreApplication>
#include <QTimer>
#include <QtXlsx>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));


    //复制文件
    /*
        QString toDir , sourceDir;

        sourceDir="Update.xml";
        toDir="F:/qt_example_and_Means/aaqmldemo/mydemo/release/Update.xml";
        bool coverFileIfExist=true;

          toDir.replace("\\","/");
          if (sourceDir == toDir){
             // return true;
          }
          if (!QFile::exists(sourceDir)){
              qDebug()<<"file not find";
          }
          QDir *createfile   = new QDir();
          bool exist = createfile->exists(toDir);
          if (exist){
              if(coverFileIfExist){
                  createfile->remove(toDir);
              }
          }//end if

          if(!QFile::copy(sourceDir, toDir))
          {
                 qDebug()<<"copy error";
          }
         */

    //流程

     //修改 xml文件

    //7zip
    //qDebug()<<"compress"<< MyHelper::Compress("Update.xml","Update.7z");
    //rsa

    /*
   const QString  pri= "30820274020100300D06092A864886F70D01010105000482025E3082025A02010002818100B2088739ECA5D21A3E4EC8F9719E2707F910B4A1A193D65610DAC2DEEF86A8E9BBB8081C74EC6EE023B283393C774324DC1A4D8C809E2D32A628B4965F50CB22696E37B5C2F7E53FF0C052FDBC3BFCDFBDDDDFEEDA0FF3D3B950576AD68F2AF295DDBCC472332A785503453237379080E7850DB05F7DBE8010FE1F4DF6D52827020111028180053C7C72A513EF975C2F7E61B084A6CB8753509B5793682FB5339C51D9DE50431C1C003D127F6CAC3D4903DC094ECD44D94C1156F4B95BAEAA88BA046C3715087E0515A2719C58F5F5B8B3FD45059D77D18269D2900FAFBAE06DCB053F31CA442EA8FE033C37EF13B2427E753E4774BB895CB2873FDD01AA193004B43F1903F1024100C2DA30B8677084DCE2C7E9FD4DBA3D3EA7C34EC8A78BC5C5E77DFCF70E611E48D78AFD1C66E64E8C095CFF622D679D613504416D349ED29AA67E67A71FBA9101024100E9E7276A44C38FB86B70815D43C2D5B742C8832F106ED73C033D63C163912F9B8BE1033A0BDF1B4E9ED17A3DC45272377431164CAF84B34E121F17B675C811270240672837E927B40A1A962D99FE928FC6121C94931EEF49FF4AA7BB2B91DA6FA69F08B2FE7872B629956E5E6915DBCD716FB2A7E666FDBD7E8E1BE8913A5C1779F1024100DC24D9CD6DE53BF8DD971057C74DF65220BCB7B3D33B24ED3039C74C99F20EB083A699A00B2C55EFA488EB856D7AC5D9D6C4C9B196228AA3D4D1F83341AD3D5102402AFF045AA005D107740C1D6B280ACBA99573B43B222148237E6B4A6A3A77770053AAC465B15C451EF360277E068E45B277C6647DC806606FD81521899AA1F98F";
   const QString  pub= "30819D300D06092A864886F70D010101050003818B0030818702818100B2088739ECA5D21A3E4EC8F9719E2707F910B4A1A193D65610DAC2DEEF86A8E9BBB8081C74EC6EE023B283393C774324DC1A4D8C809E2D32A628B4965F50CB22696E37B5C2F7E53FF0C052FDBC3BFCDFBDDDDFEEDA0FF3D3B950576AD68F2AF295DDBCC472332A785503453237379080E7850DB05F7DBE8010FE1F4DF6D52827020111";

   QJsonObject json;
   json.insert("Name", "Qt");
   json.insert("Company", "Digia");
   json.insert("From", 1991);
   json.insert("From", 1992);
   // 构建 Json 文档
   QJsonDocument document;
   document.setObject(json);
   QByteArray byteArray = document.toJson(QJsonDocument::Compact);
   QString strJson(byteArray);

   qDebug()<<"strjson"<<strJson;


      char priKey[128] = {0};
      char pubKey[128] = {0};
      char seed[1024]  = {0};
      // 生成 RSA 密钥对
      strcpy(priKey, "pri");  // 生成的私钥文件
      strcpy(pubKey, "pub");  // 生成的公钥文件
      strcpy(seed, "seed");
    // RSAHelper::GenerateRSAKey(1024, priKey, pubKey, seed);
     qDebug()<<"priKey"<< priKey<<"pubKey"<<pubKey <<"seed"<<seed;
      // RSA 加解密
      char message[1024] = {0};
      cout<<"Origin Text:\t"<<"Hello World!"<<endl<<endl;
      strcpy(message, "Hello World!");
      QString encryptedText =  RSAHelper::RSAEncryptString(pubKey, seed, strJson.toStdString().c_str());  // RSA 加密
      qDebug()<<"Encrypted Text:\t"<<encryptedText;
      QString decryptedText =  RSAHelper::RSADecryptString(priKey, encryptedText.toStdString().c_str());  // RSA 解密
      qDebug()<<"Decrypted Text:\t"<<decryptedText;
        */
    //MyTcpServer tcp(8080);

    //xlsx
    /*
           QXlsx::Document xlsx;
            xlsx.write("A1", "Hello Qt!");
            xlsx.saveAs("Test.xlsx");
            */

    // 安装消息处理程序
    //  qInstallMessageHandler(LogInfo::myMessageOutput);

     // MqttHelper  mqtt;
    //文件夹与文件判断
    /*
      QDir dir;
      dir=QDir(dir.absolutePath()+"/log");
      if(!dir.exists())
      {
          qDebug()<<"NO EXIST"<<"dir info"<<dir.absolutePath();
         bool ok = dir.mkdir(dir.absolutePath());//只创建一级子目录，即必须保证上级目录存在
         qDebug()<<"ok?"<<ok;
      }
      else{
          qDebug()<<"exist";
      }
      QString mfilename;

      mfilename= dir.absolutePath()+"/"+QDateTime::currentDateTime().toString("yyyy-MM-dd")+"log.txt";

      qDebug()<<mfilename;
      */

    // 构建 Json 对象
   // package
   /*
    QJsonObject json;
    json.insert("Name", "Qt");
    json.insert("Company", "Digia");
    json.insert("From", 1991);

    // 构建 Json 文档
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);
    qDebug()<<"byteArray"<<byteArray.size()<<"strJson" <<strJson.size();

    BaseClass  bc;
    bc.head=QString("asd123dfg4568678678w").rightJustified(20);    // asd123dfg4568678678w
    bc.len=2;
    bc.pack_type=3;
    bc.timestamp=QString("2017-07-13 09:20:16");
    bc.version=QString("1.2").rightJustified(4);
    bc.data=strJson;
    bc.sign_type=QString("");
    bc.sign=QString("2333").rightJustified(8);

    //用于暂存我们要发送的数据
       QByteArray block,ba;

       block+=bc.head;
       qDebug()<<"len0"<<block.size();
       block+= QByteArray::number(bc.len).rightJustified(4);
       qDebug()<<"len1"<<block.size();
       block+=ba.setNum(bc.pack_type).rightJustified(2);
       qDebug()<<"len2"<<block.size();
       block+=bc.timestamp;
       qDebug()<<"len3"<<block.size();
       block+=bc.version;
       qDebug()<<"len4"<<block.size();
       block+=bc.data;
       qDebug()<<"len5"<<block.size();
       block+=bc.sign;
       qDebug()<<"len6"<<block.size();
       //使用数据流写入数据

    QTcpSocket  tcp;
    tcp.connectToHost("127.0.0.1",6666);
    tcp.write("bgin");
    tcp.write(byteArray);

    tcp.write("press");
    tcp.write(block);

    qDebug()<< "block"<<block<<"str"<<strJson<<" s"<<QString(block)<<"len"<<block.size();

    */

    //service
    /*
#if !defined(Q_OS_WIN)
    // QtService stores service settings in SystemScope, which normally require root privileges.
    // To allow testing this example as non-root, we change the directory of the SystemScope settings file.
    QSettings::setPath(QSettings::NativeFormat, QSettings::SystemScope, QDir::tempPath());
    qWarning("(Example uses dummy settings file: %s/QtSoftware.conf)", QDir::tempPath().toLatin1().constData());
#endif

    HttpService service(argc, argv);
    */

     return a.exec();

}

