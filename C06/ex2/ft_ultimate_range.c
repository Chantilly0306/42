/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:17:16 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/11 21:24:50 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}
/*
#include <stdio.h>
int main(void)
{
	int	i = 0;
    int *res;
    int size;

    size = ft_ultimate_range(&res, -3, 5);
    printf("The size of range is %d\n", size);
	if (res == NULL)
		printf("null\n");
	while (i < size)
	{
		printf("%d\n", res[i]);
		i++;
	}
	free(res);
	return (0);
}*/
