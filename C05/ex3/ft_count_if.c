/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:14:23 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/05 13:56:53 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (i < length)
	{
		if (f(tab[i]))
			r++;
		i++;
	}
	return (r);
}
/*
#include <stdio.h>
int	is_lowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 97 || str[i] > 122)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	char	*tab[] = {"abc", "Def", "ghi", "123", "jklmn"};

	printf("%d\n", ft_count_if(tab, 5, is_lowcase));
	return (0);
}*/
