#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, q;

    // Input table size
    scanf("%d", &m);

    int hash[m];

    // Initialize hash table
    for (int i = 0; i < m; i++) {
        hash[i] = EMPTY;
    }

    // Number of queries
    scanf("%d", &q);

    while (q--) {
        char operation[10];
        int key;
        scanf("%s %d", operation, &key);

        int h = key % m;

        if (strcmp(operation, "INSERT") == 0) {
            int i = 0;
            int index;

            // Quadratic probing
            while (i < m) {
                index = (h + i * i) % m;

                if (hash[index] == EMPTY) {
                    hash[index] = key;
                    break;
                }
                i++;
            }

        } else if (strcmp(operation, "SEARCH") == 0) {
            int i = 0;
            int index;
            int found = 0;

            while (i < m) {
                index = (h + i * i) % m;

                if (hash[index] == key) {
                    found = 1;
                    break;
                }

                if (hash[index] == EMPTY) {
                    break;  // Stop if empty slot found
                }

                i++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}