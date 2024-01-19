#include "TrainWidget.h"
#include <QGridLayout>
#include <QIcon>

TrainWidget::TrainWidget(int trainNumber, QWidget *parent) : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout(this);

    QString buttonStyle = "QPushButton { background-color: #4A90E2; color: white; border: none; border-radius: 5px; padding: 10px; font-size: 16px; }";
    QString labelStyle = "QLabel { color: #333; font: 16px 'Arial'; }";

    trainLabel = new QLabel(QString("Train %1").arg(trainNumber + 1));
    trainLabel->setStyleSheet(labelStyle);
    layout->addWidget(trainLabel, 0, 0);

    speedSlider = new QSlider(Qt::Horizontal);
    speedSlider->setRange(0, 100);
    layout->addWidget(speedSlider, 1, 0);

    speedLabel = new QLabel("Speed");
    speedLabel->setStyleSheet(labelStyle);
    layout->addWidget(speedLabel, 2, 0);

    startButton = new QPushButton("START");
    startButton->setStyleSheet(buttonStyle);
    QIcon playIcon(":/icons/play_icon.png");
    startButton->setIcon(playIcon);
    startButton->setIconSize(QSize(16, 16));
    layout->addWidget(startButton, 3, 0);
}
