/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:40:48 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/02 12:19:37 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
			j++;
		}
		i++;
	}
}
/*#include <stdio.h>
int main(void)
{
    int tab[] = {2, 5, 1, 3, 4};
    int size = 5;
    int i;

    ft_sort_int_tab(tab, size);
    i = 0;
    while (i < size)
    {
        printf("%d\n", tab[i]);
        i++;
    }
    return (0);
}*/
