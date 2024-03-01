#include "definition.h"
#include "RCC_interface.h"
#include "Special_Functions.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "NVIC.private.h"
#include "EXTI_interface.h"
#include "SysTick_interface.h"
#include "SYSCFG_interface.h"
#include "OS_interface.h"
#include "Lcd_Interface.h"
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

void ahmed (void)
{
	while(1)
	{
		static u8 state =0;
			if(state==0)
			{
				GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , HIGH );
				NVIC_voidSetPendingFlag(7);
				delay(2000);
				state=1;
			}
			else
			{
				GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , Low );
				NVIC_voidSetPendingFlag(7);
				delay(2000);
				state=0;
			}

	}

}
void atia (void)
{
	static u8 state =0;
	if(state==0)
	{
		GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , HIGH );
		delay(2000);
		state=1;
	}
	else
	{
		GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , Low );
		delay(2000);
		state=0;
	}
}
int main(void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_AHB, 0);
	GPIO_voidSetPinDirOutput(GPIO_PORTA,GPIO_PIN0,PushPull,LowSpeed);
	GPIO_voidSetPinDirOutput(GPIO_PORTA,GPIO_PIN1,PushPull,LowSpeed);
	EXTI_vidSetCallBack(0,ahmed);
	EXTI_vidSetCallBack(1,atia);
	NVIC_voidSetPriority(6,1,0);
	NVIC_voidSetPriority(7,0,0);
	NVIC_voidEnableInterrupt(6);
	NVIC_voidEnableInterrupt(7);
	NVIC_voidSetPendingFlag(6);

  while (1)
  {

  }

}

