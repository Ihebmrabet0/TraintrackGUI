#include "LedController.h"
#include <fstream>
#include <string>

#include "Logger.h"

#ifdef WITHOUT_API
#include <iostream>
#endif

LedController::LedController(LightSettingsWindow * window, Connector *connector) 
: GUI(window), API(connector)
{
        GUI->setController(this);
        connect(this, SIGNAL(updateNames(QVector<QString>)), GUI, SLOT(updateBtnNames(QVector<QString>)));


        if(!loadNameData(PATH_LED_NAMES))
        {
            //Set to default
            for(unsigned int counter = 0; counter < NUMBER_OF_LEDS; counter++)
            {
                    btn_name_to_index[QString::number(counter+1)] = counter;

                    /// Btn_name -> index
                    /// "1"  -> 0
                    /// "2"  -> 1
                    /// "3"  -> 2
                    /// "4"  -> 3
                    /// "5"  -> 4
                    /// "6"  -> 5
                    /// ...

            }
        }



        for(int i = 0; i < NUMBER_OF_LEDS; i++)
        {
            led_matrix.push_back(false);
        }
}

bool LedController::loadNameData(const char * path)
{
    std::fstream namefile;

    namefile.open(path, std::ios::in);
    QString tmp;
    QTextStream(&tmp) << "namefile.is_open(): "<<(namefile.is_open() ? "True" : "False");
    Logger::N() -> print(tmp, tr(__FILE_NAME__),__LINE__);
    if(namefile.is_open())
    {
        std::string line;
        unsigned int counter = 0;
        QVector<QString> namelist(NUMBER_OF_LEDS+2); namelist.resize(NUMBER_OF_LEDS*2);

        while(std::getline(namefile, line))
        {
            btn_name_to_index[QString(line.c_str())] = counter;
            namelist[counter] = QString(line.c_str());
            counter++;
        }


        ///////////////////////
        ///SIGNAL TO LED GUI///
        ///////////////////////
        // to change button names

        emit updateNames(namelist); 



        namefile.close();
    }else{
        return false;
    }

    return true;
}

void LedController::saveNameData(const char * path)
{
    
    std::fstream namefile;

    namefile.open(path, std::ios::out|std::ios::trunc);

    std::vector<std::string> tmp(NUMBER_OF_LEDS+2);
    tmp.reserve(NUMBER_OF_LEDS*2);

    for(auto it = btn_name_to_index.begin(); it!=btn_name_to_index.end(); it++)
    {
            QString str;
            QTextStream(&str) << (*it).first << " : "<<(*it).second;
            DEBUG(str);
            tmp[(*it).second] = (*it).first.toStdString();
    }

    if(namefile.is_open())
    {
        
        for(int i = 0; i < NUMBER_OF_LEDS; i++)
        {
            namefile << tmp[i]<<"\n";
        }


        namefile.flush();
        namefile.close();
    }
}

void LedController::setLed(QString led_name)
{
    
    unsigned int index = btn_name_to_index[led_name];
    led_matrix[index] = !led_matrix[index];
   
    updateLED(index);    
}

void LedController::setLedName(QString old_name, QString new_name)
{
    unsigned int tmp = btn_name_to_index[old_name];
    btn_name_to_index[new_name] = tmp;
    btn_name_to_index.erase(old_name);
}

void LedController::updateLED(unsigned int position)
{
    #ifdef WITHOUT_API
    Logger::N() -> print(tr("update LED"), tr(__FILE_NAME__), __LINE__);
    #else
    mainboard_setLed(API->getMainBoard_IP(), position, led_matrix[position]);
    mainboard_writeLed(API->getMainBoard_IP());
    #endif    
}

void LedController::resetLEDs()
{
    #ifdef WITHOUT_API
    Logger::N() -> print(tr("resetting LEDs"), tr(__FILE_NAME__), __LINE__);
    #else

    for(int i = 0; i < NUMBER_OF_LEDS; i++)
    {
        mainboard_setLed(API->getMainBoard_IP(), i, false);
    }

    mainboard_writeLed(API->getMainBoard_IP());

    #endif
}

void LedController::onClose()
{
    saveNameData(PATH_LED_NAMES);
    Logger::N()->print(tr("LED Names saved"),tr(__FILE_NAME__),__LINE__);
}