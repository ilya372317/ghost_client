//
// Created by Отинов Илья on 22.12.2022.
//

#include "MainWindow.h"

MainWindow::MainWindow() : centralWidget(new PostListWidget(this)), layout(new QVBoxLayout) {
    layout->addWidget(centralWidget);
    this->setLayout(layout);
}

void MainWindow::replaceCentralWidget(QWidget* widget) {
    this->layout->replaceWidget(centralWidget, widget);
    delete centralWidget;
    this->centralWidget = widget;
}
