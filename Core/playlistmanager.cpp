#include "playlistmanager.h"
#include <QUrl>
#include <QEventLoop>

#include <QFuture>
#include <QtConcurrent>
//#include <QThread>

PlaylistManager::PlaylistManager(QObject *parent)
    : QObject(parent)
{

}

PlaylistModel &PlaylistManager::playList()
{
    return m_playlist;
}

void PlaylistManager::addTrack(const QList<QUrl> &files)
{

    for (const auto& url : files) {
        auto* player = new QMediaPlayer(this);
        m_players.append(player);
        player->setSource(url);
        connect(player, &QMediaPlayer::durationChanged, this, [this, url, player](qint64 duration) {
            m_playlist.addTrack(url.toLocalFile(), duration);
            m_players.removeOne(player);
            player->deleteLater();
            setPlaylistDuration(m_playlistDuration + duration);
        });
    }
}

QString PlaylistManager::currentTrack() const
{
    return m_currentTrack;
}

void PlaylistManager::setCurrentTrack(QString newCurrentTrack)
{
    if (m_currentTrack == newCurrentTrack)
        return;
    m_currentTrack = newCurrentTrack;
    emit currentTrackChanged();
}

quint64 PlaylistManager::playlistDuration() const
{
    return m_playlistDuration;
}

void PlaylistManager::setPlaylistDuration(quint64 newPlaylistDuration)
{
    if (m_playlistDuration == newPlaylistDuration)
        return;
    m_playlistDuration = newPlaylistDuration;
    emit playlistDurationChanged();
}
