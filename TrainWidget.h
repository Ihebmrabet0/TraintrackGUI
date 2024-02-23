#ifndef TRAINWIDGET_H
#define TRAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSlider>

#include "TrainController.h"

class TrainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TrainWidget(int trainNumber, QWidget *parent = nullptr);

signals:
    void changeSpeed(TrainID id, int speed); // speed 0-100
    void ToggleStart(TrainID id);
    

private:
    QPushButton *startButton;
    QLabel *speedLabel;
    QSlider *speedSlider;
    QLabel *trainLabel;

    TrainController *controll;
};

#endif // TRAINWIDGET_H
