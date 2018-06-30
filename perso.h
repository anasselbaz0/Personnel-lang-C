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



int ajouterPersonne(Personne *A){  // Ajout au queue du liste chainee A
	int r=0;
	printf("   *** Gestion de personnel ***\n\n");
	printf("==> Ajout d'une personne:");
	Personne* p = NULL;
	p = (Personne*)malloc(sizeof(Personne));
	//Ajout des valeurs
	printf("\n");
	p->nom    = (char*)malloc(20 * sizeof(char));
	p->prenom = (char*)malloc(20 * sizeof(char));
	p->sexe   = (char*)malloc(10 * sizeof(char));
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
			while(i < n){
				p->enfants[i] = (char*)malloc(TAILLE_ID * sizeof(char));
				printf("   -Entrer l'id du **%d** enfant : ",i+1);
				scanf("%s",p->enfants[i]);
				i++;
			}
		}
	}
	p->id = (char*)malloc(TAILLE_ID * sizeof(char));
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
	r=1;
	return r;
}



void supprimerPersonne(Personne* A, char* p_nom){
	Personne * tmp = A;
	printf("Hi");
	while((tmp->suivant->nom != p_nom) && (tmp->suivant != NULL)){
		tmp = tmp->suivant;
	}
	Personne *a_supp = tmp;
	tmp->suivant = tmp->suivant->suivant;
	free(a_supp);
}

