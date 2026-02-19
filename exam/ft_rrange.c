#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int i = 0;
    int range;
    int *res;

    if (start > end)
        range = start - end + 1;
    else
        range = end - start + 1;
    res = malloc(sizeof(int) * (range));
    if (!res)
        return (0);
    while (range > 0)
    {
        if (start > end)
            res[range - 1] = start--;
        else
            res[range - 1] = start++;
        range--;
    }
    return (res);
}