//
// Created by Отинов Илья on 27.12.2022.
//

#ifndef GHOST_CLIENT_POSTLISTWIDGET_H
#define GHOST_CLIENT_POSTLISTWIDGET_H
#include "../../ChildWidgetInterface.h"
#include "../../../Model/Post/PostModel.h"
#include "../../../Parser/Ghost/GhostClient.h"
#include "../Edit/PostEditWindow.h"
#include "QWidget"
#include "QVBoxLayout"
#include "QTableView"
#include "QPushButton"

class PostListWidget : public QWidget, ChildWidgetInterface {
    Q_OBJECT
public slots:
    void returnToParentWidget() override;
signals:
    void changeWidget(QWidget *) override;

public:
    explicit PostListWidget(QWidget* parent);
    ~PostListWidget() override;
private:
    void setupGui();

    WebClientInterface* client;
    PostModel *model;
    QVBoxLayout *mainLayout;
    QPushButton *editButton;
    QTableView *view;
};


#endif //GHOST_CLIENT_POSTLISTWIDGET_H
