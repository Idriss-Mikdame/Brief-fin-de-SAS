#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// Définition de la structure Tache
typedef struct{
    char titre[500]; // Définition de la structure Tache
    char description[500]; // Description detaille de la tache
    char priorite[40]; // Priorité de la tâche (High/Low)
    char date_echeance[20]; // Date d'échéance de la tâche (format dd/mm/aa)
}Tache;
// Variables globales
int n = 0; // Nombre actuel de tâches
Tache taches[100]; // Tableau pour stocker jusqu'à 100 tâches
/*Fonction d'ajoute */
 void ajout_tache(){
    if(n>=100){ // Vérifie si la limite de 100 tâches est atteinte
        printf("les lists de tache max");
    } // Saisie des informations de la tâche
        printf("la taches NR°%d\n",n+1);
        printf("Taper le titre de tache : ");
        scanf(" %[^\n]",taches[n].titre);
        printf("Taper la description de la tache : ");
        scanf(" %[^\n]",taches[n].description);
        printf("Taper la date d'échéance (dd/mm/aa) : ");
        scanf("%s",taches[n].date_echeance);
        printf("Taper la priorite de la tache (1. High / 2. Low) : ");
        scanf("%s",taches[n].priorite);
        n++;// Incrémente le nombre de tâches

}
// Fonction pour afficher toutes les tâches
void afficherTaches(){
    if(n < 1){// Vérifie s'il y a des tâches à afficher
        printf("Exist aucun tache a afficher \n");
        printf("Merci de cree des taches dans option 1 \n");
        }
       else {
for(int i=0;i < n;i++){// Affichage des informations de chaque tâche
        printf("l'affichage des informations des taches N-%d\n",i+1);
        printf("Titre de la tache           -> %s\n",taches[i].titre);
        printf("La description  de la tache -> %s\n",taches[i].description);
        printf("La date d'echeance la tache -> %s\n",taches[i].date_echeance);
        printf("La priorite de la tache     -> %s\n",taches[i].priorite);
    }}}

// Fonction principale pour afficher le menu et exécuter les options
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
