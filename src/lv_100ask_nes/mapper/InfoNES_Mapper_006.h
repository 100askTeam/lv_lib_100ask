
#ifndef InfoNES_MAPPER_006_H_INCLUDED
#define InfoNES_MAPPER_006_H_INCLUDED

/*-------------------------------------------------------------------*/
/*  Include files                                                    */
/*-------------------------------------------------------------------*/

#include "../InfoNES_Types.h"

/*-------------------------------------------------------------------*/
/*  Function prototypes                                              */
/*-------------------------------------------------------------------*/


void Map6_Init();
void Map6_Write( WORD wAddr, BYTE byData );
void Map6_Apu( WORD wAddr, BYTE byData );
void Map6_HSync();

#endif
