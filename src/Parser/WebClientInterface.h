//
// Created by Отинов Илья on 02.01.2023.
//

#ifndef GHOST_CLIENT_WEBCLIENTINTERFACE_H
#define GHOST_CLIENT_WEBCLIENTINTERFACE_H
#include "../Model/Post/PostModel.h"
#include "QList"

class WebClientInterface {
public:
    virtual ~WebClientInterface() = default;
    virtual PostModel* getPostsList() = 0;
    virtual bool editTitle(QString newTitle) = 0;
    virtual bool editContent(QString newContent) = 0;
    virtual bool editField(QString field, QString data) = 0;
    virtual bool deletePost(Post) = 0;
};


#endif //GHOST_CLIENT_WEBCLIENTINTERFACE_H
