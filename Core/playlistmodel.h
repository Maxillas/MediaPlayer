#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractListModel>

class PlaylistModel : public QAbstractListModel
{
    Q_OBJECT

public:

    enum PairRoles {
        TrackName = Qt::UserRole + 1,
        TrackDuration
    };

    explicit PlaylistModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    void addTrack(QString newTrack, QString duration);

private:
    QList<QPair<QString, QString>> m_data;
};

#endif // PLAYLISTMODEL_H
