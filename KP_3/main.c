#include <stdio.h>
#include <math.h>

long double machine_epsilon(long double x)
{
    long double e = 1.0L;
    while (x + e / 2.0L > x)
        e /= 2.0L;
    return e;
}

int main()
{
    printf("Введите значение x: ");
    long double x;
    scanf("%Lf", &x);

	int n;
    printf("Введите количество равных разбиений отрезка [a, b]: n = ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Введенное значение должно быть больше нуля!\n");
        return 0;
    }

    long double e0 = machine_epsilon(x);
    printf("Машинное эпсилон для x = %.10Le: e = %.10Le\n", x, e0);

    printf("+-------------------------------------------------------------------------------------------------------+\n");
    printf("|            Таблица значений ряда Тейлора и стандартной функции для f(x) = exp(pow(x, 2))              |\n");
    printf("+-------+-----------------------------------------+-----------------------------------+-----------------+\n");
    printf("|   x   | частичная сумма ряда для exp(pow(x, 2)) |      значение функции f(x)        | число итераций  |\n");
    printf("+-------+-----------------------------------------+-----------------------------------+-----------------+\n");


    long double d = 1.0L / (long double)n;

    long double x_value = 0.0L;
    for (int i = 0; i <= n; i++) {
        x_value = d * i;
        long double math_func = expl(x_value * x_value);

        long double res = 1.0L;
        long double term = 1.0L;
        int n1 = 0;

        while (fabsl(term) > e0) {
            term *= x_value * x_value / (n1 + 1);
            res += term;

            n1++;
        }

        printf("| %.3Lf\t|     %.19Le           |     %.19Le     |     %d          |\n", x_value, res, math_func, n1);
    }

    printf("+-------+-----------------------------------------+-----------------------------------+-----------------+\n");
    return 0;
}
