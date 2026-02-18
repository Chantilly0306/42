/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:31:34 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/05 13:48:08 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (*(tab + i))
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}
/*
#include <unistd.h>
int is_lowcase(char *str)
{
    int i;

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
	char	*str[] = {"Abc", "Def", "ghi", 0};

	if (ft_any(str, is_lowcase))
		write(1, "1", 1);
	else
		write(1, "0", 1);
	return (0);
}*/
