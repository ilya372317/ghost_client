//
// Created by Отинов Илья on 02.01.2023.
//

#ifndef GHOST_CLIENT_GHOSTCLIENT_H
#define GHOST_CLIENT_GHOSTCLIENT_H
#include "../WebClientInterface.h"
#include "QList"

class GhostClient : public WebClientInterface{
public:
    GhostClient();
    ~GhostClient();

    PostModel *getPostsList() override;
    bool editTitle(QString newTitle) override;
    bool editContent(QString newContent) override;
    bool editField(QString field, QString data) override;
    bool deletePost(Post) override;
};


#endif //GHOST_CLIENT_GHOSTCLIENT_H
