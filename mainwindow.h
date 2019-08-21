#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QPushButton>
#include <QAudioInput>
#include <QBuffer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on__startBtn_clicked();

    void on__endBtn_clicked();

signals:
    void sendFilePath(QString);

private:
        QAudioInput *_audioInput; //录音对象
        QFile outFile;
        QByteArray voiceData;
        QBuffer bufDevice;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
