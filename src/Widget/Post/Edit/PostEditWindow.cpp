//
// Created by Отинов Илья on 26.12.2022.
//

#include "PostEditWindow.h"

PostEditWindow::PostEditWindow(PostModel *model, int r, QWidget *parent)
        : QWidget(parent), postModel(model), row(r) {
    buttonLayout = new QHBoxLayout;
    deleteButton = new QPushButton("Delete post");
    editButton = new QPushButton("Save changes");
    closeButton = new QPushButton("Close");
    QModelIndex titleIndex = postModel->index(row, PostModel::TITLE_COLUMN);
    QModelIndex contentIndex = postModel->index(row, PostModel::CONTENT_COLUMN);
    titleBox = new QLineEdit(postModel->data(titleIndex, Qt::DisplayRole | Qt::EditRole).toString());
    contentEdit = new QTextEdit(postModel->data(contentIndex, Qt::DisplayRole | Qt::EditRole).toString());
    this->setupWidget();
}

void PostEditWindow::setupWidget() {

    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(closeButton);

    auto* mainLayout = new QVBoxLayout;

    connect(closeButton, &QPushButton::clicked, this, &PostEditWindow::returnToParentWidget);
    connect(this, SIGNAL(changeWidget(QWidget*)), parentWidget(), SLOT(replaceCentralWidget(QWidget*)));
    mainLayout->addWidget(titleBox);
    mainLayout->addWidget(contentEdit);
    mainLayout->addLayout(buttonLayout);

    this->setLayout(mainLayout);
}

void PostEditWindow::returnToParentWidget() {
    auto* postListWidget = new PostListWidget(parentWidget());
    emit changeWidget(postListWidget);
}


