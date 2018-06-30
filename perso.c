#include <stdio.h>
#include <stdlib.h>
#define TAILLE_ID 4
#include "perso.h"

int main(){
	short rep=1;
	int choix;
	do{
		system("clear");
		afficherMenu();
		printf("Votre choix est : ");
		scanf("%d",&choix);
		switch (choix){
			case 0:
				rep=0;
				break;
			case 1: //Ajouter une personne
				system("clear");
				int m = ajouterPersonne();
				if(m == 1){
					printf("Personne ajoute!");
				}
				else{
					printf("Ajout non accorde!");
				}
				rep=1;
				break;
			case 2: //Supprimer une personne
				system("clear");
				printf("   *** Gestion de personnel ***\n\n");
				printf("==> Suppression d'une personne:\n");
				printf("  Nom du personne a supprimer : ");
				char* p_nom;
				scanf("%s",p_nom);
				supprimerPersonne(p_nom);
				free(p_nom);
				rep=1;
				break;
			case 3: //Mise a jour
				system("clear");
				printf("   *** Gestion de personnel ***\n\n");
				rep=1;
				break;
			case 4://Impression des donnees
				system("clear");
				printf("   *** Gestion de personnel ***\n\n");
				rep=1;
				break;
		}
	}while(rep==1);
	printf("Vous allez quitter le systeme ...");
	return 0;
}
