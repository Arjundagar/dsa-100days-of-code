#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compare for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int min_sum = arr[left] + arr[right];
    int first = arr[left];
    int second = arr[right];

    // Step 2: Two pointer traversal
    while(left < right) {

        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(min_sum)) {
            min_sum = sum;
            first = arr[left];
            second = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", first, second);

    return 0;
}
