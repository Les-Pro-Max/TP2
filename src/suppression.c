#include<stdio.h>
#include <stdlib.h>

// création des types
typedef struct Element {
    int valeur;
    struct Element *suivant;
} Element;

typedef struct Liste {
    struct Element *premier;
} Liste;

// initialisation
Liste *initialisation() {
    Liste *liste = malloc(sizeof(*liste));
    if (liste == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    liste->premier = NULL;
    return liste;
}

// insertion en tête
void insere_tete(Liste *liste, int val) {
    Element *nouveau = malloc(sizeof(*nouveau));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    nouveau->valeur = val;
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

// affichage de la liste
void affichage_liste(Liste *liste) {
    Element *actuel = liste->premier;
    while (actuel != NULL) {
        printf("%d->", actuel->valeur);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}


typedef struct Liste {
    struct Element *premier;
} Liste;

// initialisation
Liste *initialisation() {
    Liste *liste = malloc(sizeof(*liste));
    if (liste == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    liste->premier = NULL;
    return liste;
}

// insertion en tête
void insere_tete(Liste *liste, int val) {
    Element *nouveau = malloc(sizeof(*nouveau));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    nouveau->valeur = val;
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

// affichage de la liste
void affichage_liste(Liste *liste) {
    Element *actuel = liste->premier;
    while (actuel != NULL) {
        printf("%d->", actuel->valeur);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

// suppression de toutes les occurrences de la valeur que va entrer l'utilisateur
void suppress_occur(Liste *liste, int nbr) {
    Element *actuel = liste->premier;
    Element *precedent = NULL;
    while (actuel != NULL) {
        if (actuel->valeur == nbr) {
            // suppression de l'élément
            if (precedent == NULL) {
                // cas où l’élément est en tête
                liste->premier = actuel->suivant;
                free(actuel);
                actuel = liste->premier;
            } else {
                precedent->suivant = actuel->suivant;
                free(actuel);
                actuel = precedent->suivant;
            }
        } else {
            precedent = actuel;
            actuel = actuel->suivant;
        }
    }

}

int main() {
    int n, val, nbr;
    Liste *liste1 = initialisation();

    printf("Entrer le nombre d'éléments de votre liste: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrer l'élément numero %d: ", i + 1);
        scanf("%d", &val);
        insere_tete(liste1, val);
    }

    printf("Votre liste est: ");
    affichage_liste(liste1);

    printf("Entrer la valeur dont vous voulez supprimer toutes les occurrences: ");
    scanf("%d", &nbr);

    suppress_occur(liste1, nbr);

    printf("Liste après suppression: ");
    affichage_liste(liste1);

    return 0;
}
