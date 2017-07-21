/*******************************************************************************

VlcMediaPlayer.h
ʹ��libvlcʵ�ֵ�IMediaPlayer

����ʱ����QWidget*
����OpenFile��OpenURL��Open���ļ�����Ⱦ����

����:
    QWidget* pWidget = new QOpenGLWidget();
    pWidget->show();
    auto player = new VlcMediaPlayer(pWidget);
    player->Open("test.hevc");

*******************************************************************************/

#ifndef VLCMEDIAPLAYER_H
#define VLCMEDIAPLAYER_H

#include "IMediaPlayer.h"

struct libvlc_media_player_t;
struct libvlc_instance_t;
class VlcMediaPlayer :
    public IMediaPlayer
{
public:
    VlcMediaPlayer(QWidget* pWidget);
    ~VlcMediaPlayer();

    // ���ÿ�������͸�ֵ
    VlcMediaPlayer(const VlcMediaPlayer&) = delete;
    VlcMediaPlayer& operator=(VlcMediaPlayer&) = delete;

    // Control
    virtual bool Open(const char* url);
    virtual void Play();
    virtual void Pause();
    virtual void Stop();
    virtual void ChangeVolume(int vol) ;

private:
    // ����������
    libvlc_media_player_t *m_pVlcPlayer;

private:
    // libvlcʵ�������д������Ⱦ����һ��
    static libvlc_instance_t *s_pVlcInstance;
    static unsigned int s_ref;
};

#endif // VLCMEDIAPLAYER_H