/*
 * DMA_program.c
 *
 *  Created on: Mar 1, 2024
 *      Author: salma
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "definition.h"
#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"


void DMA_voidChannelInit()
{
/*
 * 1- memory to memory
 *2- size=32 bit
 *3-MINC&PINK activated
 *4-no circular
 *5-transfer int*/
}
void DMA_voidChannelStart(u32 *Copy_pu32SourceAdd,u32 *Copy_pu32DestinationAdd,u16 Copy_u16BlockLength )
{
	//make sure channel is disabled
	//Addresses
	//block length
	//enable
}
