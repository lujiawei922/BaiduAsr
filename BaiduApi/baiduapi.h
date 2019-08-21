#ifndef BAIDUAPI_H
#define BAIDUAPI_H
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <QObject>

//SDK interface
#include "BDSpeechSDK.hpp"
#include "bds_ASRDefines.hpp"
#include "bds_asr_key_definitions.hpp"

using namespace std;


class BaiduApi : public QObject
{
    Q_OBJECT
public:
    explicit BaiduApi(QObject *parent = nullptr);

signals:
    void sendReulst(QString reulst);
public slots:
    int sendPcm(QString path);

private:
//    void asr_set_config_params(bds::BDSSDKMessage &cfg_params);
//    void asr_set_start_params(bds::BDSSDKMessage &start_params);
//    /**
//     * @param file_path IN 文件路径
//     * @param push_cmd IN 固定值 bds::ASR_CMD_PUSH_AUDIO
//     * @param sdk BDSpeechSDK
//     * @param thread_seq demo里的线程编号 用于获取如asr_finish_tags[thread_seq]线程相关的信息
//     */
//    int asr_online_pushaudio(const char *file_path, const std::string &push_cmd, bds::BDSpeechSDK *sdk, int thread_seq);
//    /**
//     * SDK 识别过程中的回调，注意回调产生在SDK内部的线程中，并非调用线程。
//     * @param message IN SDK的回调信息
//     * @param user_arg IN 用户设置set_event_listener的第二个参数
//     *
//     */
//    void asr_online_release(bds::BDSpeechSDK *sdk);
//    int asr_online_stop(bds::BDSpeechSDK *sdk);
//    void *asr_thread(void *arg);

public:
//    friend void asr_output_callback(bds::BDSSDKMessage &message, void *user_arg);

};

#endif // BAIDUAPI_H
