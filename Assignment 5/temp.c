#include <stdio.h>

int main()
{

    int min, max, n;

    scanf("%d", &n);

    int arr[n];

    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (arr[i + 1] > arr[i])
        {
            return arr[i + 1];
        }
    }

    return 0;
}