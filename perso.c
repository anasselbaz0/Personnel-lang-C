#include <stdio.h>
#include <stdlib.h>
#include "perso.h"

int main(){
	printf("   *** Gestion de ETUDIANTS ***");
	short rep=1;
	int choix;
	do{
		afficherMenu();
		printf("Votre choix est : ");
		scanf("%d",&choix);
		switch (choix){
			case 0:
				return 1;
				break;
			case 1: //Ajouter une personne
				system("clear");printf("   *** Gestion de personnel ***\n\n");
				printf("  ==> Ajout d'un personne:");
				if(ajouterPersonne()){
					printf("Personne ajoute avec sucsses!");
				} //avec une structure Personne
				else{
					printf("Personne non ajoute :(");
				}
				rep=1;
				break;
			case 2: //Supprimer une personne
				system("cls");printf("   *** Gestion de personnel ***\n\n");
				printf("  ==> Suppression d'un personne:");
				printf("Nom du personne a supprimer : ");
				char* p_nom;
				scanf("%s",p_nom);
				if(supprimerPersonne(p_nom)){
					printf("Personne supprime avec sucsses!");
				} //avec une structure Personne
				else{
					printf("Personne non supprime :(");
				}
				free(p_nom);
				rep=1;
				break;
			case 3://Mise a jour
				system("cls");printf("   *** Gestion de personnel ***\n\nHELLO HHHHHHHH");
				rep=1;
				break;
			case 4://Impression des donnees
				rep=1;
				break;
		}
	}while(rep==1);
	return 0;
}
