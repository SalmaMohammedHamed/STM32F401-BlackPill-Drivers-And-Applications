#include "definition.h"
#include "RCC_interface.h"
#include "Special_Functions.h"
#include "GPIO_interface.h"
void delay(u16 time)
{
	  for(u16 i=0;i<time;i++)
	  {
		  for (u16 j=0;j<time;j++)
		  {
			  asm("NOP");
		  }
	  }
}


void main ()
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_AHB,0);
	RCC_voidEnableClock(RCC_AHB,1);
	GPIO_voidSetPinDirOutput(GPIO_PORTA,GPIO_PIN0,PushPull,LowSpeed);
	GPIO_voidSetPinDirOutput(GPIO_PORTB,GPIO_PIN0,PushPull,LowSpeed);
	GPIO_voidSetPinDirOutput(GPIO_PORTC,GPIO_PIN15,PushPull,LowSpeed);

	while(1)
	{
		GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,HIGH);
		GPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN0,HIGH);
		GPIO_voidSetPinValue(GPIO_PORTC,GPIO_PIN15,HIGH);
		delay(1000);
		GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,LOW);
		GPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN0,LOW);
		GPIO_voidSetPinValue(GPIO_PORTC,GPIO_PIN15,Low);
		delay(1000);
	}
}
