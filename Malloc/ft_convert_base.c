#include <stdlib.h>

int	get_malloc_size(long nb, int base_len)
{
	int	size;

	size = 0;
	if (nb <= 0)
		size = 1;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb /= base_len;
		size++;
	}
	return (size);
}

char	*itoa_base(int n, char *base_to, int base_len)
{
	long	nb;
	int		size;
	char	*res;

	nb = n;
	size = get_malloc_size(nb, base_len);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = '\0';
	if (nb == 0)
		res[0] = base_to[0];
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		res[--size] = base_to[nb % base_len];
		nb /= base_len;
	}
	return (res);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || !base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] <= 32 || base[i] > 126 || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	get_nb(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	atoi_base(char *str, char *base, int base_len)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (get_nb(str[i], base) >= 0)
	{
		res = res * base_len + get_nb(str[i], base);
		i++;
	}
	return (res * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	decimal_nb;
	int	len_base_from;
	int	len_base_to;

	len_base_from = check_base(base_from);
	len_base_to = check_base(base_to);
	if (len_base_from < 2 || len_base_to < 2)
		return (NULL);
	decimal_nb = atoi_base(nbr, base_from, len_base_from);
	return (itoa_base(decimal_nb, base_to, len_base_to));
}
/*
#include <stdio.h>

int	main(void)
{
	char	*res;

	res = ft_convert_base("---^#", "!@#$^&*", "abcdefghijklmnopqrstuvwxyz");
	if (res == NULL)
		printf("null\n");
	else
		printf("%s\n", res);
	free(res);
	return (0);
}*/
