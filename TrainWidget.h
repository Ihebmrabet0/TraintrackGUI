#ifndef TRAINWIDGET_H
#define TRAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSlider>


class TrainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TrainWidget(int trainNumber, QWidget *parent = nullptr);

public slots:


private:
    QPushButton *startButton;
    QLabel *speedLabel;
    QSlider *speedSlider;
    QLabel *trainLabel;

};

#endif // TRAINWIDGET_H
