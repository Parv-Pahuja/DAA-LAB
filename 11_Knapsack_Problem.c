#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N, W;

    if (scanf("%d", &N) != 1) return 0;

    int values[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &values[i]);
    }

    int weights[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &weights[i]);
    }

    if (scanf("%d", &W) != 1) return 0;

    int dp[W + 1];
    for (int w = 0; w <= W; w++) {
        dp[w] = 0;
    }

    for (int i = 0; i < N; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    printf("%d\n", dp[W]);

    return 0;
}
