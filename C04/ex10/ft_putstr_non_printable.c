/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:54:57 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/03 15:55:50 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	dec_to_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i] != 0)
	{
		c = (unsigned char)str[i];
		if (c < 32 || c > 126)
		{
			write(1, "\\", 1);
			dec_to_hex(c);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
/*int	main(void)
{
	ft_putstr_non_printable("Ça va?\nParlez vous Français?");
	return (0);
}*/
