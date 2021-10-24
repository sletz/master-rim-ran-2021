 
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* Generateur sinus */

float* table_sinus;
int table_size_sinus;
int phase_sinus;

/* Création et remplissage de la table avec un période du signal */
void init_sinus(int sample_rate, int freq)
{
    table_size_sinus = (int)((float)sample_rate / (float)freq);
    
    /* Alloue dynamiquement une table. */
    table_sinus = (float*)malloc(table_size_sinus * sizeof(float));
    
    /* Remplit la table */
    // A COMPLETER
    
    /* Initialise la phase */
    phase_sinus = 0;
}

void destroy_sinus()
{
    /* Desalloue le tableau. */
    free(table_sinus);
}

/* Copie 'nframes' echantillons de la table dans le buffer output et gestion de la phase */
void process_sinus(float* output, int nframes)
{
    int i;
    for (i = 0 ; i < nframes; i++) {
        // A COMPLETER
    }
}

/* Retourne 1 echantillon et gestion de la phase */
float process_one_sample_sinus()
{
    // A COMPLETER
}

void display_table()
{
    // A COMPLETER
}

int main()
{
    // A COMPLETER
}
