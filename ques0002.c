#include <stdio.h>

int main() {
    int n, pos;
    int a[100];   // assuming max size

    // Read number of elements
    scanf("%d", &n);

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Read position to delete (1-based)
    scanf("%d", &pos);

    // Shift elements to the left
    for(int i = pos - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    // Print updated array
    for(int i = 0; i < n - 1; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
