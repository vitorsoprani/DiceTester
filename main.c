#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[]) {
    int nFaces = 0;
    printf("Quantas faces tem o seu dado? ");
    scanf("%d", &nFaces);

    int* faces = (int*)calloc(nFaces ,sizeof(int));
    
    int i = 1;
    while(1) {
        int faceAtual;
        printf("Digite um numero negativo para finalizar o teste\n");
        printf("Rolagem numero %d: ", i++);
        scanf("%d", &faceAtual);
        fflush(stdin);
        system("clear");

        if (faceAtual > nFaces)
            continue;
        if (faceAtual < 0)
            break;

        faces[faceAtual]++;
    }
    
    printf("Numero de ocorrencias por face:\n");
    for (int i = 0; i < nFaces; i++)
        printf("Face numero %d: %d\n", i + 1, faces[i + 1]);

    free(faces);

    return 0;
}
