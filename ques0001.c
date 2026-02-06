#include <stdio.h>

int main() {
    int n, pos, x;
    int a[100];   // assuming max size

    // Read number of elements
    scanf("%d", &n);

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Read position (1-based)
    scanf("%d", &pos);

    // Read element to insert
    scanf("%d", &x);

    // Shift elements to the right
    for(int i = n; i >= pos; i--) {
        a[i] = a[i - 1];
    }

    // Insert element
    a[pos - 1] = x;

    // Print updated array
    for(int i = 0; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
