#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include <QMediaPlayer>
//#include <QQueue>
#include "playlistmodel.h"

class PlaylistManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString currentTrack READ currentTrack WRITE setCurrentTrack NOTIFY currentTrackChanged FINAL)


public:
    PlaylistManager(QObject *parent = nullptr);

    PlaylistModel& playList();

    Q_INVOKABLE void addTrack(const QList<QUrl> &files);


    PlaylistModel m_playlist;
    QString currentTrack() const;
    void setCurrentTrack(QString newCurrentTrackIndex);
signals:
    void currentTrackChanged();
private:
    QString m_currentTrack;

    QString calculateDuration(const QUrl& track);



    void addTracks(qint64 duration);


    QVector<QMediaPlayer*> m_players; //нужен для расчета длительности треков при загрузке, чистится после использования
};

#endif // PLAYLISTMANAGER_H
