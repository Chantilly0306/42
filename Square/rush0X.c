/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:47:06 by hsilin            #+#    #+#             */
/*   Updated: 2026/01/31 13:15:00 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	write_line(char left, char mid, char right, int n)
{
	int	i;

	i = 1;
	ft_putchar(left);
	while (i <= n - 2)
	{
		ft_putchar(mid);
		i++;
	}
	if (n >= 2)
		ft_putchar(right);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	i = 1;
	write_line('A', 'B', 'C', x);
	while (i <= y - 2)
	{
		write_line('B', ' ', 'B', x);
		i++;
	}
	if (y >= 2)
		write_line('C', 'B', 'A', x);
}
