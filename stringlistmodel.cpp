#include "stringlistmodel.h"

StringListModel::StringListModel(const QStringList & strings, QObject *parent)
    : QAbstractListModel{parent}, stringList{strings}
{
}

int StringListModel::rowCount(const QModelIndex &parent) const
{
    return stringList.size();
}

QVariant StringListModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row() < stringList.size() && role == Qt::DisplayRole) {
        return stringList.at(index.row());
    }
    return QVariant();
}

void StringListModel::sort(int column, Qt::SortOrder order)
{
    if (order == Qt::AscendingOrder) {
        stringList.sort(Qt::CaseInsensitive);
    } else {
        std::sort(stringList.begin(), stringList.end(),
                  [](const QString& lhs, const QString& rhs){
            return lhs.toLower() > rhs.toLower();
        });
    }

    emit dataChanged(index(0), index(stringList.size()));
}
