
#ifndef InfoNES_MAPPER_009_H_INCLUDED
#define InfoNES_MAPPER_009_H_INCLUDED

/*-------------------------------------------------------------------*/
/*  Include files                                                    */
/*-------------------------------------------------------------------*/

#include "../InfoNES_Types.h"

/*-------------------------------------------------------------------*/
/*  Function prototypes                                              */
/*-------------------------------------------------------------------*/


void Map9_Init();
void Map9_Write( WORD wAddr, BYTE byData );
void Map9_PPU( WORD wAddr );

#endif
