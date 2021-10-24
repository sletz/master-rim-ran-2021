
// Code pour calculer un pan d'1 entrée audio vers 2 sortie audio

float left = (1.f - sqrt(pan)) * in;
float right = sqrt(pan) * in;
