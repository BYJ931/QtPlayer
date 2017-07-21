/*******************************************************************************

IMediaPlayer.h
�ӿ���

����ʱ����QWidget*
����OpenFile��OpenURL��Open���ļ�����Ⱦ����

*******************************************************************************/

#ifndef IMEDIAPLAYER_H
#define IMEDIAPLAYER_H

class QWidget;
class IMediaPlayer
{
public:
    IMediaPlayer(QWidget* pWidget);
    virtual ~IMediaPlayer();

    virtual bool OpenFile();
    virtual bool OpenURL(const char* url);

    virtual bool Open(const char* url) = 0;
    virtual bool Play() = 0;
    virtual void Pause() = 0;
    virtual void Stop() = 0;
    virtual void ChangeVolume(int vol) = 0;

protected:
    QWidget* m_pWidget;
};

#endif // IMEDIAPLAYER_H