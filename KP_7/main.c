#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
// 2/5 Один вектор, Умножить вектор-строку на разреженную матрицу и вычислить количество ненулевых элементов результата.


int main () {

	int i,A[5120], B[5120], M,N;
	printf("Введи размеры матрицы:\n");
	scanf ("%d %d", &M, &N);

	printf("Введи элементы матрицы:\n");
	matrix *m = matrix_create ( M, N );
	printf("Введи элементы вектора:\n");
	matrix *v = matrix_create ( N, 1 );

	printf("Элементы массива представления матрицы:\n  ");
	print_matrix_str ( m );
	printf("Элементы массива представления вектора:\n  ");
	print_matrix_str ( v );

	printf("Матрица:\n");
	print_matrix ( m );
	printf("Вектор:\n");
	print_matrix ( v );

	//printf("\n%d\n", matrix_get_position(m, 1,2) );
	//printf("\n%d\n", matrix_XX(m,v,1,0) );


	matrix *mv = matrix_X ( m, v );
	printf("Элементы массива представления матрицы 2:\n");
	print_matrix_str ( mv );
	printf("Матрица 2:\n  ");
	print_matrix ( mv );
	printf("\nВ произведение матрицы на столбец содержится %d ненулевых элементов\n", sadaniye ( mv ) );

	return 0;
}