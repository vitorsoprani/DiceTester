#ifndef _DICE_H
#define _DICE_H

typedef struct dice Dice;

Dice* dice_init(int nFaces);

void dice_destroy(Dice* d);

int dice_incrementFace(Dice* d, int face);

int dice_setFaceValue(Dice* d, int face, int value);

int dice_getFaceStat(Dice* d, int face);


#endif