#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "DecodeCesar.hpp"


int main()
{
    char m[50]; //Buffer de message d'entr�e

    printf("Entrez votre message cod� : ");
    scanf("%s",m);

    char** l = liste_decodee(m);
    printListDecodee(l);

    return 0;
}

