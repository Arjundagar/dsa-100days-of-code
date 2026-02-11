#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int start, end, flag = 1;

    scanf("%s", s);

    start = 0;
    end = strlen(s) - 1;

    while (start < end)
    {
        if (s[start] != s[end])
        {
            flag = 0;
            break;
        }
        start++;
        end--;
    }

    if (flag == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}
