
#ifndef InfoNES_MAPPER_004_H_INCLUDED
#define InfoNES_MAPPER_004_H_INCLUDED

/*-------------------------------------------------------------------*/
/*  Include files                                                    */
/*-------------------------------------------------------------------*/

#include "../InfoNES_Types.h"

/*-------------------------------------------------------------------*/
/*  Function prototypes                                              */
/*-------------------------------------------------------------------*/


void Map4_Init();
void Map4_Write( WORD wAddr, BYTE byData );
void Map4_HSync();
void Map4_Set_CPU_Banks();
void Map4_Set_PPU_Banks();

#endif
