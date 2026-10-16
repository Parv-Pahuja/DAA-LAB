#include <stdio.h>

void findSubsets(int *set, int n, int target, int index, int currentSum, int *currentSubset, int subsetSize) {
    if (currentSum == target) {
        saveSubset(currentSubset, subsetSize);
        return;
    }

    if (index == n || currentSum > target) {
        return;
    }

    currentSubset[subsetSize] = set[index];
    findSubsets(set, n, target, index + 1, currentSum + set[index], currentSubset, subsetSize + 1);

    findSubsets(set, n, target, index + 1, currentSum, currentSubset, subsetSize);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *set = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &set[i]) != 1) return 0;
    }

    int target;
    if (scanf("%d", &target) != 1) return 0;

    int *currentSubset = (int *)malloc(n * sizeof(int));

    findSubsets(set, n, target, 0, 0, currentSubset, 0);

    if (subsetCount == 0) {
        printf("-1\n");
    } else {
        for (int i = subsetCount - 1; i >= 0; i--) {
            for (int j = 0; j < discoveredSubsets[i].size; j++) {
                printf("%d ", discoveredSubsets[i].data[j]); 
            }
            printf("\n");
            free(discoveredSubsets[i].data);
        }
    }

    free(set);
    free(currentSubset);
    if (discoveredSubsets != NULL) {
        free(discoveredSubsets);
    }

    return 0;
}
