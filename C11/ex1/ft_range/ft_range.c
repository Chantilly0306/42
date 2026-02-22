#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
		return (0);
	tab = (int *)malloc(sizeof(int) * (max - min));
	if (!tab)
		return (0);
	i = 0;
	while (i < max - min)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
/*
#include <stdio.h>
int	main(void)
{
	int	*res;
	int	i = 0;

	res = ft_range(-3, 5);
	if (res == NULL)
		return (0);
	while (i < 8)
	{
		printf("%d ", res[i]);
		i++;
	}
	free(res);
	return (0);
}*/
