typedef struct {
	int key;
	int val;
} elem;

void sort_table ( elem *a, int N ) {

	int i,j;
	elem c;
	for (i=1; i<N; i++)
		for (j = 0; j<i; j++)
			if ( (a[i]).key < (a[j]).key ) {
				c = (a[j]);
				(a[j]) = (a[i]);
				(a[i]) = c;
			}

}

void get_table ( elem **aa, int N ) {

	int i, a1, a2;

    printf ("Ключ:   Значение:\n");

	*aa = (elem *)malloc( N *sizeof(elem) );
	elem *a = *aa;

	for (i=0; i<N; i++) {
		scanf ("%d\t%d", &a1, &a2);
		a[i].key = a1;
		a[i].val = a2;
	}
	
}

void print_table ( elem *a, int N ) {

	int i;
	printf ("Таблица:\n");
	printf ("Ключ:   Значение:\n");

	for (i=0; i<N; i++)
		printf ("\n%d\t%d", (a[i]).key, (a[i]).val);

	printf ("\n");
	
}

void search_table ( elem *a, int N, int key ) {

	int i;

	for (i=0; i<N && (a[i]).key<key; i++) {}
	if ( (a[i]).key == key )
		printf (" %d", (a[i]).val);
	else
		printf ("Данный ключ не найден");

	printf ("\nВведи значение: ");
}