
#include <stdio.h>
#include <math.h>

void somme()
{
    int table[10] = { 1, 23, 67, 100, 56, 29, 0, 7, 234, 10 };
    int somme = 0;
    
    int i;
    for (i = 0; i < 10; i++) {
        somme = somme + table[i];
    }
    printf("La somme est = %d\n", somme);
}

void moyenne()
{
    float table[10] = { 1, 23, 67, 100, 56.6f, 29, 0, 7, 234, 10 };
    float somme = 0;
    
    int i;
    for (i = 0; i < 10; i++) {
        somme = somme + table[i];
    }
    printf("La moyenne est = %f\n", somme/10.f);
}

void min_max()
{
   int table[10] = { 1, 23, 67, 100, 56, 29, -8, 7, 234, 10 };
   
    int min = table[0];
    int max = table[0];
    
    int i;
    for (i = 0; i < 10; i++) {
        if (table[i] < min) {
            min = table[i];
        }
        if (table[i] > max) {
            max = table[i];
        }
    }
    
    printf("La valeur minimum est = %d\n", min);
    printf("La valeur maximum est = %d\n", max);
}
  
int main()
{
    somme();
    moyenne();
    min_max();
}
