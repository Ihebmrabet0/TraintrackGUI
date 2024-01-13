#include "HelpWindow.h"

HelpWindow::HelpWindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QString labelTitelStyle = "QLabel { color: #0F172A; font-family : Inter; font-size : 44px; font-style : normal; font-weight : 800;}";
    QString labelStyle = "QLabel { color: gray; font-family : Inter; font-size : 40px; font-style : normal; font-weight : 600;}";

    QLabel *titleLabel = new QLabel("Help Center");
    titleLabel->setStyleSheet(labelTitelStyle);
    layout->addWidget(titleLabel);

    QLabel *helpTextLabel = new QLabel("If you need any help just \ncontact Iheb Mrabet 😅");
    helpTextLabel->setStyleSheet(labelStyle);
    layout->addWidget(helpTextLabel);
}
