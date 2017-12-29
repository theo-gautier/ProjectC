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
    std::ifstream fichier("frenchssaccent.dic");
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

std::vector<int> Find_Index_mot(const std::string mot){
    //prend en entrée un mot et renvoie l'index de décodage qui permet de retrouver un mot du dictionnaire !
    std::vector<std::string> l;
    l = liste_decodee(mot);
    std::vector<int> liste_index; //liste des décodages possibles pour un nombre
    unsigned long len = l.size();
    for (int i = 0 ; i < len ; i++){
        if (rechercher_mot(l[i])){
            liste_index.push_back(i);
        }
    }
    return liste_index; //on suppose que cette liste n'est jamais vide
}

// Recherche d'un élément dans un vector /!\NAIVE  il existe surement des méthodes déjà implémentées/!\

bool Recherche_elt(const std::vector<int> tab, const int entier){
    int len = tab.size();
    for (int i = 0; i < len; i++){
        if (entier == tab[i]){
            return true;
        }
    }
    return false;
}
//Fonction de croisement de 2 vector d'entiers  /!\ TRÈS NAIVE /!\

std::vector<int> Intersect_Vectors(const std::vector<int> vec1, const std::vector<int> vec2){
    std::vector<int> intersect; //vecteur intersection
//quelle taille est donné de base à intersect ?
    unsigned long len1 = vec1.size();
    unsigned long len2 = vec2.size();
    for (int i = 0 ; i < len1 ; i++){
        int tmp = vec1[i];
        if (Recherche_elt(vec2,tmp)){
            intersect.push_back(tmp);
        }
    }
    return intersect; //Si les phrases ne contiennent pas d'erreur, c'est non vide
}

int Find_Index(const std::vector<std::string> phrase){
    //Prend un vector de string en entrée (après avoir éliminé les parenthèses ?) est ce le format de données le plus adapté ?
    // renvoie un entier correspondant à l'index de décodage de la phrase (dans l'hypothèse où il n'existe qu'un seul décalage d'un mot qui soit dans le dico (ex: fin a pour décalage lot donc ça ne risque de pas marcher pour un tel mot) => on  ne veut plus de ça on tombe rapidement sur des bugs
    //FORCE BRUTE
    std::vector<int> index_tmp1 = Find_Index_mot(phrase[0]);
    unsigned long len = phrase.size();
    for (int i = 1; i < len ; i++){
        std::vector<int> index_tmp2 = Find_Index_mot(phrase[i]);
        index_tmp1 = Intersect_Vectors(index_tmp1, index_tmp2); //cela fonctionne -t-il
    }
    return index_tmp1[0]; //il ne doit rester qu'un seul entier dans l'intersection générale (très forte probabilité)
}


