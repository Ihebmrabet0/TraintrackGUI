#include "winterface.h"
#include <arpa/inet.h> // inet_addr()
#include <netinet/in.h> //structure for storing address information
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>

#include <errno.h>
#include <string.h>


WINTP connection_init(const char *TRAIN, int PORT );
int train_setSpeed( WINTP train, int speed );
int train_setDirection( WINTP train, int speed );
int mainboard_setWeiche( WINTP mainboard, int weiche_id, int val );
int mainboard_setLed( WINTP mainboard, int led_id, int val );
int mainboard_writeLed( WINTP mainboard );


