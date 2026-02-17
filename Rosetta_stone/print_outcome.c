#include "rush02.h"

char	*to_str(int n, char str[4])
{
	if (n >= 100)
	{
		str[0] = (n / 100) + '0';
		str[1] = (n / 10 % 10) + '0';
		str[2] = (n % 10) + '0';
		str[3] = '\0';
	}
	else if (n >= 10)
	{
		str[0] = (n / 10) + '0';
		str[1] = (n % 10) + '0';
		str[2] = '\0';
	}
	else
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}

char	*find_in_dict(char *key, t_dict *dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	return (NULL);
}

void	print_hundred(int *n, t_dict *dict, int size)
{
	char	*tmp;
	char	temp[4];

	if (*n >= 100)
	{
		tmp = to_str(*n / 100, temp);
		ft_putstr(find_in_dict(tmp, dict, size));
		write(1, " ", 1);
		ft_putstr(find_in_dict("100", dict, size));
		if (*n % 100 != 0)
			write(1, " ", 1);
		*n %= 100;
	}
}

int	print_3_digits(int n, t_dict *dict, int size)
{
	char	*tmp;
	char	temp[4];

	print_hundred(&n, dict, size);
	if (n >= 20)
	{
		tmp = to_str((n / 10) * 10, temp);
		ft_putstr(find_in_dict(tmp, dict, size));
		if (n % 10 != 0)
			write(1, " ", 1);
		n %= 10;
	}
	if (n > 0 && n < 20)
	{
		tmp = to_str(n, temp);
		ft_putstr(find_in_dict(tmp, dict, size));
	}
	return (1);
}

int	print_unit(int len, t_dict *dict, int size)
{
	char	*tmp;
	char	*value;
	int		i;

	if (len <= 3)
		return (1);
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	tmp[0] = '1';
	i = 1;
	while (i < len)
		tmp[i++] = '0';
	tmp[i] = '\0';
	value = find_in_dict(tmp, dict, size);
	free(tmp);
	if (!value)
		return (0);
	write(1, " ", 1);
	ft_putstr(value);
	return (1);
}
