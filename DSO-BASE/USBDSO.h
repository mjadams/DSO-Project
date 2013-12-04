/*************************************************************************
Title:    USB DSO Header
Author:   David Jahshan, jahshan@unimelb.edu.au 
Software: AVR-GCC 
Hardware: ATMEGA16 @ 10Mhz 

DESCRIPTION:
	Header file for USB DSO assignment for ESD

*************************************************************************/

#define BAUDRATE 19200

#define DELAY_CONST 100

#define ADC_DATA(STATE) PORTA=STATE
#define ADC_DATA_DDR(DIR) DDRA=DIR
#define ADC_DATA_IN PINA

#define RAM_READ(STATE) SET(PORTB,_BV(PB0),STATE)
#define RAM_READ_DDR(DIR) SET(DDRB,_BV(PB0),DIR)
#define RAM_READ_IN GET(PINB,_BV(PB0))	

#define ENABLE(STATE) SET(PORTB,_BV(PB1),STATE)
#define ENABLE_DDR(DIR) SET(DDRB,_BV(PB1),DIR)
#define ENABLE_IN GET(PINB,_BV(PB1))	

#define LED1(STATE) SET(PORTB,_BV(PB2),~STATE) // Optional LED GPIO
#define LED1_DDR(DIR) SET(DDRB,_BV(PB2),DIR)
#define LED1_IN GET(PINB,_BV(PB2))	

#define LED2(STATE) SET(PORTB,_BV(PB3),~STATE) // Optional LED GPIO
#define LED2_DDR(DIR) SET(DDRB,_BV(PB3),DIR)
#define LED2_IN GET(PINB,_BV(PB3))	

#define LED3(STATE) SET(PORTB,_BV(PB4),~STATE) // Optional LED GPIO
#define LED3_DDR(DIR) SET(DDRB,_BV(PB4),DIR)
#define LED3_IN GET(PINB,_BV(PB4))	

#define LED4(STATE) SET(PORTD,_BV(PD3),~STATE) // Optional LED GPIO
#define LED4_DDR(DIR) SET(DDRD,_BV(PD3),DIR)
#define LED4_IN GET(PIND,_BV(PD3))	

#define SDA(STATE) SET(PORTB,_BV(PB5),STATE)
#define SDA_DDR(DIR) SET(DDRB,_BV(PB5),DIR)
#define SDA_IN GET(PINB,_BV(PB5))	

#define SCS(STATE) SET(PORTB,_BV(PB6),STATE)
#define SCS_DDR(DIR) SET(DDRB,_BV(PB6),DIR)
#define SCS_IN GET(PINB,_BV(PB6))	

#define SCK(STATE) SET(PORTB,_BV(PB7),STATE)
#define SCK_DDR(DIR) SET(DDRB,_BV(PB7),DIR)
#define SCK_IN GET(PINB,_BV(PB7))	

#define PLL_S0(STATE) SET(PORTD,_BV(PD7),STATE) // PLL control line setup S0
#define PLL_S0_DDR(DIR) SET(DDRD,_BV(PD7),DIR)
#define PLL_S0_IN GET(PIND,_BV(PD7))	

#define PLL_S1(STATE) SET(PORTD,_BV(PD6),STATE) // PLL control line setup S1
#define PLL_S1_DDR(DIR) SET(DDRD,_BV(PD6),DIR)
#define PLL_S1_IN GET(PIND,_BV(PD6))	

#define IN_CLK(STATE) SET(PORTD,_BV(PD5),STATE) // PLL Clock output setup
#define IN_CLK_DDR(DIR) SET(DDRD,_BV(PD5),DIR)
#define IN_CLK_IN GET(PIND,_BV(PD5))	

#define SLOW_CLK(STATE) SET(PORTD,_BV(PD4),STATE) // Databuffer read clocking signal
#define SLOW_CLK_DDR(DIR) SET(DDRD,_BV(PD4),DIR)
#define SLOW_CLK_IN GET(PIND,_BV(PD4))	

#define FILL_COMP(STATE) SET(PORTD,_BV(PD2),STATE)
#define FILL_COMP_DDR(DIR) SET(DDRD,_BV(PD2),DIR)
#define FILL_COMP_IN GET(PIND,_BV(PD2))	

#define RX(STATE) SET(PORTD,_BV(PD0),STATE)
#define RX_DDR(DIR) SET(DDRD,_BV(PD0),DIR)
#define RX_IN GET(PIND,_BV(PD0))	

#define TX(STATE) SET(PORTD,_BV(PD1),STATE)
#define TX_DDR(DIR) SET(DDRD,_BV(PD1),DIR)
#define TX_IN GET(PIND,_BV(PD1))	

#define SERIAL_BAUD_RATE(baud_rate) ((F_CPU)/((baud_rate)*16l)-1)
#define SERIAL_SET_BAUD_RATE1(baud_rate) UBRRH=(byte)(SERIAL_BAUD_RATE(baud_rate)>>8)
#define SERIAL_SET_BAUD_RATE2(baud_rate) UBRRL=(byte)(SERIAL_BAUD_RATE(baud_rate))
#define UART_DATA_REGISTER UDR
#define UART_CONFIG1 SET(UCSRB,(_BV(RXEN)|_BV(TXEN)),ON)
#define UART_CONFIG2 SET(UCSRC,(_BV(URSEL)|_BV(UCSZ1)|_BV(UCSZ0)),ON)
#define TX_EMPTY (GET(UCSRA,_BV(TXC)))
#define TX_CLEAR SET(UCSRA,_BV(TXC),ON)
#define RX_FULL GET(UCSRA,_BV(RXC))

#define TIMER_SETUP SET(TCCR1A,_BV(COM1A0),ON); SET(TCCR1B,(_BV(WGM12)|_BV(CS10)),ON)
#define CLOCK_DIVIDER(VALUE) OCR1A=VALUE;

#define WAIT_FOR_RX while(!RX_FULL)
#define RX_BYTE UART_DATA_REGISTER 
#define ENABLE_TRIGGER ENABLE(HIGH);ENABLE(LOW)
#define TX_BYTE UART_DATA_REGISTER
#define WAIT_FOR_TX while(!TX_EMPTY)
#define CAPTURE_COMPLETE FILL_COMP_IN
#define CHANNEL_1_SAMPLE ADC_DATA_IN
#define CHANNEL_2_SAMPLE ADC_DATA_IN

#define PLL_S1_1 PLL_S1(HIGH); PLL_S1_DDR(OUT)
#define PLL_S1_0 PLL_S1(LOW); PLL_S1_DDR(OUT)
#define PLL_S1_M PLL_S1(LOW); PLL_S1_DDR(IN)
#define PLL_S0_1 PLL_S0(HIGH); PLL_S0_DDR(OUT)
#define PLL_S0_0 PLL_S0(LOW); PLL_S0_DDR(OUT)
#define PLL_S0_M PLL_S0(LOW); PLL_S0_DDR(IN)

#define PLLx4 PLL_S1_0;PLL_S0_0
#define PLLx16n3 PLL_S1_0;PLL_S0_M
#define PLLx5 PLL_S1_0;PLL_S0_1
#define PLLx5n2 PLL_S1_M;PLL_S0_0
#define PLLx2 PLL_S1_M;PLL_S0_M
#define PLLx10n3 PLL_S1_M;PLL_S0_1
#define PLLx6 PLL_S1_1;PLL_S0_0
#define PLLx3 PLL_S1_1;PLL_S0_M
#define PLLx8 PLL_S1_1;PLL_S0_1

