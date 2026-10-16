#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1, c1, r2, c2;

    if (scanf("%d %d", &r1, &c1) != 2) return 0;

    int **A = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        A[i] = (int *)malloc(c1 * sizeof(int));
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    if (scanf("%d %d", &r2, &c2) != 2) return 0;

    if (c1 != r2) {
        printf("Invalid input\n");
        for (int i = 0; i < r1; i++) free(A[i]);
        free(A);
        return 0;
    }

    int **B = (int **)malloc(r2 * sizeof(int *));
    for (int i = 0; i < r2; i++) {
        B[i] = (int *)malloc(c2 * sizeof(int));
        for (int j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int **res = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        res[i] = (int *)calloc(c2, sizeof(int));
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r1; i++) free(A[i]);
    free(A);
    for (int i = 0; i < r2; i++) free(B[i]);
    free(B);
    for (int i = 0; i < r1; i++) free(res[i]);
    free(res);

    return 0;
}
