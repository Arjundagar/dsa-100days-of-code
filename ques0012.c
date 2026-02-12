#include <stdio.h>

int main()
{
    int m, n;
    int a[100][100];
    int i, j;
    int flag = 1;

    scanf("%d %d", &m, &n);

    
    if (m != n)
    {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != a[j][i])
             {
                flag = 0;
                break;
            }
        }
    }

    if (flag == 1)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
