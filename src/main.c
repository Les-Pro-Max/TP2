#include <stdio.h>

int main() {
    int x = 42;       // Une variable normale
    int* p = &x;      // p est un pointeur vers int, il contient l’adresse de x
    
    printf("Valeur de x : %d\n", x);
    printf("Adresse de x : %p\n", &x);
    printf("Contenu du pointeur p : %p\n", p);
    printf("Valeur pointée par p : %d\n", *p);
    
    return 0;
}
