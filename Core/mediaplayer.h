#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QObject>
#include <QMediaPlayer>

#include "playlistmanager.h"

class MediaPlayer : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isPlaying READ isPlaying WRITE setIsPlaying NOTIFY isPlayingChanged FINAL)


public:
    explicit MediaPlayer(QObject *parent = nullptr);


    bool isPlaying() const;

   // PlaylistModel& playList();
    PlaylistManager& playListManager();

    void setIsPlaying(bool newIsPlaying);

public slots:
    void play(bool isChangeCurrentTrack);
    void pause();
    void stop();
    void repeat();
    void next();
    void prev();
signals:

    void isPlayingChanged();



private:
    QMediaPlayer* m_mediaPlayer;
    QAudioOutput* m_audioOutput;

    PlaylistManager m_playListManager;
    bool m_isPlaying = false;
};

#endif // MEDIAPLAYER_H
