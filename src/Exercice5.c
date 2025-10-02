#include <stdio.h>
#include <stdlib.h>

// Définition d’un nœud de liste doublement chaînée circulaire
typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

// Fonction pour créer un nouveau nœud
DNode* newDNode(int value) {
    DNode* n = (DNode*)malloc(sizeof(DNode));
    n->data = value;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

// Insertion en tête
void insertHeadDCircular(DNode** head, int value) {
    DNode* n = newDNode(value);

    if (*head == NULL) {  
        // Liste vide → le nœud pointe sur lui-même
        *head = n;
        n->next = n;
        n->prev = n;
    } else {
        DNode* last = (*head)->prev;  // dernier nœud
        n->next = *head;
        n->prev = last;
        last->next = n;
        (*head)->prev = n;
        *head = n;  // mise à jour de la tête
    }
}

// Insertion en queue
void insertTailDCircular(DNode** head, int value) {
    DNode* n = newDNode(value);

    if (*head == NULL) {
        *head = n;
        n->next = n;
        n->prev = n;
    } else {
        DNode* last = (*head)->prev;
        n->next = *head;
        n->prev = last;
        last->next = n;
        (*head)->prev = n;
    }
}

// Affichage de la liste (dans le sens direct)
void printList(DNode* head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }
    DNode* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Programme principal pour tester
int main() {
    DNode* head = NULL;

    insertHeadDCircular(&head, 10);
    insertHeadDCircular(&head, 20);
    insertTailDCircular(&head, 30);
    insertTailDCircular(&head, 40);

    printf("Liste circulaire doublement chaînée : ");
    printList(head);

    return 0;
}
