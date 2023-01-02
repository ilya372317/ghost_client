//
// Created by Отинов Илья on 26.12.2022.
//

#include "TextEditor.h"

TextEditor::TextEditor(QWidget *parent)
        : QWidget(parent),
        backButton(new QPushButton("back")),
        clearButton(new QPushButton("clear")),
        textEdit(new QTextEdit),
        layout(new QVBoxLayout),
        buttonLayout(new QHBoxLayout) {
    connect(backButton, &QPushButton::clicked, this, &TextEditor::returnToParentWidget);
    connect(clearButton, &QPushButton::clicked, this, &TextEditor::clearTextArea);
    layout->addWidget(textEdit);
    buttonLayout->addWidget(clearButton);
    buttonLayout->addWidget(backButton);
    layout->addLayout(buttonLayout);
    this->setLayout(layout);

    connect(this, SIGNAL(changeWidget(QWidget*)), parentWidget(), SLOT(replaceCentralWidget(QWidget*)));
}

TextEditor::~TextEditor() {
    delete backButton;
    delete clearButton;
    delete textEdit;
    delete buttonLayout;
    delete layout;
}

void TextEditor::clearTextArea() {
    textEdit->clear();
    textEdit->setText("what`s up?");
}

void TextEditor::returnToParentWidget() {
    emit changeWidget((QWidget*)new QPushButton("test"));
}
