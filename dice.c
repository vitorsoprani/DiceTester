#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dice.h"

#define DEBUG_DICE 1

struct dice{
    int* faces; //Each position in the vector represents a face.
    int nFaces;
};

Dice* dice_init(int nFaces) {
    Dice* d = (Dice*)malloc(sizeof(Dice));
    
    #if DEBUG_DICE
        assert(nFaces > 0);
        assert(d != NULL);
    #else 
        if (d == NULL || nFaces <= 0)  return NULL;
    #endif

    d->nFaces = nFaces;
    d->faces = (int*)calloc(nFaces, sizeof(int));

    #if DEBUG_DICE
        assert(d->faces != NULL);
    #else
        if (d->faces == NULL){
            free(d);
            return NULL;
        }
    #endif

    return d;
}

void dice_destroy(Dice* d) {
    #if DEBUG_DICE
        assert(d != NULL);
    #endif

    if (d != NULL) {
        free(d->faces);
        free(d);
    }
}

int dice_incrementFace(Dice* d, int face) {
    #if DEBUG_DICE
        assert(d != NULL);
        assert(face <= d->nFaces);
        assert(face > 0);
    #else
        if (dice == NULL)
            return 0;
        if (face <= 0)
            return 0;
        if (face > d->nFaces)
            return 0;
    #endif

    d->faces[face - 1]++;
    return 1;
}

int dice_setFaceValue(Dice* d, int face, int value) {
    #if DEBUG_DICE
        assert(d != NULL);
        assert(face <= d->nFaces);
        assert(face > 0);
        assert(value >= 0);
    #else
        if (dice == NULL)
            return 0;
        if (face <= 0)
            return 0;
        if (face > d->nFaces)
            return 0;
        if (value < 0)
            return 0;
    #endif

    d->faces[face - 1] = value;
    return 1;
}

int dice_getFaceStat(Dice* d, int face) {
    #if DEBUG_DICE
        assert(d != NULL);
        assert(face <= d->nFaces);
        assert(face > 0);
    #else
        if (dice == NULL)
            return 0;
        if (face <= 0)
            return 0;
        if (face > d->nFaces)
            return 0;
    #endif

    return d->faces[face - 1];
}