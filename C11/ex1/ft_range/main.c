#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

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
}