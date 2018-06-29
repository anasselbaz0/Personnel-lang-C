struct Personne{
	char*  nom;
	char*  prenom;
	char*  sexe;
	int    nbr_enfant;
	char** enfants;
	char*  id;
	struct Personne* suivant;
};

struct Personne A;

void afficherMenu(){
	printf("\n\n    1- Ajouter   une personne");
	printf("\n    2- Supprimer une personne");
	printf("\n    3- Mise a jour d'une personne");
	printf("\n    4- Imprimer les donnees");
	printf("\n    0- Quitter\n\n");
}

int ajouterPersonne(){
	struct Personne p;
	printf("\n  Nom = ");            scanf("%s",&p.nom[0]);
	printf("  Prenom = ");           scanf("%s",&p.prenom[0]);
	printf("  Sexe = ");             scanf("%s",p.sexe); //scanf("%s",&p.sexe[0]); 
	printf("  Nombre d enfants = "); scanf("%d",&p.nbr_enfant);
	int n = p.nbr_enfant;
	if(n > 0){
		int i = 0;
		p.enfants = (char**)malloc(n * sizeof(char*));
		while(i < n){
			printf("Entrer l'id du %deme enfant : ",i);
			scanf("%s",p.enfants[i]);
			i++;
		}
	}
	printf("  ID = "); scanf("%s",p.id);
	struct Personne* tmp = &A;
	while(tmp->suivant != NULL){
		tmp = tmp->suivant;
	}
	tmp->suivant = &p;
	p.suivant = NULL;
	return 1;
}

int supprimerPersonne(char* p_nom){
	struct Personne* tmp = &A;
	while((tmp->suivant->nom != p_nom) && (tmp->suivant != NULL)){
		tmp = tmp->suivant;
	}
	struct Personne* supp = tmp;
	tmp->suivant = tmp->suivant->suivant;
	free(tmp);
	return 1;
}

