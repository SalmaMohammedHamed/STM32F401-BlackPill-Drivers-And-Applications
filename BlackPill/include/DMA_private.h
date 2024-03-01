/*
 * DMA_private.h
 *
 *  Created on: Mar 1, 2024
 *      Author: salma
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

typedef struct
{

}channel;
typedef struct
{
	volatile u32 DMA_LISR;
	volatile u32 DMA_HISR;
	volatile u32 DMA_LIFCR;
	volatile u32 DMA_HIFCR;
	channel DMAChannel [7];
}DMA_t;

#define DMA ((volatile DMA_t *) 0x40026000 )

#endif /* DMA_PRIVATE_H_ */
