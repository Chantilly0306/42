#include <unistd.h>

int	check_atoi(char *str)
{
	int	i = 0;
	int	nb = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		else
			nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (nb <= 1)
		return (0);
	return (nb);
}

int	is_prime(int i)
{
	int	j = i - 1;

	while (j > 1)
	{
		if (i % j == 0)
			return (0);
		j--;
	}
	return (i);
}

void	putnb(int nb)
{
	char	c;

	if (nb >= 10)
		putnb(nb / 10);
	c = '0' + nb % 10;
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	nb;
	int	res;

	if (argc == 2)
		nb = check_atoi(argv[1]);
	if (argc != 2 || nb == 0)
		write(1, "0", 1);
	else
	{
		res = 0;
		while (nb > 1)
		{
			res += is_prime(nb);
			nb--;
		}
		putnb(res);
	}
	write(1, "\n", 1);
	return (0);
}
