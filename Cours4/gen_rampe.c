
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* Generateur de rampe */

float* table_rampe;
int table_size_rampe;
int phase_rampe;

/* Création et remplissage de la table avec un période du signal */
void init_rampe(int sample_rate, int freq)
{
    table_size_rampe = (int)((float)sample_rate / (float)freq);
    
    /* Alloue dynamiquement une table. */
    table_rampe = (float*)malloc(table_size_rampe * sizeof(float));
    
    /* Remplit la table */
    int i;
    for (i = 0; i < table_size_rampe; i++) {
        table_rampe[i] = (float)i / (float)table_size_rampe;
    }

    /* Initialise la phase */
    phase_rampe = 0;
}

void destroy_rampe()
{
    /* Desalloue le tableau. */
    free(table_rampe);
}

/* Copie 'nframes' échantillons de la table dans le buffer output et gestion de la phase */
void process_rampe(float* output, int nframes)
{
    int i;
    for (i = 0 ; i < nframes; i++) {
        output[i] = table_rampe[phase_rampe];
        phase_rampe = phase_rampe + 1;
        if (phase_rampe == table_size_rampe) {
            phase_rampe = 0;
        }
    }
}

/* Retourne 1 echantillon et gestion de la phase */
float process_one_sample_rampe()
{
    float sample = table_rampe[phase_rampe];
    phase_rampe = phase_rampe + 1;
    if (phase_rampe == table_size_rampe) {
        phase_rampe = 0;
    }
    return sample;
}

void display_table()
{
    int i;
    for (i = 0 ; i < table_size_rampe; i++) {
        printf("Sample : %f\n", table_rampe[i]);
    }
}

// Simulation en utilisant la fonctioon qui produit un échantillan à chaque appel
void simulate()
{
    printf("===== Simule la production de 256 échantillons =====\n");
    for (int i = 0; i < 256; i++) {
        printf("Sample : %f\n", process_one_sample_rampe());
    }
}

// Simulation par blocs
void simulate2(int nb_block, int block_size)
{
    printf("===== Simule la production de %d blocks de %d échantillons =====\n",
           nb_block, block_size);
    
    // Block de sortie
    float output[block_size];
    
    // Simule la production de 'nb_block' blocks
    for (int block = 0; block < nb_block; block = block + 1) {
        
        // Remplit 1 block (= buffer) audio
        process_rampe(output, block_size);
        
        // Imprime le block
        printf("Block %d\n", block);
        for (int i = 0; i < block_size; i++) {
            printf("Sample : %f\n", output[i]);
        }
    }
}

// Simulation sur deux blocs
void simulate3()
{
    printf("===== Simule la production de 2 blocks de 128 échantillons =====\n");
    
    // Block de sortie
    float output[128];
    
    // Remplit 1 block (= buffer) audio
    process_rampe(output, 128);
    
    // Imprime le block
    for (int i = 0; i < 128; i++) {
        printf("Sample : %f\n", output[i]);
    }
    
    // Remplit 1 block (= buffer) audio
    process_rampe(output, 128);
    
    // Imprime le block
    for (int i = 0; i < 128; i++) {
        printf("Sample : %f\n", output[i]);
    }
}

int main()
{
    init_rampe(44100, 500);
    display_table();
    //simulate();
    //simulate2(10, 16);
    simulate3();
    destroy_rampe();
    return 0;
}
