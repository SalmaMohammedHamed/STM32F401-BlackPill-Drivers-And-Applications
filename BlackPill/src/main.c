#include "definition.h"
#include "RCC_interface.h"
#include "Special_Functions.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "NVIC.private.h"
#include "EXTI_interface.h"
#include "SysTick_interface.h"
#include "SYSCFG_interface.h"
#include "SYSCFG_private.h"
void ahmed (void)
{

	GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , HIGH );

}
void atia (void)
{
	/*Pin A2 High			*/
	GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , HIGH );

}
int main(void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_AHB, 0);
	RCC_voidEnableClock(RCC_AHB, 1);
	RCC_voidEnableClock(RCC_APB2,14);
	EXTI_vidSetCallBack(0, ahmed);
	EXTI_vidSetCallBack(1,atia);
	GPIO_voidSetPinDirInput(GPIO_PORTB,GPIO_PIN0,PullUp);
	GPIO_voidSetPinDirOutput(GPIO_PORTA,GPIO_PIN1,PushPull,LowSpeed);
	SYSCFG_EXTICR1=0x00000001;
	EXTI_voidInit();
	EXTI_voidenableEXTI(0);
	NVIC_Init();
	NVIC_voidEnableInterrupt(6);

  while (1)
  {

  }

}

