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
    /*cin permet de récupérer des entrées comme scanf à la seule différence que scanf renvoie des char*
     et pas des string */
    bool res;
    res = rechercher_mot(str);
    std::cout << res << std::endl;
    std::string message;
    std::cin >> message;
    std::vector<std::string> l = liste_decodee(message);
    printListDecodee(l);
    //Test de Find_Index_mot
    std::string test = "bonjour"; //renvoie -1 pour klac, 23 pour bonjour
    std::string test_d = decodeCesar(test,3);
    //ça retourne 23 (26 - 3) héhéhé petite erreur qui au final est bien pratique, si l'index de chiffrage est 3 l'index de déchiffrage (car on autorise que les entiers NATURELS sur un cycle de 26)  est 23
    int index1 = Find_Index_mot(test_d);
    std::cout << index1 << std::endl;
    //Test de Find_Index
    /* std::vector<std::string> phrase = {"kf","nbohf","vo","cpocpo"}; */
    std::vector<std::string> phrase;
    phrase.push_back("kf");
    phrase.push_back("nbohf");
    phrase.push_back("vo");
    phrase.push_back("cpocpo");
    //fonctionne mal => cf. le cpp correspondant pour l'explication
    int index2 = Find_Index(phrase);
    std::cout << index2 << std::endl;
    return 0;
}



/* 
 Remarques: 
 fstream gère mieux les string (chaine de caractères de C++) que les char* (chaîne de caractères de C)
 
 Améliorations possibles (à partir de ce que Théo a déjà commencé à faire):

1.On peut envisager de ne pas s'arrêter une fois un bon décalage bon mais un décalage bon est trouvé que celui fonctionne aussi pour les autres
2.usage des const
3.gestion des langues à alphabet latin => travail de recherche de dictionnaire (adaptation ?)
4.problème aevc la conjugaison
5.problème avec les accents
6. Optimiser si possible (suppression de fstream T_T) la recherche d'un mot dans le dico qui est une magnifique liste triée.
7. Augmenter les possibilités de codage (Vigenère par exemple)
8. Déguiser la strcture des phrase (cf pdf (à push))
9. On attaque César par force brute. En efet, on croise tous les décalages de chaque mot de la phrase avec le dictionnair epour récupérer l'indice. 
 
 
 Solutions possibles:
 1. il y a un petit problème avec les mots de 2 lettres, beaucoup de décalages fonctionnent et posent des problèmes, à première vue il faut enregistrer l'ensemble des décalages possibles pour un mot et croiser ces possibilités pour les autres mots de l phrase. Il y a très peu de chances qu'il reste plus d'un décalage possible pour la phrase 
 2. To do
 4. Régler les accents avant la conjugaison <3
 5. règle-t-on les accents ?
 6. Dichotomie ?
 
 */
