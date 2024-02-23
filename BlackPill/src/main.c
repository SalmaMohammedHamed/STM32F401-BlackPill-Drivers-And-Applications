#include "definition.h"
#include "RCC_interface.h"
#include "Special_Functions.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "NVIC.private.h"
#include "EXTI_interface.h"
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

	GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN2 , HIGH );

}
void atia (void)
{
	/*Pin A2 High			*/
	GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN3 , HIGH );

}

void main ()
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_AHB,0);
	RCC_voidEnableClock(RCC_AHB,1);
	EXTI_vidSetCallBack(0, ahmed);
	EXTI_vidSetCallBack(1,atia);
	GPIO_voidSetPinDirInput(GPIO_PORTA,GPIO_PIN0,PullUp);
	GPIO_voidSetPinDirInput(GPIO_PORTA,GPIO_PIN1,PullUp);
	GPIO_voidSetPinDirOutput(GPIO_PORTA,GPIO_PIN2,PushPull,LowSpeed);
	GPIO_voidSetPinDirOutput(GPIO_PORTA,GPIO_PIN3,PushPull,LowSpeed);
	//AFIO_voidSetEXTIConfig(0, 0);
	//AFIO_voidSetEXTIConfig(1, 0);
	EXTI_voidInit();
	EXTI_voidenableEXTI(0);
	EXTI_voidenableEXTI(1);
	NVIC_Init();
	NVIC_voidEnableInterrupt(6);
	NVIC_voidEnableInterrupt(7);
	while(1)
	{
		if(GPIO_u8GetPinValue(GPIO_PORTA,GPIO_PIN1)==0)
		{
			GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,1);
		}
		else
		{
			GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,0);
		}
	}
}


