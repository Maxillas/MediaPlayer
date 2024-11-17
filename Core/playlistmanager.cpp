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
            qint64 hours = duration / 3600000;
            qint64 minutes = (duration % 3600000) / 60000;
            qint64 seconds = (duration % 60000) / 1000;
            QString durationStr = QString::asprintf("%02lld:%02lld:%02lld", hours, minutes, seconds);

            m_playlist.addTrack(url.toLocalFile(), durationStr);
            m_players.removeOne(player);
            player->deleteLater();
        });
    }
}

void PlaylistManager::addTracks(qint64 duration)
{
    qDebug() << "Длительность трека:" << QString::number(duration);
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
