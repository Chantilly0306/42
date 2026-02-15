#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*new_tab;

	if (length <= 0)
		return (0);
	new_tab = (int *)malloc(sizeof(int) * length);
	if (!new_tab)
		return (0);
	i = 0;
	while (i < length)
	{
		new_tab[i] = f(tab[i]);
		i++;
	}
	return (new_tab);
}
/*
#include <stdio.h>

int double_num(int n)
{
    return (n * 2);
}

int	main()
{
	int	i;
	int	tab[] = {1, 2, 3, 4, 5};
	int *res;

	res = ft_map(tab, 5, &double_num);
	i = 0;
	while (i < 5)
	{
		printf("%d\n", res[i]);
		i++;
	}
	return (0);
}*/
