#include <stdio.h>

int main() {
    int n, k;
    
    // Input size
    scanf("%d", &n);
    
    int arr[n];
    
    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input k
    scanf("%d", &k);
    
    // Handle case when k > n
    k = k % n;
    
    int temp[n];
    
    // Copy last k elements to beginning
    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }
    
    // Copy remaining elements
    for(int i = 0; i < n - k; i++) {
        temp[k + i] = arr[i];
    }
    
    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    
    return 0;
}