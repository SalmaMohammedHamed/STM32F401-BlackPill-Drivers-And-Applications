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
#include "DMA_interface.h"
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
	u32 Arr1=0;
	u32 Arr2;

	u32 Arr3[1000]={0};
	u32 Arr4[1000];
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_AHB, 0);
	RCC_voidEnableClock(RCC_AHB, 21);
	RCC_voidEnableClock(RCC_AHB, 22);
	GPIO_voidSetPinDirOutput(GPIO_PORTA,GPIO_PIN0,PushPull,LowSpeed);
	GPIO_voidSetPinDirOutput(GPIO_PORTA,GPIO_PIN1,PushPull,LowSpeed);
	DMA_voidChannelInit(0,0);
	NVIC_voidEnableInterrupt(11);
	DMA_voidChannelStart(0,&Arr1,&Arr2,1);
	//NVIC_voidSetPendingFlag(11);
	for (u16 i=0;i<1000;i++)
	{
		Arr4[i]=Arr3[i];


	}


  while (1)
  {

  }

}
/*ISR*/
/*clear the flags*/
void DMA1_Stream0_IRQHandler(void)
{
	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,HIGH);
	while(1);
}
