#include <stdio.h>

int main()
{
    int r, c;
    int a[100][100];
    int i;

    scanf("%d %d", &r, &c);

    for(i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while(top <= bottom && left <= right)
    {
        // Top row
        for(i = left; i <= right; i++)
            printf("%d ", a[top][i]);
        top++;

        // Right column
        for(i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;

        // Bottom row
        if(top <= bottom)
        {
            for(i = right; i >= left; i--)
                printf("%d ", a[bottom][i]);
            bottom--;
        }

        // Left column
        if(left <= right)
        {
            for(i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }

    return 0;
}
