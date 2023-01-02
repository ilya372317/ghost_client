//
// Created by Отинов Илья on 26.12.2022.
//

#ifndef GHOST_CLIENT_POSTEDITWINDOW_H
#define GHOST_CLIENT_POSTEDITWINDOW_H
#include "QWidget"
#include "../../../Model/Post/PostModel.h"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QPushButton"
#include "QLineEdit"
#include "QTextEdit"
#include "../../MainWindow.h"

class PostEditWindow : public QWidget, public ChildWidgetInterface {
    Q_OBJECT
public:
    explicit PostEditWindow(PostModel *model, int r, QWidget *parent = nullptr);

signals:
    void changeWidget(QWidget *) override;

public slots:
    void returnToParentWidget() override;
private:
    void setupWidget();
    PostModel* postModel;
    int row;
    QHBoxLayout* buttonLayout;
    QPushButton* deleteButton;
    QPushButton* editButton;
    QPushButton* closeButton;
    QLineEdit* titleBox;
    QTextEdit* contentEdit;
};


#endif //GHOST_CLIENT_POSTEDITWINDOW_H
