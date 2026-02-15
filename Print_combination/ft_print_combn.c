#include <unistd.h>

void	write_num(int n, int *num)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = '0' + num[i];
		write(1, &c, 1);
		i++;
	}
	if (num[0] < 10 - n)
		write(1, ", ", 2);
}

void	recursive(int index, int start, int n, int *num)
{
	if (index == n)
	{
		write_num(n, num);
		return ;
	}
	while (start <= 9)
	{
		num[index] = start;
		recursive(index + 1, start + 1, n, num);
		start++;
	}
}

void	ft_print_combn(int n)
{
	int	num[10];

	if (n > 0 && n < 10)
		recursive(0, 0, n, num);
}

int	main(void)
{
	ft_print_combn(5);
	return (0);
}