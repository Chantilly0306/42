/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:12:53 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/01 15:24:49 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
/*#include <stdio.h>
int	main(void)
{
	int	*a;
	int *b;
	int c;
	int d;

	a = &c;
	b = &d;
	*a = 3;
	*b = 5;
    printf("%d\n", c);
    printf("%d\n", d);
	ft_swap(a, b);
    printf("%d\n", c);
    printf("%d\n", d);
	return (0);
}*/
