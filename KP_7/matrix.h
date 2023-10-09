#define MIN_CAP 512

typedef struct {
	int *a;
	int M;
	int N;

	int size;
	int cap;
} matrix;


void videleniye_pamyati ( matrix * m ) {

	m->cap *= 2;
	m->a = (int *)realloc( m->a, m->cap*sizeof(int) );
}

void umensheniye_pamyati ( matrix * m ) {

	m->cap /= 2;
	m->a = (int *)realloc( m->a, m->cap*sizeof(int) );
}


void matrix_str_push ( matrix *m, int a ) {			// добавить в вектор цифру (заполнение)

	if ( m->cap <= m->size )
		videleniye_pamyati ( m );

	m->a[ (m->size)++ ] = a;

}

void matrix_str_pop2 ( matrix *m ) {				// просто убрать два числа с конца вектора

	if ( m->cap > MIN_CAP && m->size*4 < m->cap )
		umensheniye_pamyati ( m );

	m->size -= 1;
}

int matrix_get ( matrix *m, int n ) {				// вернуть значение по позиции в векторе
	return ( n < m->size ) ? m->a[n] : 0;
}

int matrix_get_position ( matrix *m, int M, int N ) {			// вернуть значение из матрицы

	if ( m->M < M || m->N < N )
		return 0;

	int i = 0, st=1, k=0, kk=0;
	while (  kk < m->M  &&  i < m->size  ) {
		switch (st) {
			case 1: {
				while ( k++ < matrix_get( m, i ) )
					if ( (k-1)==M )
						return 0;
				st = 2;
				break;
			}
			case 2: {
				if ( matrix_get( m, i ) == -1 ) {
					if ( (k-1)==M && N<=m->N )
						return 0;
					st = 1;
					kk++;
					break;
				}
				if ( (k-1)==M && matrix_get( m, i++ )==N )
						return matrix_get( m, i );
				break;
			}
		}
		i++;
	}
}



matrix * matrix_create ( int M, int N ) {

	matrix *m;
	m = (matrix *)malloc( sizeof( matrix ) );
	m->a = (int *)malloc( MIN_CAP * sizeof(int) );
	m->size = 0;
	m->cap = MIN_CAP;
	m->M = M;
	m->N = N;

	int i,j,jj,a;

	for (i=0; i<M; i++) {
		matrix_str_push ( m, i );
		j = jj = 0;
		for ( ; j<N; j++) {
			scanf("%d", &a);
			if (a) {
				matrix_str_push ( m, j );
				matrix_str_push ( m, a );
				jj++;
			}
		}
		if (jj)
			matrix_str_push ( m, -1 );
		else
			matrix_str_pop2 (m);
	}

	return m;
}

void print_matrix_str ( matrix *m ) {
	int i=-1;
	printf ("{");
	while ( ++i < m->size )
		printf(" %d", m->a[i]);
	printf (" }\n");
}

void print_matrix ( matrix *m ) {
	int i = 0, st=1, k=0, kk=0, n=0;
	while (  kk < m->M  &&  i < m->size  ) {
		switch (st) {			// 1 - начало новой строки 2 - вывод элементов строки
			case 1: {
				while ( k++ < matrix_get( m, i ) ) {
					n = 0;
					printf ("\n");
					while ( n < m->N ) {
						printf (" 0");
						n++;
					}
				}
				n = 0;
				st = 2;
				printf ("\n");
				break;
			}
			case 2: {
				while ( n < matrix_get( m, i ) && n <= m->N ) {
					printf (" 0");
					n++;
				} n++;
				if ( matrix_get( m, i ) == -1 ) {
					while ( n <= m->N ) {
						printf (" 0");
						n++;
					}
					st = 1;
					kk++;
					break;
				}
				printf (" %d", matrix_get( m, ++i ) );
				break;
			}
		}
		i++;
	}
	printf ("\n");
}

int matrix_XX ( matrix *m1, matrix *m2, int ii, int jj ) {

	int i = 0, st=1, k=0, kk=0, ret = 0;
	while (  kk < m1->M  &&  i < m1->size  ) {
		switch (st) {
			case 1: {
				while ( k++ < matrix_get( m1, i ) ) {}
				st = 2;
				break;
			}
			case 2: {
				if ( matrix_get( m1, i ) == -1 ) {
					st = 1;
					kk++;
					break;
				}
				if ( (k-1)==ii )
					ret += matrix_get( m1, ++i ) * matrix_get_position ( m2, matrix_get( m1, i-1 ), jj );
				break;
			}
		}
		i++;
	}

	return ret;
}

matrix * matrix_X ( matrix *m1, matrix *m2 ) {
	
	if ( m1->N != m2->M )
		return NULL;

	matrix *m;
	m = (matrix *)malloc( sizeof( matrix ) );
	m->a = (int *)malloc( MIN_CAP * sizeof(int) );
	m->size = 0;
	m->cap = MIN_CAP;
	m->M = m1->M;
	m->N = m2->N;

	int i,j,jj,a;

	for (i=0; i < m1->M; i++) {
		matrix_str_push ( m, i );
		for (j=jj=0; j < m2->N; j++) {
			a = matrix_XX ( m1, m2, i, j );
			if (a) {
				matrix_str_push ( m, j );
				matrix_str_push ( m, a );
				jj++;
			}
		}
		if (jj)
			matrix_str_push ( m, -1 );
		else
			matrix_str_pop2 (m);
	}

	return m;

}

int sadaniye ( matrix *m ) {

	int i = 0, st=1, k=0, kk=0, ret = 0;
	while (  kk < m->M  &&  i < m->size  ) {
		switch (st) {
			case 1: {
				k = matrix_get( m, i );
				st = 2;
				break;
			}
			case 2: {
				if ( matrix_get( m, i ) == -1 ) {
					st = 1;
					kk++;
					ret++;
					break;
				}
				i++;
				break;
			}
		}
		i++;
	}

	return ret;

}

/*

1 2 3   4 3 2 1
2 3 4   3 2 1 4
3 4 1   2 1 4 3


*/
