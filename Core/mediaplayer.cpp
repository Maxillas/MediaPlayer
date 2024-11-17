#include "mediaplayer.h"
#include <QAudioOutput>
#include <QQmlEngine>
#include <QTimer>

MediaPlayer::MediaPlayer(QObject *parent)
    : QObject{parent}
{
    m_mediaPlayer = new QMediaPlayer(this);
    m_audioOutput = new QAudioOutput(this);
   // m_audioOutput->setDevice()
    m_mediaPlayer->setAudioOutput(m_audioOutput);
    //m_mediaPlayer->setSource(QString("Try.mp3"));

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

bool MediaPlayer::isPlaying() const
{
    return m_isPlaying;
}

// PlaylistModel &MediaPlayer::playList()
// {
//     return m_playListManager.playList();
// }

PlaylistManager& MediaPlayer::playListManager()
{
    return m_playListManager;
}

void MediaPlayer::setIsPlaying(bool newIsPlaying)
{
    if (m_isPlaying == newIsPlaying)
        return;
    m_isPlaying = newIsPlaying;
    emit isPlayingChanged();
}
