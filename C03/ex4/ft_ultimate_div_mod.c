/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:45:47 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/01 17:26:08 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a;
	*a = c / *b;
	*b = c % *b;
}
/*#include <stdio.h>
int	main(void)
{
	int	*a;
	int	*b;
	int	c;
	int	d;

	a = &c;
	b = &d;
	*a = 13;
	*b = 5;
	ft_ultimate_div_mod(a, b);
	printf("%d, %d\n", c, d);
	return (0);
}*/
