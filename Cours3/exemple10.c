
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Lire des paramètres sur la ligne de commande.
*/

int lopt(char* argv[], const char* name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

char* lopts(char* argv[], const char* name, char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

int main(int argc, char* argv[])
{
    int val = lopt(argv, "-a", 1);
    char* str = lopts(argv, "-s", "toto");
     
    printf("Valeur passée après -a = %d\n", val);
    printf("Valeur passée après -s = %s\n", str);
   
    return 0;
}
