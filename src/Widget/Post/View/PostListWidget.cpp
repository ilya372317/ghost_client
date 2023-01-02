//
// Created by Отинов Илья on 27.12.2022.
//

#include "PostListWidget.h"

PostListWidget::PostListWidget(QWidget *parent)
        : QWidget(parent) {
    client = new GhostClient;
    model = client->getPostsList();
    mainLayout = new QVBoxLayout;
    view = new QTableView;
    editButton = new QPushButton("edit post");
    setupGui();
    connect(editButton, &QPushButton::clicked, this, &PostListWidget::returnToParentWidget);
    connect(this, SIGNAL(changeWidget(QWidget * )), parentWidget(), SLOT(replaceCentralWidget(QWidget * )));
}

PostListWidget::~PostListWidget() {
    delete view;
    delete editButton;
    delete mainLayout;
    delete model;
    delete client;
}

void PostListWidget::setupGui() {
    view->setModel(model);
    mainLayout->addWidget(editButton);
    mainLayout->addWidget(view);
    setLayout(mainLayout);
}

void PostListWidget::returnToParentWidget() {
    QItemSelectionModel *selectionModel = view->selectionModel();
    QModelIndexList selectedRows = selectionModel->selectedRows();

    if (selectedRows.empty()) {
        return;
    }
    QModelIndex selectedIndex = selectedRows.first();

    if (!selectedIndex.isValid()) {
        return;
    }

    auto *editWidget = new PostEditWindow(model, selectedIndex.row(), parentWidget());
    emit changeWidget(editWidget);
}