#include "myservice.h"

const QString appname = "DataManageTools.exe";

MyService::MyService(int argc, char **argv)
    : QtService<QCoreApplication>(argc, argv, "DataManageToolsService")
{
    setServiceDescription("A dummy HTTP service implemented with Qt");
    setServiceFlags(QtServiceBase::CanBeSuspended);
}

void MyService::start()
{
    QCoreApplication *app = application();

#if QT_VERSION < 0x040100
    quint16 port = (app->argc() > 1) ?
                QString::fromLocal8Bit(app->argv()[1]).toUShort() : 8080;
#else
    const QStringList arguments = QCoreApplication::arguments();
    quint16 port = (arguments.size() > 1) ?
                arguments.at(1).toUShort() : 8080;
#endif
    daemon = new MyTcpServer(port, app);

    if (!daemon->isListening()) {
        logMessage(QString("Failed to bind to port %1").arg(daemon->serverPort()), QtServiceBase::Error);
        app->quit();
    }

    //添加定时器
    QTimer *timer = new QTimer();
    connect(timer,  &QTimer::timeout, this, &MyService::checkupdate);
    timer->start(1000*60*10);



}

void MyService::pause()
{
    daemon->pause();
}

void MyService::resume()
{
    daemon->resume();
}

void MyService::checkupdate()
{

    //判断进程是否存在

    if ( !MyHelper::GetProcessidFromName(appname.toStdString().c_str()))
    {
        qDebug()<<"进程不存在";

        //重启进程

        QProcess p;
        p.startDetached(MyHelper::GetPath(false));
    }

    ParklotUpdate  pa;
    if(pa.availableUpdate)
    {

        //终止进程
        // QString  appname="DataManageTools.exe";
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

        QString  oldsyspath = MyHelper::GetPath(true)+"/config/SystemConfig.xml";
        QString  newsyspath = MyHelper::GetPath(true)+"/temp/SystemConfig.xml";
        QString  oldupdapath = MyHelper::GetPath(true)+"/config/Update.xml";
        QString  newupdapath = MyHelper::GetPath(true)+"/temp/Update.xml";
        // MyHelper::copyFileToPath(oldpath ,newpath ,true);
        if( pa.copyFileToPath(oldsyspath,newsyspath,true) && pa.copyFileToPath(oldupdapath, newupdapath,true))
        {

            qDebug()<<"配置文件已复制到临时目录";
        }

        // 备份文件

        pa.UninstallserServer();

        pa.Uninstallser();

        pa.Installser();

        if (pa.HasInstallSuccess())
        {

            pa.UpdateXML();
            //复制文件;

            if( pa.copyFileToPath(newsyspath,oldsyspath,true) && pa.copyFileToPath( newupdapath,oldupdapath,true))
            {

                qDebug()<<"配置文件已复制到临时目录";
            }
            pa.InstallserServer();
        }
        else
        {
            qDebug()<<"安装失败";
        }

    }
}
