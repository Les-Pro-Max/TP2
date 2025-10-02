#include <stdio.h>
#include <stdlib.h>

// Structure du nœud de la liste circulaire
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure de la liste circulaire
typedef struct {
    Node* head;
    int size;
} CircularList;

// Fonction pour créer une nouvelle liste circulaire
CircularList* createList() {
    CircularList* list = (CircularList*)malloc(sizeof(CircularList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Fonction pour créer un nouveau nœud
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour insérer un élément en tête de la liste circulaire
void insertAtHead(CircularList* list, int data) {
    Node* newNode = createNode(data);
    
    if (list->head == NULL) {
        // Liste vide : le nouveau nœud pointe vers lui-même
        list->head = newNode;
        newNode->next = newNode;
    } else {
        // Trouver le dernier nœud (celui qui pointe vers head)
        Node* last = list->head;
        while (last->next != list->head) {
            last = last->next;
        }
        
        // Insérer le nouveau nœud en tête
        newNode->next = list->head;
        last->next = newNode;
        list->head = newNode;
    }
    
    list->size++;
    printf("Élément %d inséré en tête\n", data);
}

// Fonction pour insérer un élément en queue de la liste circulaire
void insertAtTail(CircularList* list, int data) {
    Node* newNode = createNode(data);
    
    if (list->head == NULL) {
        // Liste vide : le nouveau nœud pointe vers lui-même
        list->head = newNode;
        newNode->next = newNode;
    } else {
        // Trouver le dernier nœud (celui qui pointe vers head)
        Node* last = list->head;
        while (last->next != list->head) {
            last = last->next;
        }
        
        // Insérer le nouveau nœud en queue
        last->next = newNode;
        newNode->next = list->head;
    }
    
    list->size++;
    printf("Élément %d inséré en queue\n", data);
}

// Fonction pour afficher la liste circulaire
void displayList(CircularList* list) {
    if (list->head == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    Node* current = list->head;
    printf("Liste circulaire : ");
    
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);
    
    printf("(taille: %d)\n", list->size);
}

// Fonction pour libérer la mémoire de la liste
void freeList(CircularList* list) {
    if (list->head == NULL) {
        free(list);
        return;
    }
    
    Node* current = list->head;
    Node* next;
    
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != list->head);
    
    free(list);
}

// Fonction principale pour tester les opérations
int main() {
    CircularList* list = createList();
    
    printf("=== Test d'insertion en tête et en queue dans une liste circulaire ===\n\n");
    
    // Test d'insertion en tête
    printf("1. Insertions en tête :\n");
    insertAtHead(list, 10);
    displayList(list);
    
    insertAtHead(list, 20);
    displayList(list);
    
    insertAtHead(list, 30);
    displayList(list);
    
    printf("\n2. Insertions en queue :\n");
    insertAtTail(list, 40);
    displayList(list);
    
    insertAtTail(list, 50);
    displayList(list);
    
    insertAtTail(list, 60);
    displayList(list);
    
    printf("\n3. Mélange d'insertions :\n");
    insertAtHead(list, 5);
    displayList(list);
    
    insertAtTail(list, 70);
    displayList(list);
    
    insertAtHead(list, 1);
    displayList(list);
    
    // Vérification que la liste est bien circulaire
    printf("\n4. Vérification de la circularité :\n");
    if (list->head != NULL) {
        Node* current = list->head;
        printf("Parcours de 15 éléments (plus que la taille) : ");
        for (int i = 0; i < 15; i++) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
    
    // Libération de la mémoire
    freeList(list);
    
    return 0;
}