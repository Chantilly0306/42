/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:58:23 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/05 19:15:53 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	desc;

	if (length <= 1)
		return (1);
	i = 0;
	asc = 1;
	desc = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			asc = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			desc = 0;
		i++;
	}
	return (asc || desc);
}
/*
#include <stdio.h>
int	compare_num(int n1, int n2)
{
	return (n1 - n2);
}

int	main(void)
{
	int	tab[] = {1, 1, 1, -1, -2, -3, -5};

	printf("%d\n", ft_is_sort(tab, 7, compare_num));
	return (0);
}*/
