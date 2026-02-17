/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:33:23 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/16 18:44:32 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	src[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	*src = "Helloooword!";
	char	dest[30];
	char	*res;

	res = ft_strcpy(dest, src);
	printf("%s\n", res);
	return (0);
}*/
/*These functions copy the string pointed to by src, into a string at the
 buffer pointed to by dst. The programmer is responsible for allocating a 
destination buffer large enough.*/
