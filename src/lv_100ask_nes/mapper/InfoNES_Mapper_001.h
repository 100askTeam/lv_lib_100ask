
#ifndef InfoNES_MAPPER_001_H_INCLUDED
#define InfoNES_MAPPER_001_H_INCLUDED


/*-------------------------------------------------------------------*/
/*  Include files                                                    */
/*-------------------------------------------------------------------*/

#include "../InfoNES_Types.h"

/*-------------------------------------------------------------------*/
/*  Function prototypes                                              */
/*-------------------------------------------------------------------*/

void Map1_Init();
void Map1_set_ROM_banks();
void Map1_Write( WORD wAddr, BYTE byData );

#endif
