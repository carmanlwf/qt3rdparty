#ifndef MYSERVICE_H
#define MYSERVICE_H

#include <QObject>
#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextStream>
#include <QDateTime>
#include <QStringList>
#include <QDir>
#include <QSettings>
#include <QProcess>
#include<QTimer>
#include "qtservice.h"
#include "mytcpserver.h"
#include <windows.h>
#include"winnt.h"
#include"winver.h"
#include"tlhelp32.h"
#include"parklotupdate.h"

class MyService: public QObject,public QtService<QCoreApplication>
{
   Q_OBJECT

public:
    MyService(int argc, char **argv);

protected:
    void start();

    void pause();

    void resume();
public slots:
   void checkupdate();


private:
    MyTcpServer *daemon;
    //ParklotUpdate pupdate;
};

#endif // MYSERVICE_H
