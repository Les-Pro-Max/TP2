#include <stdio.h>
#include <stdlib.h>

// création des types
typedef struct Element {
    int valeur;
    struct Element *suivant;
    struct Element *precedent;
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
    nouveau->precedent = NULL;

    if (liste->premier != NULL) {
        liste->premier->precedent = nouveau;
    }

    liste->premier = nouveau;
}

// affichage de la liste
void affichage_liste(Liste *liste) {
    Element *actuel = liste->premier;
    while (actuel != NULL) {
        printf("%d <-> ", actuel->valeur);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

// insertion triée d'un nouvel élément
void inserer_element(Liste *liste, int new) {
    Element *nouveau = malloc(sizeof(*nouveau));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    nouveau->valeur = new;
    nouveau->suivant = NULL;
    nouveau->precedent = NULL;

    // Cas où la liste est vide 
    if (liste->premier == NULL || liste->premier->valeur >= new) {
        nouveau->suivant = liste->premier;
        if (liste->premier != NULL) {
            liste->premier->precedent = nouveau;
        }
        liste->premier = nouveau;
        return;
    }

    Element *actuel = liste->premier;
    while (actuel->suivant != NULL && actuel->suivant->valeur < new) {
        actuel = actuel->suivant;
    }

    nouveau->suivant = actuel->suivant;
    nouveau->precedent = actuel;

    if (actuel->suivant != NULL) {
        actuel->suivant->precedent = nouveau;
    }
    actuel->suivant = nouveau;
}

int main() {
    int n, val, new;
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

    printf("Entrer la valeur à ajouter dans la liste: ");
    scanf("%d", &new);

    inserer_element(liste1, new);

    printf("Liste après insertion du nouvel élément: ");
    affichage_liste(liste1);

    return 0;
}