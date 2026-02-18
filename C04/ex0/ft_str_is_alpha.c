/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:43:25 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/03 15:44:16 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 65 || str[i] > 122 || (str[i] > 90 && str[i] < 97))
			return (0);
		i++;
	}
	return (1);
}
/*#include <unistd.h>
int	main(void)
{
	char	c;

	c = '0' + ft_str_is_alpha("e\\w*5/1y");
	write(1, &c, 1);
    c = '0' + ft_str_is_alpha("abcde");
    write(1, &c, 1);
    c = '0' + ft_str_is_alpha("");
    write(1, &c, 1);
	return (0);
}*/
