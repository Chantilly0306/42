/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:49:04 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/03 15:49:15 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}
/*#include <unistd.h>
int	main(void)
{
	char	c;

	c = '0' + ft_str_is_printable("€42");
	write(1, &c, 1);
	c = '0' + ft_str_is_printable(" ABCDEF");
	write(1, &c, 1);
	c = '0' + ft_str_is_printable("");
	write(1, &c, 1);
	return (0);
}*/
