#include <stdio.h>

#include "dice.h"

int main(int argc, char* argv[]) {
    int nFaces = 0;
    printf("Quantas faces tem o seu dado? ");
    scanf("%d%*c", &nFaces);

    Dice* d = dice_init(nFaces);
    
    printf("Digite um numero negativo para finalizar o teste\n");
    int i = 1;
    while(1) {
        int faceAtual = - 1;
        printf("Rolagem numero %d: ", i++);
        scanf("%d%*c", &faceAtual);

        if (faceAtual < 0)
            break;
    
        dice_incrementFace(d, faceAtual);
    }
    
    printf("Numero de ocorrencias por face:\n");
    for (int i = 0; i < nFaces; i++)
        printf("Face numero %d: %d\n", i + 1, dice_getFaceStat(d, i + 1));

    dice_destroy(d);
    return 0;
}
