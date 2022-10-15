/* Projeto Jogo da Vida - PUCSP - Prof° Júlio - 2022*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "Windows.h"
#include "functions.h"

int main() {

    //Pega a informação dos carecteres em português
    setlocale(LC_ALL, "Portuguese");

    //Mostra toda a parte inicial do jogo ao usuário
    aberturaJogo();
    
}