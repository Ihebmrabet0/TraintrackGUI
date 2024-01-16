
/*
 *	name:   sp.h
 *	prefix: sp_
 *
 *	this modules implements the very simple on/off port
 *
 *	'API':
 *	------
 *	sp_state() : the interrupt handler
 *	sp_config(): configuring the port, i.e., address etc.
 *	sp_on()	   : setting the output port to 1
 *	sp_off()   : setting the output port to 0
 *
 */


#ifndef __INCLUDE_GUARD_SP__
#define __INCLUDE_GUARD_SP__

typedef struct {
	  char    state;	// current port state
	  char    new_state;	// new port state by external requests
	  int     port_id;	// the actual port interfac
	} SP, *SPP;

void sp_state    ( SPP sp );
int  sp_config	( SPP sp, int port_id );
void sp_on       ( SPP sp );
void sp_off      ( SPP sp );

#endif
