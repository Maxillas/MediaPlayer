#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QObject>
#include <QMediaPlayer>

#include "playlistmanager.h"
#include "settingsmanager.h"

class MediaPlayer : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isPlaying READ isPlaying WRITE setIsPlaying NOTIFY isPlayingChanged FINAL)

    Q_PROPERTY(quint64 duration READ duration NOTIFY durationChanged FINAL)
    Q_PROPERTY(quint64 position READ position NOTIFY positionChanged FINAL)


public:
    explicit MediaPlayer(QObject *parent = nullptr);


    bool isPlaying() const;

   // PlaylistModel& playList();
    PlaylistManager& playListManager();
    Q_INVOKABLE const SettingsManager* settingsManager();

    void setIsPlaying(bool newIsPlaying);

    quint64 duration() const;
    quint64 position() const;

public slots:
    void play(bool isChangeCurrentTrack);
    void pause();
    void stop();
    void repeat();
    void next();
    void prev();

    void setPositon(float positionPercent);
    // quint64 currentTrackDuration();
    // quint64 currentTrackPosition_msec(); //в мсек
    // uint8_t currentTrackPosition_percent(); //в процентах

signals:

    void isPlayingChanged();



    void durationChanged(qint64 position);

    void positionChanged(qint64 position);

private:
    QMediaPlayer* m_mediaPlayer;
    //QMediaPlayer* m_mediaPlayer2; для второго канала
    QAudioOutput* m_audioOutput;

    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);

    SettingsManager m_settingManager;
    PlaylistManager m_playListManager;
    bool m_isPlaying = false;
    quint64 m_duration;
    quint64 m_position;
};

#endif // MEDIAPLAYER_H
