/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:05:42 by hsilin            #+#    #+#             */
/*   Updated: 2026/01/31 20:25:29 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/
int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}
/*int	main(void)
{
	int	n;

	n = ft_recursive_factorial(5);
	printf("%d\n", n);
	n = ft_recursive_factorial(-5);
    printf("%d\n", n);
	n = ft_recursive_factorial(0);
    printf("%d\n", n);
	n = ft_recursive_factorial(123456);
    printf("%d\n", n);
	return (0);
}*/
