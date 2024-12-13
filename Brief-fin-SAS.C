#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// D�finition de la structure Tache
typedef struct{
    char titre[500]; // D�finition de la structure Tache
    char description[500]; // Description detaille de la tache
    char priorite[40]; // Priorit� de la t�che (High/Low)
    char date_echeance[20]; // Date d'�ch�ance de la t�che (format dd/mm/aa)
}Tache;
// Variables globales
int n = 0; // Nombre actuel de t�ches
Tache taches[100]; // Tableau pour stocker jusqu'� 100 t�ches
/*Fonction d'ajoute */
 void ajout_tache(){
    if(n>=100){ // V�rifie si la limite de 100 t�ches est atteinte
        printf("les lists de tache max");
    } // Saisie des informations de la t�che
        printf("la taches NR�%d\n",n+1);
        printf("Taper le titre de tache : ");
        scanf(" %[^\n]",taches[n].titre);
        printf("Taper la description de la tache : ");
        scanf(" %[^\n]",taches[n].description);
        printf("Taper la date d'�ch�ance (dd/mm/aa) : ");
        scanf("%s",taches[n].date_echeance);
        printf("Taper la priorite de la tache (1. High / 2. Low) : ");
        scanf("%s",taches[n].priorite);
        n++;// Incr�mente le nombre de t�ches

}
// Fonction pour afficher toutes les t�ches
void afficherTaches(){
    if(n < 1){// V�rifie s'il y a des t�ches � afficher
        printf("Exist aucun tache a afficher \n");
        printf("Merci de cree des taches dans option 1 \n");
        }
       else {
for(int i=0;i < n;i++){// Affichage des informations de chaque t�che
        printf("l'affichage des informations des taches N-%d\n",i+1);
        printf("Titre de la tache           -> %s\n",taches[i].titre);
        printf("La description  de la tache -> %s\n",taches[i].description);
        printf("La date d'echeance la tache -> %s\n",taches[i].date_echeance);
        printf("La priorite de la tache     -> %s\n",taches[i].priorite);
    }}}
// Fonction pour modifier une t�che existante
void modifierTache(){
     if(n < 1){// V�rifie s'il y a des t�ches � modifier
        printf("Exist aucun tache pour Modifier\n");
        printf("Merci de cree des taches dans option 1 \n");}
       else {
    int nbrM;
    printf("Choisire le NBR de tache pour modifier :");
    scanf("%d",&nbrM);
       if(nbrM < 1 || nbrM > n){// V�rifie si le num�ro de t�che est valide
        printf("le nbr de tache invalide !!!");
       }
       nbrM--;// Convertit en index du tableau
       // Saisie des nouvelles informations pour la t�che
        printf("Ajouter pour modifier la tache N : %d\n",nbrM+1);
        printf("Taper la tache : ");
        scanf(" %[^\n]",taches[nbrM].titre);
        printf("Taper la description de la tache : ");
        scanf(" %[^\n]",taches[nbrM].description);
        printf("Taper la date d'�ch�ance dd/mm/aa : ");
        scanf("%s",taches[nbrM].date_echeance);
        printf("Taper la priorite de la tache : ");
        scanf("%s",taches[nbrM].priorite);
        printf("La modification est succes\n");}}
// Fonction pour supprimer une t�che
void supprimerTache(){
    if(n < 1){ // V�rifie s'il y a des t�ches � supprimer
        printf("Exist aucun tache pour suprimer\n");
        printf("Merci de cree des taches dans option 1 \n");}
       else {
    int nbrS;
    printf("Entre le Nbr de  la tache ete suprimer : ");
    scanf("%d",&nbrS);
    if (nbrS < 1 || nbrS > n )// V�rifie si le num�ro de t�che est valide
    { printf("Le Nbr de la tache invalide !!!");}
    nbrS--;// Convertit en index du tableau
    for (int i = nbrS; i < n - 1;i++){
            taches[i] = taches[ i + 1];
             }
            n--;// R�duit le nombre de t�ches
}}
// Fonction pour filtrer les t�ches par priorit�
void filtrer_tache(){
    char priorite[10];
        if(n < 1){// V�rifie s'il y a des t�ches � filtrer
            printf("Exist aucun tache pour filtrer\n ");
            printf("Merci de cree des taches dans option 1 \n");}
        else {
            printf("Entrez la priorite � filtrer (High/Low) : ");
            scanf("%s",&priorite);

    int touver = 0;// Indique si une t�che correspond � la priorit� donn�e
    for(int i=0;i < n;i++){
        if(strcmp(taches[i].priorite,priorite) == 0)
        {
        touver = 1;
        printf("\nl'affichage des informations des taches N-%d\n",i+1);
        printf("Titre de la tache           -> %s\n",taches[i].titre);
        printf("La description  de la tache -> %s\n",taches[i].description);
        printf("La date d'echeance la tache -> %s\n",taches[i].date_echeance);
        printf("La priorite de la tache     -> %s\n",taches[i].priorite);
        printf("La filtration est succes\n");

        }
    }
    if (touver != 1)
        printf("aucun priorite trouve dans les taches pour %s\n", priorite);
}}
// Fonction principale pour afficher le menu et ex�cuter les options
int main(){
    int choix;
    do{
        printf("----------MENUE----------\n");
        printf("1---> Ajouter une Tache\n");
        printf("2---> Afficher les Taches\n");
        printf("3---> Modifier une Tache\n");
        printf("4---> suprimer une Tache\n");
        printf("5---> filtrer les Taches\n");
        printf("6---> Quitter le programme\n");
        printf("Entrer le choix :");
        scanf("%d",&choix);
        switch(choix){
        case 1: ajout_tache();
            break;
        case 2:
            afficherTaches();
            break;
        case 3:
            modifierTache();
            break;
        case 4:
            supprimerTache();
            break;
        case 5:
            filtrer_tache();
            break;
        case 6:
            printf("BYE!!!!");
            break;

        default:
            printf("choix invalide\n");
            break;
            }
    }while(choix !=6);
    return 0;
}
