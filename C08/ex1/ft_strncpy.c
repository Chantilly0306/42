/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:13:56 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/18 11:14:00 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	dest[30];
	char	*res;
	int		i = 0;

	res = ft_strncpy(dest, "Hello World!", 5);
	while (i < 10)
		printf("%c", res[i++]);
	printf("\n");
	return (0);
}*/
