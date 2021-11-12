
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void square()
{
    float table[20];
    int i;
    
    for (i = 0; i < 10; i++) {
        table[i] = -1;
    }
    
    for (i = 10; i < 20; i++) {
        table[i] = 1;
    }
    
    printf("======= square =======\n");
    for (i = 0; i < 20; i = i+1) {
        printf("Sample %d = value = %f\n", i, table[i]);
    }
}

void square2()
{
    float table[20];
    int i;
    
    for (i = 0; i < 20; i++) {
        if (i < 10) {
            table[i] = -1;
        } else {
            table[i] = 1;
        }
    }
    
    printf("======= square2 =======\n");
    for (i = 0; i < 20; i = i+1) {
        printf("Sample %d = value = %f\n", i, table[i]);
    }
}


#define SIZE 128

void sinus()
{
    float table[SIZE];
    int i;
    
    for (i = 0; i < SIZE; i = i+1) {
        table[i] = sin(2 * M_PI * (float)i/((float)SIZE - 1));
    }
    
    printf("======= sinus =======\n");
    for (i = 0; i < SIZE; i = i+1) {
        printf("Sample %d = value = %f\n", i, table[i]);
    }
}

// Table sur range [0..1]
void rampe()
{
    float table[SIZE];
    int i;
    
    for (i = 0; i < SIZE; i = i+1) {
        table[i] = (float)i/((float)SIZE - 1);
    }
    
    printf("======= rampe ======= \n");
    for (i = 0; i < SIZE; i = i+1) {
        printf("Sample %d = value = %f\n", i, table[i]);
    }
}

// Table sur range [-1..1]
void rampe2()
{
    float table[SIZE];
    int i;
     
    // Crée la table de [0..1]
    for (i = 0; i < SIZE; i = i+1) {
        table[i] = (float)i/((float)SIZE - 1);
    }
    
    // Transforme la table précédente dans le range [-1..1]
    for (i = 0; i < SIZE; i = i+1) {
        table[i] = table[i] * 2.0f - 1.0f;
    }
    
    printf("======= rampe2 ======= \n");
    for (i = 0; i < SIZE; i = i+1) {
        printf("Sample %d = value = %f\n", i, table[i]);
    }
}


int main()
{
    square();
    square2();
    sinus();
    rampe();
    rampe2();
    
    return 0;
}
