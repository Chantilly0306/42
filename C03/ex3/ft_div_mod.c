/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:35:04 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/01 16:43:52 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*#include <stdio.h>
int	main(void)
{
	int	*div;
	int	*mod;
	int	c;
	int	d;

	div = &c;
	mod = &d;
	ft_div_mod(13, 5, div, mod);
	printf("%d, %d\n", *div, *mod);
	return (0);
}*/
