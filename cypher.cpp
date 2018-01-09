#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "DecodeCesar.hpp"
#include "Donnees.hpp"



int main()
{
    /*std::string str;
    std::cin >> str;*/


    std::string test = "bonjour je suis un cochon"; //renvoie -1 pour klac, 23 pour bonjour
    std::string test_d = decodeCesar(test,3);


    int index2 = Find_Index(phrase);
    std::cout << index2 << std::endl;
    return 0;
}



/* 
 Remarques: 
- fstream gere mieux les string (chaine de caracteres de C++) que les char* (chaine de caracteres de C)
- /!\ PROBLEME AVEC LES ACCENTS ENTRE NOS MACHINES /!\
 
 
 Ameliorations possibles (a partir de ce que Theo a deja commence a faire):

3.gestion des langues a alphabet latin/ reconnaisance automatique de la langue a partir des dictionnaires => travail de recherche de dictionnaire (adaptation ?)
4.probleme avec la conjugaison
5.probleme avec les accents
6. Optimiser si possible (suppression de fstream T_T) la recherche d'un mot dans le dico qui est une magnifique liste triee.
7. Augmenter les possibilites de codage (Vigenere par exemple mais ca devient plus complique on peut deja complique Cesar cf 8. )
8. Les vrais cryptogrammes suppriment les espaces, la ponctuation, les accents. Ils recollent tout et font des petits paquets de 3,4 ou 5. Pour Cesar, les paquets n'ont pas vraiment d'importance mais le fait de tout coller et de supprimer ponctutation etc ca deviendrait marrant :)

 11. Probleme et grosse perte de TEMPS aussi, (j'ai pas eu le temps d'optimiser) à chaque appel de recherche_mot (ie de Find_Index_mot) on ouvre puis on ferme le .dic ce qui doit manger pas mal de temps en plus du fait que les fonctions de recher d'elt(intersect, entier dans un tableau trié qui plus est ne sont pas optimisés).
 
 Solutions possibles:
 2. To do
 4. Regler les accents avant la conjugaison <3
 5. regle-t-on les accents ?
 6. Dichotomie ?
 
 */
