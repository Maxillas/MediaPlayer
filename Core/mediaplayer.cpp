#include "mediaplayer.h"
#include <QAudioOutput>
#include <QAudioDevice>
#include <QMediaDevices>
#include <QQmlEngine>
#include <QTimer>

MediaPlayer::MediaPlayer(QObject *parent)
    : QObject{parent}
{
    m_mediaPlayer = new QMediaPlayer(this);
    m_audioOutput = new QAudioOutput(this);

    m_settingManager = new SettingsManager(this);

   // m_audioOutput->setDevice()
    m_mediaPlayer->setAudioOutput(m_audioOutput);

    for (const auto& i : QMediaDevices::audioOutputs()) {
        qDebug() << "as = " << i.description();
    }

    connect(m_mediaPlayer, &QMediaPlayer::positionChanged, this, &MediaPlayer::positionChanged);
    connect(m_mediaPlayer, &QMediaPlayer::durationChanged, this, &MediaPlayer::durationChanged);
    connect(m_mediaPlayer, &QMediaPlayer::mediaStatusChanged, this, &MediaPlayer::onMediaStatusChanged);

    QJSEngine::setObjectOwnership(this, QJSEngine::ObjectOwnership::CppOwnership);

}

void MediaPlayer::play(bool isChangeCurrentTrack)
{
    auto currentTrack = m_mediaPlayer->source();
    if(currentTrack.toLocalFile() == m_playListManager.currentTrack() &&
        m_mediaPlayer->isPlaying()) {
        pause();
        return;
    }

    if(currentTrack.isEmpty() || isChangeCurrentTrack) {
        m_mediaPlayer->setSource(m_playListManager.currentTrack());
        m_mediaPlayer->play();
        setIsPlaying(true);
        return;
    }
    m_mediaPlayer->play();
    setIsPlaying(true);
}

void MediaPlayer::pause()
{
    m_mediaPlayer->pause();
    setIsPlaying(false);
}

void MediaPlayer::stop()
{
    m_mediaPlayer->stop();
    m_mediaPlayer->setSource(QUrl());
    setIsPlaying(false);
    emit positionChanged(0);
    emit durationChanged(0);
}

void MediaPlayer::repeat()
{
    m_mediaPlayer->stop();
    m_mediaPlayer->play();
}

void MediaPlayer::next()
{

}

void MediaPlayer::prev()
{

}

void MediaPlayer::setPositon(float positionPercent)
{
    m_mediaPlayer->setPosition(m_mediaPlayer->duration() * positionPercent / 100);
}

void MediaPlayer::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        stop();
    }
}

bool MediaPlayer::isPlaying() const
{
    return m_isPlaying;
}

PlaylistManager& MediaPlayer::playListManager()
{
    return m_playListManager;
}

SettingsManager const *MediaPlayer::settingsManager()
{
    return m_settingManager;
}

void MediaPlayer::setIsPlaying(bool newIsPlaying)
{
    if (m_isPlaying == newIsPlaying)
        return;
    m_isPlaying = newIsPlaying;
    emit isPlayingChanged();
}

quint64 MediaPlayer::duration() const
{
    return m_mediaPlayer->duration();
}

quint64 MediaPlayer::position() const
{
    return m_mediaPlayer->position();
}
