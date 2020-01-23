#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE 30

typedef struct 
{
	char name[1+NAMESIZE];
	int number;
} fiche;

int compareOnNumbers(const void *p1, const void *p2){
	fiche *e1= (fiche*)p1;
	fiche *e2= (fiche*)p2;
	return e1->number- e2-> number;
}

int compareOnNames(const void *p1, const void *p2){
	fiche *e1= (fiche*)p1;
	fiche *e2= (fiche*)p2;
	return strcmp(e1->name, e2->name);
}

void display(fiche *d, int nb){
	int i;
	for (int i = 0; i < nb; ++i)
	{
		printf("\t %s - %d \n", d[i].name , d[i].number);
	}
}

int main (void){
	fiche directory[]= {
		{"Spirou",1},
		{"Titi",4},
		{"Fantasio",3},
		{"Rominet",8},
		{"Zorglub", 6},
		{"Champignac",6}
	};

	int nb= sizeof(directory)/sizeof(fiche);
	puts("fiches sorted by name: ");
	qsort(directory,nb,sizeof(fiche), compareOnNames);
	display(directory,nb);

}
