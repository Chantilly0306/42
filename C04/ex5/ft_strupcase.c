/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:49:57 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/03 15:50:06 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	return (str);
}
/*#include <stdio.h>
int	main(void)
{
	char	s[] = "aBCdefghijklmnopqrstuvwxyz";

	ft_strupcase(s);
	printf("%s\n", s);
	return (0);
}*/
