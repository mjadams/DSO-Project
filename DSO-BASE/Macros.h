/*************************************************************************
Title:    Usefull Macros header File 
Author:   David Jahshan, Iridec Systems Pty Ltd dej@iridec.com.au 
Software: AVR-GCC 
Hardware: ATMEGA128 @ 16Mhz 

DESCRIPTION:
	Some usefull macros for turnig signals on and off

*************************************************************************/

#include <avr/io.h>

#define byte unsigned char 

/*ON OFF*/
#define ON 0xFF
#define OFF 0x00
#define HIGH 0xFF
#define LOW 0x00
#define IN 0x00
#define OUT 0xFF
#define ALL 0xFF
#define LEFT 0xFF
#define RIGHT 0x00
#define TRUE 1
#define FALSE 0
#define INACTIVE 0
#define ACTIVE 1
#define CLOCKWISE 0
#define ANTICLOCKWISE 1
#define DISABLED 0
#define ENABLED 1
#define UP 1
#define DOWN 0
#define GND 0
#define VCC 1

/*SET and GET MACRO*/
#define SET(PORT,MASK,VALUE) (PORT = ((MASK & VALUE) | (PORT & ~MASK)))
#define GET(PORT,MASK) (PORT & MASK)


