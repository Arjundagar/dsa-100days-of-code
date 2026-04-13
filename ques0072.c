#include <stdio.h>

char firstRepeatedChar(char *s) {
    int visited[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (visited[index] == 1) {
            return s[i];  // first repeated character
        }

        visited[index] = 1;
    }

    return '\0'; // no repeated character
}

int main() {
    char s[] = "geeksforgeeks";

    char result = firstRepeatedChar(s);

    if (result == '\0')
        printf("-1\n");
    else
        printf("%c\n", result);

    return 0;
}