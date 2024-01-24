#include "LedController.h"
#include <fstream>
#include <string>

#ifdef WITHOUT_API
#include <iostream>
#endif

LedController::LedController(LightSettingsWindow * window, Connector *connector) 
: GUI(window), API(connector)
{
        GUI->setController(this);
        connect(this, SIGNAL(updateNames(std::vector<QString>&)), GUI, SLOT(setLed(updateBtnNames(std::vector<QString>&))));
            
        //Set to default
        for(unsigned int counter = 1; counter <= NUMBER_OF_LEDS; counter++)
        {
                btn_name_to_index[QString::number(counter)] = counter-1;

                /// Btn_name -> index
                /// "1"  -> 0
                /// "2"  -> 1
                /// "3"  -> 2
                /// "4"  -> 3
                /// "5"  -> 4
                /// "6"  -> 5
                /// ...

        }



        loadNameData(PATH_LED_NAMES);

        for(int i = 0; i < NUMBER_OF_LEDS; i++)
        {
            led_matrix.push_back(false);
        }
}

bool LedController::loadNameData(const char * path)
{
    std::fstream namefile;

    namefile.open(path, std::ios::in);

    if(namefile.is_open())
    {
        std::string line;
        unsigned int counter = 1;
        std::vector<QString> namelist; namelist.reserve(30);

        while(std::getline(namefile, line))
        {
            btn_name_to_index[QString(line.c_str())] = counter;
            namelist.push_back(QString(line.c_str()));
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

    namefile.open(path, std::ios::out);

    if(namefile.is_open())
    {
        
        for(auto it = btn_name_to_index.begin(); it!=btn_name_to_index.end(); it++)
        {
            namefile << (*it).first.toStdString()<<"\n";
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
    std::cout<<"Update LED"<<std::endl;
    #else
    mainboard_setLed(API->getMainBoard_IP(), position, led_matrix[position]);
    mainboard_writeLed(API->getMainBoard_IP());
    #endif    
}

void LedController::resetLEDs()
{
    #ifdef WITHOUT_API
    std::cout<<"resetting LEDs"<<std::endl;
    #else

    for(int i = 0; i < NUMBER_OF_LEDS; i++)
    {
        mainboard_setLed(API->getMainBoard_IP(), i, false);
    }

    mainboard_writeLed(API->getMainBoard_IP());

    #endif
}