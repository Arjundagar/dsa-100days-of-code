#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long count = 0;
    long long prefix_sum = 0;

    // Using large array for frequency
    int *freq = calloc(2 * MAX + 1, sizeof(int));

    // To handle negative prefix sums
    int offset = MAX;

    // Important: prefix_sum 0 occurs once initially
    freq[offset] = 1;

    for(int i = 0; i < n; i++) {

        prefix_sum += arr[i];

        // If this prefix_sum appeared before,
        // add its frequency to count
        count += freq[prefix_sum + offset];

        // Increase frequency
        freq[prefix_sum + offset]++;
    }

    printf("%lld\n", count);

    free(freq);

    return 0;
}