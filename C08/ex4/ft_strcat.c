/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:15:00 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/18 11:15:05 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
		dest[i++] = *(src++);
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	dest[15] = "Hi";
	printf("%s\n", ft_strcat(dest, "lloooo World"));
	return (0);
}*/
