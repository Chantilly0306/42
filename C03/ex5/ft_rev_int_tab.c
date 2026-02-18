/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:27:47 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/01 22:16:13 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	temp;

	index = 0;
	while (index < size / 2)
	{
		temp = tab[index];
		tab[index] = tab[size - index - 1];
		tab[size - index - 1] = temp;
		index++;
	}
}
/*#include <stdio.h>
int	main(void)
{
	int	tab[] = {9, 12, 0, -6, 4};
	int	size;
	int	i;

	size = 5;
	ft_rev_int_tab(tab, size);
	i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}*/
