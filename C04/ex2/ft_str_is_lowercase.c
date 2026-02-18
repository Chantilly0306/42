/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:46:40 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/03 15:47:13 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 97 || str[i] > 122)
			return (0);
		i++;
	}
	return (1);
}
/*#include <unistd.h>
int	main(void)
{
	char	c;

	c = '0' + ft_str_is_lowercase("oAo");
	write(1, &c, 1);
    c = '0' + ft_str_is_lowercase("abcde");
    write(1, &c, 1);
    c = '0' + ft_str_is_lowercase("");
    write(1, &c, 1);
	return (0);
}*/
