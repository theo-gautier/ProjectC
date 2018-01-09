#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "DecodeCesar.hpp"
#include "Donnees.hpp"

bool rechercher_mot(const std::string Str, std::ifstream  fich){
    // recherche un mot dans le dictionnaire et renvoie true si celui-ci y est
    if (fich){ //si le fichier a été bien chargé
        std::string ligne;
        while(getline(fichier,ligne)){ //tant qu'il reste des lignes => saut de ligne dans le fichier (curseur dans le fichier)
            if (Str == ligne){
                return true;
            }
        }
    }
    else{
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }
    return false;
}

//    std::ifstream fichier("frenchssaccent.dic"); A IMPLEMENTER

