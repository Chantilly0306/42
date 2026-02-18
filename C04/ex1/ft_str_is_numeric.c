/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:45:06 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/03 15:45:51 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
/*#include <unistd.h>
int	main(void)
{
	char	c;

	c = '0' + ft_str_is_numeric("23;dc");
	write(1, &c, 1);
    c = '0' + ft_str_is_numeric("012345");
    write(1, &c, 1);
    c = '0' + ft_str_is_numeric("");
    write(1, &c, 1);

	return (0);
}*/
