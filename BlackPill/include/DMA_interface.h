/*
 * DMA_interface.h
 *
 *  Created on: Mar 1, 2024
 *      Author: salma
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

void DMA_voidChannelInit();
void DMA_voidChannelStart(u32 *Copy_pu32SourceAdd,u32 *Copy_pu32DestinationAdd,u16 Copy_u16BlockLength );



#endif /* DMA_INTERFACE_H_ */
