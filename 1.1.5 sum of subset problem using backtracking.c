#include <stdio.h>
        return;
    }

    // Choice 1: Include the current element
    current_subset[current_size] = set[index];
    find_subsets(set, n, target_sum, index + 1, current_sum + set[index], current_subset, current_size + 1);

    // Choice 2: Exclude the current element (Backtrack)
    find_subsets(set, n, target_sum, index + 1, current_sum, current_subset, current_size);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *set = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &set[i]) != 1) return 0;
    }

    int target_sum;
    if (scanf("%d", &target_sum) != 1) return 0;

    // Allocate memory for tracking results
    discovered_subsets = (int **)malloc(max_subsets * sizeof(int *));
    subset_sizes = (int *)malloc(max_subsets * sizeof(int));
    int *current_subset = (int *)malloc(n * sizeof(int));

    // Run the backtracking algorithm
    find_subsets(set, n, target_sum, 0, 0, current_subset, 0);

    // Output formatting
    if (subset_count == 0) {
        printf("-1\n");
    } else {
        // Print in reverse order of discovery (last found -> printed first)
        for (int i = subset_count - 1; i >= 0; i--) {
            for (int j = 0; j < subset_sizes[i]; j++) {
                printf("%d", discovered_subsets[i][j]);
                if (j < subset_sizes[i] - 1) {
                    printf(" ");
                }
            }
            printf(" \n");
            free(discovered_subsets[i]); // Free individual subset memory
        }
    }

    // Clean up allocated memory
    free(discovered_subsets);
    free(subset_sizes);
    free(current_subset);
    free(set);

    return 0;
}

