/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:12:10 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/11 20:24:58 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_malloc_size(long nb, int base_len)
{
	int	size;

	size = 0;
	if (nb <= 0)
		size = 1;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb /= base_len;
		size++;
	}
	return (size);
}

char	*itoa_base(int n, char *base_to, int base_len)
{
	long	nb;
	int		size;
	char	*res;

	nb = n;
	size = get_malloc_size(nb, base_len);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = '\0';
	if (nb == 0)
		res[0] = base_to[0];
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		res[--size] = base_to[nb % base_len];
		nb /= base_len;
	}
	return (res);
}
