//
//  Donnees.cpp
//  
//
//  Created by Luca Gorini on 24/12/2017.
//
//
#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "DecodeCesar.hpp"
#include "Donnees.hpp"

bool rechercher_mot(const std::string Str){
    // recherche un mot dans le dictionnaire et renvoie true si celui-ci y est
    // recherche linéaire en la longueur du dictionnaire et O( longueur_max_mot * n ) où n est la longueur du dico
    //On doit pouvoir optimiser le bordel. À moins de sacrifier fstream, impossible de copier tout le dico dans un vecteur sans faire au moins n opératoires (+ les sous jacentes à la copie)
    bool res = false;
    std::ifstream fichier("/Users/lucagorini/Documents/Electifs/ProjectC/frenchssaccent.dic");
    // /!\ NE PAS SUPPRIMER /!\ "/Users/lucagorini/Documents/Electifs/ProjectC/frenchssaccent.dic"
    //je suis passé sur un .txt mais je vais essayer avec le point dic
    if (fichier){ //si le fichier a été bien chargé
        std::string ligne;
        while(getline(fichier,ligne)){ //tant qu'il reste des lignes => saut de ligne dans le fichier (curseur dans le fichier)
            if (Str == ligne){
                res = true;
            }
        }
    }
    else{
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }
    return res;
}

int Find_Index_mot(const std::string mot){
    //prend en entrée un mot et renvoie l'index de décodage qui permet de retrouver un mot du dictionnaire !
    std::vector<std::string> l;
    l = liste_decodee(mot);
    unsigned long len = l.size();
    for (int i = 0 ; i < len ; i++){
        if (rechercher_mot(l[i])){
            return i;
        }
    }
    return -1;
}

int Find_Index(const std::vector<std::string> phrase){
    //Prend un vector de string en entrée (après avoir éliminé les parenthèses ?) est ce le format de données le plus adapté ?
    // renvoie un entier correspondant à l'index de décodage de la phrase (dans l'hypothèse où il n'existe qu'un seul décalage d'un mot qui soit dans le dico (ex: fin a pour décalage lot donc ça ne risque de pas marcher pour un tel mot) => on  ne veut plus de ça on tombe rapidement sur des bugs
    unsigned long len = phrase.size();
    for (int i = 0; i <len ; i++){
        int index_tmp = Find_Index_mot(phrase[i]);
        if (index_tmp!= -1){
            return index_tmp;
        }
    }
    return 0;
}


