
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

    //system("E:\\PersonalInformation\\my.bat");
   // system("E:\\PersonalInformation\\Uninstall.bat");

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

    /*
    ParklotUpdate  pa;

    if(pa.availableUpdate)
    {

        //终止进程
        QString  appname="DataManageTools.exe";
        if ( !MyHelper::GetProcessidFromName(appname.toStdString().c_str()))
        {
            qDebug()<<"进程不存在";
        }

        if (!MyHelper::KillProcess(MyHelper::GetProcessidFromName(appname.toStdString().c_str())))
        {
            qDebug()<<"关闭进程失败";
        }

       pa.DownUpdateFile();

     while (pa.downfilepath.isEmpty())
      {

       QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
     //   QThread::sleep(500);

      }
      pa.StopServer();

     //QString   oldpath = MyHelper::GetPath(true)+"/config/SystemConfig.xml";
     //QString   newpath = MyHelper::GetPath(true)+"/temp/SystemConfig.xml";
     // MyHelper::copyFileToPath(oldpath ,newpath ,true);
     // pa.copyFileToPath("","",true);

      pa.UninstallserServer();

      pa.Uninstallser();

      pa.Installser();

      pa.HasInstallSuccess();

      pa.UpdateXML();

      pa.InstallserServer();


    }
   */
     //修改 xml文件

    //7zip
   //qDebug()<<"compress"<< MyHelper::Compress("Update.xml","Update.7z");

    //rsa
    /*
      char priKey[128] = {0};
      char pubKey[128] = {0};
      char seed[1024]  = {0};
      // 生成 RSA 密钥对
      strcpy(priKey, "pri");  // 生成的私钥文件
      strcpy(pubKey, "pub");  // 生成的公钥文件
      strcpy(seed, "seed");
     RSAHelper::GenerateRSAKey(1024, priKey, pubKey, seed);
     qDebug()<<"priKey"<< priKey<<"pubKey"<<pubKey <<"seed"<<seed;
      // RSA 加解密
      char message[1024] = {0};
      cout<<"Origin Text:\t"<<"Hello World!"<<endl<<endl;
      strcpy(message, "Hello World!");
      QString encryptedText =  RSAHelper::RSAEncryptString(pubKey, seed, message);  // RSA 加密
      qDebug()<<"Encrypted Text:\t"<<encryptedText;
      QString decryptedText =  RSAHelper::RSADecryptString(priKey, encryptedText.toStdString().c_str());  // RSA 解密
     qDebug()<<"Decrypted Text:\t"<<decryptedText;
     */
    //MyTcpServer tcp(8080);

    //mqtt

     // MqttHelper  mqtt;
    //mqtt.Connect();
    //xlsx
    /*
           QXlsx::Document xlsx;
            xlsx.write("A1", "Hello Qt!");
            xlsx.saveAs("Test.xlsx");
            */


    // 安装消息处理程序
    //  qInstallMessageHandler(LogInfo::myMessageOutput);

      MqttHelper  mqtt;
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

    return a.exec();
}

