#include "Connector.h"


bool Connector::connect()
{
    wintp_Zug_Y = connection_init(TRAIN_Y , TRAIN_PORT_Y );
	wintp_Zug_B = connection_init(TRAIN_B , TRAIN_PORT_B );
	mainboard = connection_init( MB, MB_PORT );

    if(!wintp_Zug_Y || !wintp_Zug_B || !mainboard)
    {
        connection_successful = false;
        return false;
    }
        connection_successful = true;
    return true;
}

bool Connector::connectDummy()
{
    wintp_Zug_Y = connection_init( DUMMY_Y, TRAIN_PORT_Y );
	wintp_Zug_B = connection_init( DUMMY_B, TRAIN_PORT_B );
	mainboard = connection_init( DUMMY_MB, MB_PORT );

    if(!wintp_Zug_Y || !wintp_Zug_B || !mainboard)
    {
        connection_successful = false;
        return false;
    }
        connection_successful = true;
    return true;
}

WINTP Connector::getTrainY_IP()
{
    return connection_successful ? wintp_Zug_Y : nullptr;
}

WINTP Connector::getTrainB_IP()
{
    return connection_successful ? wintp_Zug_B : nullptr;
}

WINTP Connector::getMainBoard_IP()
{
    return connection_successful ? mainboard : nullptr;
}