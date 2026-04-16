#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, max_len = 0;

    // Hash map simulation
    int hash[2 * MAX + 1];
    for(int i = 0; i < 2 * MAX + 1; i++) {
        hash[i] = -1;
    }

    int offset = MAX; // to handle negative sums

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum = 0
        if(sum == 0) {
            max_len = i + 1;
        }

        // Case 2: sum seen before
        if(hash[sum + offset] != -1) {
            int len = i - hash[sum + offset];
            if(len > max_len) {
                max_len = len;
            }
        } else {
            // store first occurrence
            hash[sum + offset] = i;
        }
    }

    printf("%d\n", max_len);

    return 0;
}