/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:22:23 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/12 15:33:01 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc > 0)
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
				write(1, &argv[i][j++], 1);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
