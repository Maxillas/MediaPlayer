#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include <QMediaPlayer>
//#include <QQueue>
#include "playlistmodel.h"

class PlaylistManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString currentTrack READ currentTrack WRITE setCurrentTrack NOTIFY currentTrackChanged FINAL)
    Q_PROPERTY(quint64 playlistDuration READ playlistDuration WRITE setPlaylistDuration NOTIFY playlistDurationChanged FINAL)


public:
    PlaylistManager(QObject *parent = nullptr);

    PlaylistModel& playList();

    Q_INVOKABLE void addTrack(const QList<QUrl> &files);


    PlaylistModel m_playlist;
    QString currentTrack() const;
    void setCurrentTrack(QString newCurrentTrackIndex);
    quint64 playlistDuration() const;
    void setPlaylistDuration(quint64 newPlaylistDuration);

signals:
    void currentTrackChanged();
    void playlistDurationChanged();

private:
    QString m_currentTrack;

    void addTracks(qint64 duration);


    QVector<QMediaPlayer*> m_players; //нужен для расчета длительности треков при загрузке, чистится после использования
    quint64 m_playlistDuration = 0;
};

#endif // PLAYLISTMANAGER_H
