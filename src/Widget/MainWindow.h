//
// Created by Отинов Илья on 22.12.2022.
//

#ifndef GHOST_CLIENT_MAINWINDOW_H
#define GHOST_CLIENT_MAINWINDOW_H
#include "QWidget"
#include "QLabel"
#include "QVBoxLayout"
#include "QTableView"
#include "../Model/Post/PostModel.h"
#include "QPushButton"
#include "Post/View/PostListWidget.h"
#include "Post/Edit/PostEditWindow.h"

class MainWindow : public QWidget {
    Q_OBJECT
public:
    MainWindow();
public slots:
    void replaceCentralWidget(QWidget* widget);
private:
    QWidget* centralWidget;
    QVBoxLayout* layout;
};


#endif //GHOST_CLIENT_MAINWINDOW_H
