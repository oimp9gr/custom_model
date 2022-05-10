#include "widget.h"
#include "stringlistmodel.h"

#include <QApplication>
#include <QStringList>
#include <QTableView>
#include <QHeaderView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList lst;
    lst << "Maxime" << "Yan" << "Magnus" << "Fabiano" << "Ding" << "Anish";

    StringListModel * model = new StringListModel(lst);

    QTableView * tableView = new QTableView;
    tableView->resize(150, 210);

    tableView->setModel(model);
    tableView->setSortingEnabled(true);
    tableView->horizontalHeader()->setSortIndicatorShown(true);
    tableView->show();

    return a.exec();
}
