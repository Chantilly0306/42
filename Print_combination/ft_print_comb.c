#include <unistd.h>

void	write_comb(int a, int b, int c)
{
	char	n;

	n = '0' + a;
	write(1, &n, 1);
	n = '0' + b;
	write(1, &n, 1);
	n = '0' + c;
	write(1, &n, 1);
	if (a != 7)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int		a;
	int		b;
	int		c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				write_comb(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}

int main(void)
{
	ft_print_comb();
	return (0);
}
