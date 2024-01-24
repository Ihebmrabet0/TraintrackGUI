#ifndef LIGHTSETTINGSWINDOW_H
#define LIGHTSETTINGSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QList>


#include "Constants.h"
#include "LedController.h"

class LedController;

class LightSettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LightSettingsWindow(QWidget *parent = nullptr);


    void setController(LedController * controller);

signals:

    void setLed(QString led_name);
    void renameLed(QString old_name,QString new_name);

public slots:
    void onLightButtonClicked();
    void onEditButtonClicked();

    void updateBtnNames(std::vector<QString>&names);

private:
    QLineEdit *editNameField;
    QLabel *selectedLightLabel;
    QString lastSelectedLight;
    QPushButton* selectedLightButton = nullptr;
    QString buttonStyle = "QPushButton { background-color: #333; color: white; border: none; border-radius: 5px; padding: 10px; font-family: Inter; font-size: 30px; font-style: normal; font-weight: 600;}";

    QList<QPushButton*> led_buttons;

    LedController * controller;
};

#endif // LIGHTSETTINGSWINDOW_H
