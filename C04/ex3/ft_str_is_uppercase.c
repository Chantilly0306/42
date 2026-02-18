/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:47:58 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/03 15:48:17 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 65 || str[i] > 90)
			return (0);
		i++;
	}
	return (1);
}
/*#include <unistd.h>
int	main(void)
{
	char	c;

	c = '0' + ft_str_is_uppercase("ABCdef");
	write(1, &c, 1);
	c = '0' + ft_str_is_uppercase("ABCDEF");
	write(1, &c, 1);
	c = '0' + ft_str_is_uppercase("");
	write(1, &c, 1);
	return (0);
}*/
