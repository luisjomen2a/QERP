#include <stdlib.h>
#include <stdio.h>

/*toutes les quantitees d'ingredients sont stoquees en gramme*/
float epinard=500000;
float sel=5000;
float epices=5000;
float ail=5000;
float morue=100000;


int stockBoiteAnnuelle=23000;
int stockBrandadeAnnuelle=5000;
int stockBoite=23000;
int stockBrandade=5000;

int productionParHeure = 1075/7;

int jourSemaine=1, jourMois=1, mois=1, semaine=1;

// boolMorue : 1-> production de Brandade, 0-> production d'epinard

/***

Fon

***/
void productionJournaliere(int heure, float productivite, int boolMorue)
{
	int boiteAProduire = productivite*productionParHeure*heure;

	epinard-=boiteAProduire*100;
	sel-=boiteAProduire*0.0225;
	ail-=boiteAProduire*0.1;
	epices-=boiteAProduire*0.02;

	if(boolMorue)
	{
		morue-=boiteAProduire*100;
		stockBrandadeAnnuelle+=boiteAProduire;
		stockBrandade+=boiteAProduire;
	}
	else
	{
		stockBoiteAnnuelle+=boiteAProduire;
		stockBoite+=boiteAProduire;
	}	
} 

//Q1
void verifieStock()
{
	int jourCommande = jourMois-8;
	int moisCommande = mois;
	if(jourCommande<=0)
	{
		moisCommande--;
		jourCommande=30+jourCommande;
	}
	if(epinard<=0)
	{
		printf("commander 500kg d'epinard le %d / %d\n", jourCommande, moisCommande);
		epinard+=500000;
		
	}
	if(sel<=0)
	{
		printf("commander 5kg de sel le %d / %d\n", jourCommande, moisCommande);
		sel+=5000;
	}
	if(epices<=0)
	{
		printf("commander 5kg d'epices le %d / %d\n", jourCommande, moisCommande);
		epices+=5000;
	}
	if(ail<=0)
	{
		printf("commander 5kg d'ail le %d / %d\n", jourCommande, moisCommande);
		ail+=5000;
	}
	if(morue<=0)
	{
		printf("commander 500kg de brandade de morue le %d / %d\n", jourCommande, moisCommande);
		morue+=500000;
	}
}

void venteProduits(int moisCourant){


	
	if(moisCourant >= 6 && moisCourant <= 8){
		
		stockBoite -= 21600;
		stockBrandade -= 4800;

	}
	else{

		stockBoite -= 18000;
		stockBrandade -= 4000;

	}

	if(stockBoite <= 0){

		printf("Attention! Vous avez trop vendu! Vos stock de Boite d'épinards sont maintenant négatifs\n Mois : %d",moisCourant);

	}

	if(stockBrandade <= 0){

		printf("Attention! Vous avez trop vendu! Vos stocks de Brandade de Morue sont maintenant négatifs\n Mois : %d",moisCourant);

	}
}

void simulation(float productivite)
{

	while(jourMois<=30 && mois<=12)
	{

		// production
		if(jourSemaine == 1 && semaine%2==0)	// si on doit changer de serie
			productionJournaliere(4, productivite, semaine%2);
		else
			productionJournaliere(7, productivite, semaine%2);


		verifieStock();	
	

		// avance dans le temps
		jourSemaine ++;
		jourMois ++;
		if(jourSemaine==6)
		{
			jourMois +=2;
			
			jourSemaine=1;
			semaine++;
		}
		if(jourMois>30)
		{
			jourMois-=30; //JoursMois = 32
			mois++;

			//Ventes des produits
			venteProduits(mois);
		}

	}
}





int main(int argc, char** argv){


	simulation(1.0);	
		

	return 0;

}
