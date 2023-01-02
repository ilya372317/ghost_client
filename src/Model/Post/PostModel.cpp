//
// Created by Отинов Илья on 22.12.2022.
//

#include "PostModel.h"

PostModel::~PostModel() {
    delete postList;
}

int PostModel::rowCount(const QModelIndex &parent) const {
    return postList->count();
}

int PostModel::columnCount(const QModelIndex &parent) const {
    return POST_FILED_COUNT;
}

QVariant PostModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return {};
    }

    if (index.row() > postList->count()) {
        return {};
    }
    if (index.column() > PostModel::POST_FILED_COUNT) {
        return {};
    }

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        switch (index.column()) {
            case PostModel::TITLE_COLUMN:
                return postList->at(index.row()).title;
            case PostModel::CONTENT_COLUMN:
                return postList->at(index.row()).content;
            default:
                return {};
        }
    }

    return {};
}

QVariant PostModel::headerData(int section, Qt::Orientation orientation, int role) {
    if (role != Qt::DisplayRole) {
        return {};
    }

    if (orientation == Qt::Horizontal) {
        return QStringLiteral("Post #%1").arg(section);
    }

    if (orientation == Qt::Vertical) {
        switch (section) {
            case TITLE_COLUMN:
                return QString("Title");
            case CONTENT_COLUMN:
                return QString("Content");
            default:
                return QString("Unknown column");
        }
    }

    return {};
}

Qt::ItemFlags PostModel::flags(const QModelIndex &index) const {
    if (!index.isValid()) {
        return Qt::ItemIsEnabled;
    }

    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

bool PostModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (index.isValid() && role == Qt::EditRole) {
        auto tempPost = postList->at(index.row());

        switch (index.column()) {
            case TITLE_COLUMN:
                tempPost.title = value.toString();
                postList->replace(index.row(), tempPost);
                break;
            case CONTENT_COLUMN:
                tempPost.content = value.toString();
                postList->replace(index.row(), tempPost);
                break;
        }

        return true;
    }

    return false;
}

bool PostModel::insertRows(int position, int rows, const QModelIndex &index) {
    beginInsertRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; row++) {
        postList->insert(row, *(new Post));
    }
    endInsertRows();

    return true;
}

bool PostModel::removeRows(int position, int rows, const QModelIndex &index) {
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; row++) {
        postList->removeAt(row);
    }
    endRemoveRows();

    return true;
}