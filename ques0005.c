#include <stdio.h>

int main() {
    int p, q;
    int a[100], b[100], c[200];
    int i = 0, j = 0, k = 0;

    // Read size of first log
    scanf("%d", &p);

    // Read first sorted array
    for(i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Read size of second log
    scanf("%d", &q);

    // Read second sorted array
    for(i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    i = 0;
    j = 0;

    // Merge both arrays
    while(i < p && j < q) {
        if(a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    // Copy remaining elements of first array
    while(i < p) {
        c[k++] = a[i++];
    }

    // Copy remaining elements of second array
    while(j < q) {
        c[k++] = b[j++];
    }

    // Print merged array
    for(i = 0; i < k; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
