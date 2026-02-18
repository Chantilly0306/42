/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:50:46 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/03 15:50:52 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}
/*#include <stdio.h>
int	main(void)
{
	char	s[] = "aBCdeFGHIJKLmnoPQRSTUVWXYz";

	ft_strlowcase(s);
	printf("%s\n", s);
	return (0);
}*/
