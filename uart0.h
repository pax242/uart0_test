// UART.h
// U0Rx PA0
// U0Tx PA1

#define CR   0x0D
#define LF   0x0A

void UART0_init(void);

char UART0_InChar(void);

void UART0_OutChar(char data);

void UART0_OutString(char *pt);
