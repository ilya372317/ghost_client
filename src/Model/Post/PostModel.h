//
// Created by Отинов Илья on 22.12.2022.
//

#ifndef GHOST_CLIENT_POSTMODEL_H
#define GHOST_CLIENT_POSTMODEL_H

#include <utility>

#include "QAbstractListModel"
#include "vector"

struct Post {
    unsigned long id;
    QString title;
    QString content;
};

class PostModel : public QAbstractListModel {
public:
    static const int POST_FILED_COUNT = 2;
    static const int ID_COLUMN = 0;
    static const int TITLE_COLUMN = 1;
    static const int CONTENT_COLUMN = 2;

    PostModel(QList<Post> *posts, QObject *parent = nullptr) :
            QAbstractListModel(parent),
            postList(posts) {};
    ~PostModel();
    [[nodiscard]] int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    [[nodiscard]] int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole);
    [[nodiscard]] Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
private:
    QList<Post> *postList;
};


#endif //GHOST_CLIENT_POSTMODEL_H
