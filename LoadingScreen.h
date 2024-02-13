#ifndef LOADINGSCREEN_H
#define LOADINGSCREEN_H

#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <QTimer>
#include <QVBoxLayout>
#include <QScreen>
#include <QGuiApplication>

class LoadingScreen : public QWidget {
    Q_OBJECT

public:
    explicit LoadingScreen(QWidget *parent = nullptr);

signals:
    void connectionComplete();

private slots:
    void onConnectionSimulated();

private:
    QLabel *animationLabel;
    QMovie *loadingMovie;
    QTimer *connectionTimer;
};

#endif // LOADINGSCREEN_H
