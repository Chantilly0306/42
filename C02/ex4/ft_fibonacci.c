/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:28:18 by hsilin            #+#    #+#             */
/*   Updated: 2026/01/31 20:54:45 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/
int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*int	main(void)
{
	int	n;

    n = ft_fibonacci(3);
    printf("%d, ", n);
    n = ft_fibonacci(4);
    printf("%d, ", n);
    n = ft_fibonacci(5);
    printf("%d, ", n);
    n = ft_fibonacci(6);
    printf("%d, ", n);
    n = ft_fibonacci(7);
    printf("%d, ", n);
}*/
