// Целый тип ключа. Сортировка пузырьком.
#include <stdio.h>
#include <stdlib.h>
#include"list.h"

int main () {

	elem *t;

	int N, key;
	printf ("Сколько элементов?\n");
	scanf ("%d",&N);

	get_table ( &t, N );
	sort_table ( t, N ); 

	print_table ( t, N );
	printf("Введи значение для поиска: ");
	while ( scanf ("%d", &key) )
		search_table ( t, N, key );
return 0;
}