#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAILLE_ID 4
#include "perso.h"

int main(){
	Personne* MAIN; //liste chaine ou on va stocker les donnees
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
				if(ajouterPersonne(MAIN)){
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
				supprimerPersonne(MAIN, p_nom);
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
				printf("Nom de fichier : ");
				char* filename;// = malloc(20*sizeof(char));
				scanf("%s",filename);
				dataToFile(filename, MAIN);
				printf("Enregistre vers %s", filename);
				rep=1;
				break;
		}
	}while(rep==1);
	printf("Vous allez quitter le systeme ...");
	return 0;
}
