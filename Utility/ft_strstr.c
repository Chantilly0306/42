/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:45:01 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/17 12:57:28 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_str(char *str, char *to_find, int pos)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (to_find[len])
		len++;
	while (i < len)
		if (str[pos++] != to_find[i++])
			return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] != to_find[0])
			i++;
		else
		{
			if (is_str(str, to_find, i) == 1)
				return (&str[i]);
			i++;
		}
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*res;

	res = ft_strstr("Hello 202026 paris piscine 2026, 2027", "2028");
	if (res == NULL)
		printf("nulll");
	else
		printf("%s\n", res);
	return (0);
}*/
