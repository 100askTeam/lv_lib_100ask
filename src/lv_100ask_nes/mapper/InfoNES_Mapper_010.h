
#ifndef InfoNES_MAPPER_010_H_INCLUDED
#define InfoNES_MAPPER_010_H_INCLUDED

/*-------------------------------------------------------------------*/
/*  Include files                                                    */
/*-------------------------------------------------------------------*/

#include "../InfoNES_Types.h"

/*-------------------------------------------------------------------*/
/*  Function prototypes                                              */
/*-------------------------------------------------------------------*/


void Map10_Init();
void Map10_Write( WORD wAddr, BYTE byData );
void Map10_PPU( WORD wAddr );

#endif
