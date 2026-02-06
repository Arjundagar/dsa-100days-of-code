#include <stdio.h>

int main() {
    int n;
    int a[100];
    int i, j;

    // Read number of elements
    scanf("%d", &n);

    // Read sorted array
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Remove duplicates
    j = 1;   // index for unique elements

    for(i = 1; i < n; i++) {
        if(a[i] != a[i - 1]) {
            a[j] = a[i];
            j++;
        }
    }

    // Print unique elements
    for(i = 0; i < j; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
