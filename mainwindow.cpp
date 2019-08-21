#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QDebug>
#include <QLabel>
#define TOFILE //存到文件

struct WAVHEADER
{
    // RIFF 头
    char RiffName[4];
    unsigned long nRiffLength;
    // 数据类型标识符
    char WavName[4];
    // 格式块中的块头
    char FmtName[4];
    unsigned long nFmtLength;
    // 格式块中的块数据
    unsigned short nAudioFormat;
    unsigned short nChannleNumber;
    unsigned long nSampleRate;
    unsigned long nBytesPerSecond;
    unsigned short nBytesPerSample;
    unsigned short nBitsPerSample;
    // 数据块中的块头
    char    DATANAME[4];
    unsigned long   nDataLength;
};
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置格式
    QAudioFormat audioFormat;
    audioFormat.setByteOrder(QAudioFormat::LittleEndian);
    audioFormat.setChannelCount(1);
    audioFormat.setCodec("audio/pcm");
    audioFormat.setSampleRate(16000);
    audioFormat.setSampleSize(16);
    audioFormat.setSampleType(QAudioFormat::SignedInt);
    //判断设备，查看是否存在
    QAudioDeviceInfo devInfo = QAudioDeviceInfo::defaultInputDevice();
    if(devInfo.isNull()){
        qDebug() << "未找到录音设备";
    }
    //不支持格式，使用最接近格式
    if(!devInfo.isFormatSupported(audioFormat)){ //当前使用设备是否支持
        audioFormat = devInfo.nearestFormat(audioFormat); //转换为最接近格式
    }
    _audioInput = new QAudioInput(devInfo,audioFormat,this);
    //内存的IO对象
    bufDevice.setBuffer(&voiceData);
}

MainWindow::~MainWindow()
{

}


void MainWindow::on__startBtn_clicked()
{
#ifdef TOFILE //存到文件
   outFile.setFileName(qApp->applicationDirPath() + "/test.pcm"); //语音原始文件
   outFile.open(QIODevice::WriteOnly | QIODevice::Truncate);
   _audioInput->start(&outFile);
#else //存到内存
   bufDevice.open(QIODevice::WriteOnly | QIODevice::Truncate);
   _audioInput->start(&bufDevice);
#endif
}

void MainWindow::on__endBtn_clicked()
{
    _audioInput->stop();
    delete ui;
#ifdef TOFILE
     outFile.close();
#else
     bufDevice.close();
#endif
     emit sendFilePath(qApp->applicationDirPath() + "/test.pcm");
//    QIODevice *device{nullptr};
//    #ifdef TOFILE //存到文件
//        device = &outFile;
//    #else //存到内存
//        device = &bufDevice;
//    #endif
//添加wav文件头
//    static WAVHEADER wavHeader;
//    qstrcpy(wavHeader.RiffName,"RIFF");
//    qstrcpy(wavHeader.WavName,"WAVE");
//    qstrcpy(wavHeader.FmtName,"fmt ");
//    qstrcpy(wavHeader.DATANAME,"data");
//    wavHeader.nFmtLength = 16;
//    int nAudioFormat = 1;
//    wavHeader.nAudioFormat = nAudioFormat;
//    wavHeader.nBitsPerSample = 16;
//    wavHeader.nChannleNumber = 1;
//    wavHeader.nSampleRate = 16000;
//    wavHeader.nBytesPerSample = wavHeader.nChannleNumber * wavHeader.nBitsPerSample / 8;
//    wavHeader.nBytesPerSecond = wavHeader.nSampleRate * wavHeader.nChannleNumber *  wavHeader.nBitsPerSample / 8;
//    wavHeader.nRiffLength = device->size() - 8 + sizeof(WAVHEADER);
//    wavHeader.nDataLength = device->size();
//////写到IO设备头
//    device->seek(0);
//    device->write(reinterpret_cast<char*>(&wavHeader),sizeof(WAVHEADER));
}
