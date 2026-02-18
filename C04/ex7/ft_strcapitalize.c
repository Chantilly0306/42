/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:51:40 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/03 15:51:47 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	c;

	i = 0;
	if (str[i] >= 97 && str[i] <= 122)
		str[i] -= 32;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122)
		{
			if (str[i + 1] >= 97 && str[i + 1] <= 122)
				str[i + 1] -= 32;
		}
		else
		{
			if (str[i + 1] >= 65 && str[i + 1] <= 90)
				str[i + 1] += 32;
		}
		i++;
	}
	return (str);
}
/*#include <stdio.h>
int	main(void)
{
	char	s[] = "hELLO, how are you doing? 42Words forty-two; fifty+and+one";

	ft_strcapitalize(s);
	printf("%s\n", s);
	return (0);
}*/
