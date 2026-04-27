#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long left = 0, right = n;
    long long ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (mid <= n / mid) {   // mid*mid <= n (safe check)
            ans = mid;          // store possible answer
            left = mid + 1;     // try for bigger value
        } else {
            right = mid - 1;    // go smaller
        }
    }

    printf("%lld\n", ans);

    return 0;
}