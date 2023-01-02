//
// Created by Отинов Илья on 31.12.2022.
//

#ifndef GHOST_CLIENT_CHILDWIDGETINTERFACE_H
#define GHOST_CLIENT_CHILDWIDGETINTERFACE_H

#include "QObject"

class ChildWidgetInterface {
public slots:
    virtual void returnToParentWidget() = 0;
signals:
    virtual void changeWidget(QWidget *) = 0;
};


#endif //GHOST_CLIENT_CHILDWIDGETINTERFACE_H
