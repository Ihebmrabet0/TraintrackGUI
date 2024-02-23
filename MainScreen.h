#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QGridLayout>
#include <QTimeEdit>
#include <QFrame>
#include <QPalette>
#include <QIcon>
#include <QObject>
#include <QGraphicsDropShadowEffect>
#include <QMovie>


#include "Logger.h"

#include "TrainWidget.h"
#include "HelpWindow.h"
#include "LightSettingsWindow.h"

class MainScreen : public QMainWindow {
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = nullptr);
    void updateConnectionStatus(bool isConnected);

signals:

    

public slots:


private:
    QLabel *statusLabel;

    Connector *API_Connector; 
};

#endif // MAINSCREEN_H
