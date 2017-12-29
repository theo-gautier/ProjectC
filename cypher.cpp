#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "DecodeCesar.hpp"
#include "Donnees.hpp"



int main()
{
    std::string str;
    std::cin >> str;
    /*cin permet de r�cup�rer des entr�es comme scanf � la seule diff�rence que scanf renvoie des char*
     et pas des string */
    bool res;
    res = rechercher_mot(str);
    std::cout << res << std::endl;
    std::string message;
    std::cin >> message;
    std::vector<std::string> l = liste_decodee(message);
    printVectorString(l);
    //Test de Find_Index_mot
    std::string test = "bonjour"; //renvoie -1 pour klac, 23 pour bonjour
    std::string test_d = decodeCesar(test,3);
    //�a retourne 23 (26 - 3) h�h�h� petite erreur qui au final est bien pratique, si l'index de chiffrage est 3 l'index de d�chiffrage (car on autorise que les entiers NATURELS sur un cycle de 26)  est 23
    std::vector<int> index1 = Find_Index_mot(test_d);
    printVectorInt(index1);
    //Test de Find_Index
    //Phrase � coder: Je mange un bonbon
    /* std::vector<std::string> phrase = {"kf","nbohf","vo","cpocpo"}; fonctionne sur xcode mais pas dans le terminal */
    std::vector<std::string> phrase;
    phrase.push_back("kf");
    phrase.push_back("nbohf");
    phrase.push_back("vo");
    phrase.push_back("cpocpo");
//�a renvoie 25 = (26 -1) OK
    int index2 = Find_Index(phrase);
    std::cout << index2 << std::endl;
    return 0;
}



/* 
 Remarques: 
- fstream g�re mieux les string (chaine de caract�res de C++) que les char* (cha�ne de caract�res de C)
- /!\ PROBL�ME AVEC LES ACCENTS ENTRE NOS MACHINES /!\
 
 
 Am�liorations possibles (� partir de ce que Th�o a d�j� commenc� � faire):

1.On peut envisager de ne pas s'arr�ter une fois un bon d�calage bon mais un d�calage bon est trouv� que celui fonctionne aussi pour les autres => OK �TESTER SUR D'AUTRES CHOSES
2.usage des const => OK
3.gestion des langues � alphabet latin => travail de recherche de dictionnaire (adaptation ?)
4.probl�me aevc la conjugaison
5.probl�me avec les accents
6. Optimiser si possible (suppression de fstream T_T) la recherche d'un mot dans le dico qui est une magnifique liste tri�e.
7. Augmenter les possibilit�s de codage (Vigen�re par exemple)
8. D�guiser la strcture des phrase (cf pdf (� push))
9. On attaque C�sar par force brute. En efet, on croise tous les d�calages de chaque mot de la phrase avec le dictionnair epour r�cup�rer l'indice. 
10. Travailler l'affichage des vecteurs
 //printListDecodee pourrair devenir  PrintVector le probl�me est l'argument! comment �crire de mani�re concise pas avec des vieux IF ou quoi une seule fonction pour print � la fois des std::vector<std::string> et des std::vector<int> est ce que passer en argument std::vector sest-il possible ?
    -Suppression des parenth�ses sauf si Th�o veut faire un joli affichage.
 
 Solutions possibles:
 1. il y a un petit probl�me avec les mots de 2 lettres (par exemple), beaucoup de d�calages fonctionnent et posent des probl�mes. � premi�re vue il faut enregistrer l'ensemble des d�calages possibles pour un mot et croiser ces possibilit�s pour les autres mots de la phrase. Il y a tr�s peu de chances qu'il reste plus d'un d�calage possible pour la phrase enti�re => OK mais m�thode na�ve et un peu � l'aveugle concernant la manipulation des vector
 2. To do
 4. R�gler les accents avant la conjugaison <3
 5. r�gle-t-on les accents ?
 6. Dichotomie ?
 
 */
