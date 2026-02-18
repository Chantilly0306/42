/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:35:26 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/18 16:43:37 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
/*
typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;
*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str, int len)
{
	int		i;
	char	*new_str;

	if (len <= 0 || !str)
		return (NULL);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock;

	if (ac <= 0)
		return (NULL);
	stock = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i], stock[i].size);
		i++;
	}
	stock[ac].str = 0;
	return (stock);
}
/*
int	main(void)
{
	int			i = 0;
	char		*src[] = {"Byebye", "42", "Piscine"};
	t_stock_str	*res;

	res = ft_strs_to_tab(3, src);
	while (res[i].copy)
	{
		printf("%s\n", res[i].copy);
		free(res[i++].copy);
	}
	free(res);
	return (0);
}*/
