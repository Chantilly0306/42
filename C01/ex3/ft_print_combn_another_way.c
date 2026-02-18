#include <unistd.h>

void    print_num(int n, int *tab)
{
    char    c;
    int     i;

    i = 0;
    while (i < n)
    {
        c = '0' + tab[i];
        write(1, &c, 1);
        i++;
    }
    if (tab[0] < 10 - n)
        write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
    int i;
    int tab[10];
    int max[10];

    i = 0;
    while (i < n)
    {
        max[i] = 10 - n + i;
        tab[i + 1] = tab[i] + 1;
        i++;
    }
    print_num(n, tab);
    i = 0;
    while (i < n)
    {
        if (tab[0] == max[0])
            return ;
        if (tab[i] == max[i])
        {
            tab[i - 1]++;
            while (i < n)
                tab[i] = tab[i - 1] + 1;
                i++;
            print_num(n, tab);
            i = 0;
            continue;
        }
        if (i == n - 1)
        {
            tab[i]++;
            print_num(n, tab);
            i = 0;
            continue;
        }
        i++;
    }
}


int main(void)
{
	ft_print_combn(1);
	return (0);
}