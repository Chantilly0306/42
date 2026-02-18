/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:36:52 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/04 15:23:29 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
void	ft_putnbr(int n)
{
	char	c;

	c = '0' + (n % 10);
	write(1, &c, 1);
}
*/
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*int	main()
{
	int	tab[5] = {1, 2, 3, 4, 5};

	ft_foreach(tab, 5, &ft_putnbr);
	return (0);
}*/
