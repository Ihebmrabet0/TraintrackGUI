#ifndef CONNECTOR_H
#define CONNECTOR_H

#define WITHOUT_API

#ifndef WITHOUT_API
#include "src_winterface/winterface-api.h"

class Connector
{
    public:
        Connector(){};

        bool connect();
        bool connectDummy();

        WINTP getTrainY_IP();
        WINTP getTrainB_IP();
        WINTP getMainBoard_IP();
 
    private:
        bool connection_successful = false;
        WINTP wintp_Zug_Y, wintp_Zug_B;
        WINTP mainboard;

};
#else
#include <iostream>

class Connector
{
    int a;
};

#endif


#endif