#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H

#include <QAbstractListModel>

class StringListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit StringListModel(const QStringList & strings, QObject *parent = nullptr);


private:
    QStringList stringList;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    // QAbstractItemModel interface
public:
    void sort(int column, Qt::SortOrder order) override;
};

#endif // STRINGLISTMODEL_H
