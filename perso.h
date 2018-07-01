typedef struct Personne{
	char*            nom;
	char*            prenom;
	char*            sexe;
	int              nbr_enfant;
	char**           enfants;
	char*            id;
	struct Personne* suivant;
}Personne;



void afficherMenu(){
	printf("		*** Gestion de personnel ***");
	printf("\n\n      1- Ajouter       une personne");
	printf("\n      2- Supprimer     une personne");
	printf("\n      3- Mise a jour d'une personne");
	printf("\n      4- Imprimer les donnees");
	printf("\n      0- Quitter\n\n");
}



bool ajouterPersonne(Personne* A){  // Ajout au queue du liste chainee A
	printf("   *** Gestion de personnel ***\n\n");
	printf("==> Ajout d'une personne:");
	Personne* p = NULL;
	p = (Personne*)malloc(sizeof(Personne));
	if(p == NULL){
		printf("Allocation echouee _1:(");
		return false;
	}
	else{
		//Ajout des valeurs
		printf("\n");
		p->nom    = (char*)malloc(20 * sizeof(char));
		p->prenom = (char*)malloc(20 * sizeof(char));
		p->sexe   = (char*)malloc(10 * sizeof(char));
		p->id     = (char*)malloc(TAILLE_ID * sizeof(char));
		if( (p->nom == NULL) || (p->prenom == NULL) || (p->sexe == NULL) || (p->id == NULL) ){
			printf("Allocation echouee _2");
			return false;
		}
		printf("  Nom              = ");    scanf("%s",p->nom);	
		printf("  Prenom           = ");    scanf("%s",p->prenom);
		printf("  Sexe             = ");    scanf("%s",p->sexe);
		printf("  Nombre d enfants = ");    scanf("%d",&p->nbr_enfant);
		int n = p->nbr_enfant;
		if(n < 0){ //si c'est negatif, on le considere comme nulle
			p->nbr_enfant = 0;
			printf("  Nombre d enfants = 0");
		}
		else{ // n >= 0
			if(n > 0){  // n != 0
				int i = 0;
				p->enfants = (char**)malloc(n * sizeof(char*));
				if(p->enfants == NULL){
					printf("Allocation echouee _3");
					return false;
				}
				while(i < n){
					p->enfants[i] = (char*)malloc(TAILLE_ID * sizeof(char));
					if(p->enfants[i] == NULL){
						printf("Allocation echouee _%d",4+i);
						return false;
					}
					printf("   -Entrer l'id du **%d** enfant : ",i+1);
					scanf("%s",p->enfants[i]);
					i++;
				}
			}
		}
		printf("  Identifient personnel (%d caracteres) = ",TAILLE_ID);   scanf("%s",p->id);
		//Ajout a la liste
		p->suivant = NULL;
		if(A == NULL){
			A = p;
		}
		else{
			Personne *tmp = A;
			while(tmp->suivant != NULL){
				tmp = tmp->suivant;
			}
			tmp->suivant = p;
		}
		return true;
	}
}



void supprimerPersonne(Personne* A, char* p_nom){
	Personne * tmp = A;
	while((tmp->suivant->nom != p_nom) && (tmp->suivant != NULL)){
		tmp = tmp->suivant;
	}
	Personne *a_supp = tmp;
	tmp->suivant = tmp->suivant->suivant;
	free(a_supp);
}


void  dataToFile(char* filename, Personne* A){
	FILE* f = NULL;
	f = fopen(filename, "w");
	Personne* tmp = A;
	/*while(tmp != NULL){
		fprintf(f, "Nom\tPrenom\tSexe\tNombre denfants\tIdentifiant");
		fprintf(f, "%s\t%s\t%s\t%d\t%s\n\n", tmp->nom, tmp->prenom, tmp->sexe, tmp->nbr_enfant, tmp->id);
		tmp = tmp->suivant;
	}*/
	fprintf(f, "Nom\tPrenom\tSexe\tNombre denfants\tIdentifiant\n");
	fprintf(f, "%s\t%s\t%s\t%d\t%s\n\n", A->nom, A->prenom, A->sexe, A->nbr_enfant, A->id);
	fclose(f);
}
