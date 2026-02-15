#include <unistd.h>

void	write_2_digits(int i)
{
	char	n;

	n = '0' + i / 10;
	write(1, &n, 1);
	n = '0' + i % 10;
	write(1, &n, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			write_2_digits(a);
			write(1, " ", 1);
			write_2_digits(b);
			if (a != 98 || b != 99)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}