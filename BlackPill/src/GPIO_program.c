/*
 * GPIO_program.c
 *
 *  Created on: Feb 23, 2024
 *      Author: salma
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "definition.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

void GPIO_voidSetPinDirOutput(u8 Copy_PORT, u8 Copy_PIN,u8 Copy_Type,u8 Copy_Speed)
{
	switch(Copy_PORT)
		{
			case GPIO_PORTA:
				if(Copy_PIN < 16)
				{

					GPIOA_MODER &= ~((0b11) << (Copy_PIN * 2));
					GPIOA_MODER |= ((output) << (Copy_PIN * 2));
					GPIOA_OTYPER &= ~((0b1) << (Copy_PIN));
					GPIOA_OTYPER |= ((Copy_Type) << (Copy_PIN));
					GPIOA_OSPEEDR &= ~((0b11) << (Copy_PIN * 2));
					GPIOA_OSPEEDR |= ((Copy_Speed) << (Copy_PIN * 2));
				}
			break;
			case GPIO_PORTB:
				if(Copy_PIN < 16)
				{
					GPIOB_MODER &= ~((0b11) << (Copy_PIN * 2));
					GPIOB_MODER |= ((output) << (Copy_PIN * 2));
					GPIOB_OTYPER &= ~((0b1) << (Copy_PIN));
					GPIOB_OTYPER |= ((Copy_Type) << (Copy_PIN));
					GPIOB_OSPEEDR &= ~((0b11) << (Copy_PIN * 2));
					GPIOB_OSPEEDR |= ((Copy_Speed) << (Copy_PIN * 2));
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			case GPIO_PORTC:
				if(Copy_PIN < 16)
				{
					GPIOC_MODER &= ~((0b11) << (Copy_PIN * 2));
					GPIOC_MODER |= ((output) << (Copy_PIN * 2));
					GPIOC_OTYPER &= ~((0b1) << (Copy_PIN));
					GPIOC_OTYPER |= ((Copy_Type) << (Copy_PIN));
					GPIOC_OSPEEDR &= ~((0b11) << (Copy_PIN * 2));
					GPIOC_OSPEEDR |= ((Copy_Speed) << (Copy_PIN * 2));
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			default:
				/**< RETURN ERROR STATUS */
			break;
		}
		/**< RETURN ERRORSTATUS */
}

void GPIO_voidSetPinValue(u8 Copy_PORT,u8 Copy_PIN, u8 Copy_Value)
{
	if(Copy_PIN < 16)
	{
		switch(Copy_PORT)
		{
			case GPIO_PORTA:
				if(Copy_Value == HIGH)
				{
					SET_BIT(GPIOA_ODR, Copy_PIN);
				}
				else if(Copy_Value == LOW)
				{
					CLR_BIT(GPIOA_ODR, Copy_PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			case GPIO_PORTB:
				if(Copy_Value == HIGH)
				{
					SET_BIT(GPIOB_ODR, Copy_PIN);
				}
				else if(Copy_Value == LOW)
				{
					CLR_BIT(GPIOB_ODR, Copy_PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			case GPIO_PORTC:
				if(Copy_Value == HIGH)
				{
					SET_BIT(GPIOC_ODR, Copy_PIN);
				}
				else if(Copy_Value == LOW)
				{
					CLR_BIT(GPIOC_ODR, Copy_PIN);
				}
				else
				{
					/**< RETURN ERROR STATUS */
				}
			break;
			default:
				/**< RETURN ERROR STATUS */
			break;
		}
	}
	else
	{
		/**< RETURN ERROR STATUS */
	}
	/**< RETURN ERROR STATUS */
}

