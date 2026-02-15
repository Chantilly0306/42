#include <stdlib.h>

int	calculate_size(int size, char **strs, char *sep)
{
	int	res_size;
	int	i;
	int	j;

	res_size = 1;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != 0)
		{
			res_size++;
			j++;
		}
		i++;
	}
	i = 0;
	while (sep[i] != 0)
		i++;
	res_size += i * (size - 1);
	return (res_size);
}

void	fill_str(int size, char **strs, char *res, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != 0)
		{
			res[k] = strs[i][j];
			j++;
			k++;
		}
		j = 0;
		while (sep[j] != 0 && i < size - 1)
		{
			res[k] = sep[j];
			j++;
			k++;
		}
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		res_size;

	if (size <= 0)
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	res_size = calculate_size(size, strs, sep);
	res = (char *)malloc(sizeof(char) * res_size);
	if (!res)
		exit (1);
	fill_str(size, strs, res, sep);
	res[res_size - 1] = '\0';
	return (res);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*strs[] = {"Hello", "Forty", "2"};
	char	*new_str;

	new_str = ft_strjoin(3, strs, "! ");
	if (new_str)
		printf("%s\n", new_str);
	free(new_str);
	return (0);
}*/
