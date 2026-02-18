/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:29:33 by hsilin            #+#    #+#             */
/*   Updated: 2026/01/31 20:08:27 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/
int	ft_iterative_power(int nb, int power)
{
	int	outcome;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	outcome = nb;
	while (power > 1)
	{
		outcome = outcome * nb;
		power--;
	}
	return (outcome);
}
/*int	main(void)
{
	int	n;

	n = ft_iterative_power(5, 3);
	printf("%d\n", n);
	n = ft_iterative_power(5, -3);
    printf("%d\n", n);
	n = ft_iterative_power(-5, 3);
    printf("%d\n", n);
	n = ft_iterative_power(-5, 0);
    printf("%d\n", n);
    n = ft_iterative_power(0, 0);
    printf("%d\n", n);
	return (0);
}*/
