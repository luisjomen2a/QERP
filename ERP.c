#include <stdlib.h>
#include <stdio.h>

/*toutes les quantitees d'ingredients sont stoquees en gramme*/
float epinard=0;


/*Fonction qui calcule la consommation d'epinard ou de brandade
 * qteReccette represente les quantitees utilisees par la recette
 * productionParJour est la production journaliere de boites
 *
 * renvoie la quantite (en Kg) d'utilisation de l'ingredient donnee
 * */
float utilisationParJour(int qteRecette, int productionParJour){

	return qteRecette*productionParJour/1000;


}





int main(int argc, char** argv){

	printf("res %f kg",utilisationParJour(100.0,1075.0));


	return 1;

}
