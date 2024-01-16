#ifndef TRAINCONTROLLER_H
#define TRAINCONTROLLER_H 

#include "src_winterface/winterface-api.h"

class TrainWidget;

enum DIRECTION {FORWARD, BACKWARD};

struct Train
{
    DIRECTION direction; // 0 - 1
    unsigned int Speed; // 0 - 4000
};

class TrainController
{
    public:

    TrainController(TrainWidget * widget_train);

    void setTrack(unsigned int track);
    void startTrain(int train);
    void setTrainSpeed(int train, int speed);

    private:

    //GUI-Component
    TrainWidget *view;


    //Zustand
    Train train1, train2;
    int current_track;
        
    Connector *connector;
};



#endif