/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:02:36 by hsilin            #+#    #+#             */
/*   Updated: 2026/01/31 18:56:32 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/
int	ft_iterative_factorial(int nb)
{
	int	outcome;

	if (nb < 0)
		return (0);
	outcome = 1;
	while (nb > 0)
	{
		outcome = outcome * nb;
		nb--;
	}
	return (outcome);
}
/*int	main(void)
{
	int	n;

	n = ft_iterative_factorial(5);
	printf("%d\n", n);
    n = ft_iterative_factorial(-5);
    printf("%d\n", n);
    n = ft_iterative_factorial(0);
    printf("%d\n", n);
    n = ft_iterative_factorial(123456);
    printf("%d\n", n);
	return 0;
}*/
