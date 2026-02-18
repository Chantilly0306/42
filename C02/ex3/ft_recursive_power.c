/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:10:38 by hsilin            #+#    #+#             */
/*   Updated: 2026/01/31 20:23:21 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/
int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*int	main(void)
{
	int	n;

	n = ft_recursive_power(5, 3);
	printf("%d\n", n);
	n = ft_recursive_power(5, -3);
    printf("%d\n", n);
	n = ft_recursive_power(-5, 3);
    printf("%d\n", n);
	n = ft_recursive_power(-5, 0);
    printf("%d\n", n);
    n = ft_recursive_power(0, 0);
    printf("%d\n", n);
	return (0);
}*/
