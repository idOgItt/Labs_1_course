#include <stdio.h>

typedef enum _kDir {
    LEFT = 0,
    UP,
    RIGHT,
    DOWN
} kDir;

int main(void) {
    const int N = 7;
    int n, m, k;
    kDir dir;

    while (1) {
        printf("Введите n и m (1 - %d, Завершить - 0): ", N);
        scanf("%d", &m);
        scanf("%d", &n);

        if (n == 0 || m == 0)
            break;

        if (n < 1 || n > N || m < 1 || m > N) {
            printf("Недопустимое значение n или m\n");
            continue;
        }

        int a[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", (*(a + i) + j));
            }
        }

        printf("Исходная матрица:\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", *(*(a + i) + j));
            }
            printf("\n");
        }

        dir = RIGHT;
        int *ptr = *a;

        printf("Линейный вид: ");

        int left = 0, right = m - 1, top = 0, bottom = n - 1;

        while (left <= right && top <= bottom) {
            if (dir == LEFT) {
                for (int i = right; i >= left; i--) {
                    printf("%d ", *(*(a + bottom) + i));
                }
                bottom--;
                dir = UP;
            } else if (dir == UP) {
                for (int i = bottom; i >= top; i--) {
                    printf("%d ", *(*(a + i) + left));
                }
                left++;
                dir = RIGHT;
            } else if (dir == RIGHT) {
                for (int i = left; i <= right; i++) {
                    printf("%d ", *(*(a + top) + i));
                }
                top++;
                dir = DOWN;
            } else if (dir == DOWN) {
                for (int i = top; i <= bottom; i++) {
                    printf("%d ", *(*(a + i) + right));
                }
                right--;
                dir = LEFT;
            }
        }

        printf("\n");
    }

    return 0;
}
