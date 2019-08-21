#include "mainwindow.h"
#include <QApplication>
#include "BaiduApi/baiduapi.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    BaiduApi b;
    QObject::connect(&w,&MainWindow::sendFilePath,&b,&BaiduApi::sendPcm);
    w.show();


    return a.exec();
}
