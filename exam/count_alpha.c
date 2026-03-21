/*
Assignment name  : count_alpha
Expected files   : count_alpha.c
Allowed functions: write, printf
--------------------------------------------------------------------------------

Write a program called count_alpha that takes a string and displays the number
of occurences of its alphabetical characters. Other characters are not counted.
The order is the order of occurence in the string. The display must be ended by
a newline.

The format is in the examples.

If the number of arguments is not 1, display only a newline.

Examples :
$> ./count_alpha abbcc
1a, 2b, 2c
$> ./count_alpha "abbcc"
1a, 2b, 2c
$> ./count_alpha "abbcc" "dddeef" | cat -e
$
$> ./count_alpha "My Hyze 47y 7." | cat -e
1m, 3y, 1h, 1z, 1e$
$> ./count_alpha "" | cat -e
$
*/

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int     i = 0;
    int     j = 0;
    int     k = 0;
    char    *str = argv[1];
    char    alpha[27] = {0};
    int     count[27] = {0};

    if (argc != 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    while (str[i])
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            j = 0;
            while (alpha[j])
            {
                if (alpha[j] == str[i] || alpha[j] == str[i] + 32)
                {
                    count[j]++;
                    j = -1;
                    break ;
                }
                j++;
            }
            if (j != -1)
            {
                if (str[i] >= 'A' && str[i] <= 'Z')
                    alpha[k] = str[i] + 32;
                else
                    alpha[k] = str[i];
                count[k]++;
                k++;
            }
        }
        i++;
    }
    k = 0;
    while (count[k])
    {
        printf("%d%c", count[k], alpha[k]);
        if (count[k + 1])
            printf(", ");
        k++;
    }
    printf("\n");
    return 0;
}