/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:16:36 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/17 11:32:32 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (src[i] && i < nb)
		dest[j++] = src[i++];
	return (dest);
}
/*
int	main(void)
{
	char	dest[15] = "Hi";

	printf("%s\n", ft_strncat(dest, "lloooo World", 4));
	return (0);
}*/
