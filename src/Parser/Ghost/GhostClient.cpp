//
// Created by Отинов Илья on 02.01.2023.
//

#include "GhostClient.h"

GhostClient::GhostClient() = default;

GhostClient::~GhostClient() = default;

PostModel* GhostClient::getPostsList() {
    auto* postList = new QList<Post>;

    //TODO: replace with query
    for (int i = 0; i < 100; i++) {
        Post post;
        post.id = i;
        post.title = QString("Post number#").append(QString::number(i));
        post.content = QString("Content of post #").append(QString::number(i));
        postList->push_back(post);
    }

    auto* postModel = new PostModel(postList);

    return postModel;
}

bool GhostClient::editTitle(QString newTitle) {
    return true;
}

bool GhostClient::editContent(QString newContent) {
    return true;
}

bool GhostClient::editField(QString field, QString data) {
    return true;
}

bool GhostClient::deletePost(Post) {
    return true;
}