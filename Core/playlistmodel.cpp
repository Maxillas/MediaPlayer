#include <QUrl>

#include "playlistmodel.h"

PlaylistModel::PlaylistModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

int PlaylistModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_data.size();

}

QVariant PlaylistModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_data.size())
        return QVariant();

    if(role == TrackName) {
        return m_data[index.row()].first;
    }
    if(role == TrackDuration) {
        return m_data[index.row()].second;
    }

    return QVariant();
    // if (index.isValid() && role == Qt::DisplayRole) {
    //     int row = index.row();
    //     return m_data[row];
    // }
}

QHash<int, QByteArray> PlaylistModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TrackName] = "name";
    roles[TrackDuration] = "duration";
    return roles;
}

void PlaylistModel::addTrack(QString newTrack, quint64 duration)
{
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
    m_data.append(QPair<QString, quint64>(newTrack, duration));
    endInsertRows();
}
