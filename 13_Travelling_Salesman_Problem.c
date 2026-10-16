#include <stdio.h>

#define INF 1e9

int n;
int cost[20][20];
int dp[1 << 16][16];

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Bitmask DP function for Traveling Salesman Problem
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        if (cost[pos][0] != -1)
            return cost[pos][0];
        return INF;
    }

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            if (cost[pos][city] != -1) {
                int newCost = cost[pos][city] + tsp(mask | (1 << city), city);
                ans = min(ans, newCost);
            }
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize DP array with -1
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    // Start traversal from city 0 with mask 1 (00...001)
    int result = tsp(1, 0);

    if (result >= INF) {
        printf("-1\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}
