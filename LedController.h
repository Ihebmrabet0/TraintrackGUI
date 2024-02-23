#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include <map>
#include <QString>
#include <QObject>
#include <QWidget>
#include <QVector>
#include <vector>
#include "Connector.h"
#include "Constants.h"
#include "LightSettingsWindow.h"

class LightSettingsWindow;

class LedController : public QObject
{
    Q_OBJECT

    public:

        LedController(LightSettingsWindow* window, Connector * connector);


        bool loadNameData(const char* path);
        void saveNameData(const char* path);
    signals:
        void updateName(QString name,unsigned int position);
        void updateNames(QVector<QString> names);

    public slots:
        void setLed(QString led_name);
        void setLedName(QString old_name, QString new_name);
        void onClose(); 


    private:
        std::vector<bool> led_matrix;
        std::map<QString, unsigned int> btn_name_to_index;
        LightSettingsWindow * GUI;
        Connector * API;

        void updateLED(unsigned int position);

        void resetLEDs();

};

#endif