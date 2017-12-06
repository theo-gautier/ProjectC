#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "DecodeCesar.hpp"


int main()
{
    char m[50]; //Buffer de message d'entrée

    printf("Entrez votre message codé : ");
    scanf("%s",m);

    char** l = liste_decodee(m);
    printListDecodee(l);

    return 0;
}

