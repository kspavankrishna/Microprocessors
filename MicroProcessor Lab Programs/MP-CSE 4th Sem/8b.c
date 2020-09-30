#include <stdio.h> 
#include "NUC1xx.h" 
#include "Driver\DrvGPIO.h" 
#include "Driver\DrvUART.h" 
#include "Driver\DrvSYS.h" 
 
void EINT1Callback(void)  
{ DrvGPIO_ClrBit(E_GPB,11); 
DrvSYS_Delay(1000); 
DrvGPIO_SetBit(E_GPB,11); 
DrvSYS_Delay(1000); 
}  
int main(void) 
{ UNLOCKREG(); 
DrvSYS_Open(48000000); 
LOCKREG();  
DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT); 
DrvGPIO_Open(E_GPB, 15, E_IO_INPUT); 
DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, EINT1Callback); 
while(1) { } 
}
