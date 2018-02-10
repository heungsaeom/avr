/*#########################################################

Demo program for testing the IR Remote control libraries.
-----------------------------------------------------------

Copyright Avinash Gupta 2008 avinash@eXtremeElectronics.co.in

Web: www.eXtremeElectronics.co.in

Please give credit or reference to www.eXtremeElectronics.co.in
if you use this in your projects and find it useful.


##########################################################*/
#include <avr/io.h>

#include "remote.h"
#include "lcd.h"

void main()
{
	uint8_t cmd=0;


	RemoteInit();
	DDRC=0xFF;

	LCDInit(LS_BLINK);

	LCDClear();

	LCDWriteString("IR RemoteDecoder");
	LCDWriteStringXY(0,1,"Key Code:");

	while(1)
	{
		cmd=GetRemoteCmd(1);
		if(cmd == 16724175)
		{
			PORTC=0xFF;
		}
			if(cmd == 16718055)
		{
			PORTC=0x00;
		}
		_delay_ms(500);
	//	LCDWriteIntXY(10,1,cmd,3);
	}
}
