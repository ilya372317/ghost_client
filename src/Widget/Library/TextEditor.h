//
// Created by Отинов Илья on 26.12.2022.
//

#ifndef GHOST_CLIENT_TEXTEDITOR_H
#define GHOST_CLIENT_TEXTEDITOR_H
#include "QTextEdit"
#include "QPushButton"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "../MainWindow.h"

class TextEditor : public QWidget{
    Q_OBJECT
public:
    explicit TextEditor(QWidget* parent = nullptr);
    ~TextEditor() override;

public slots:
    void clearTextArea();
    void returnToParentWidget();
signals:
    void changeWidget(QWidget*);
private:
    QPushButton* backButton;
    QPushButton* clearButton;
    QTextEdit* textEdit;
    QVBoxLayout* layout;
    QHBoxLayout* buttonLayout;
};


#endif //GHOST_CLIENT_TEXTEDITOR_H
