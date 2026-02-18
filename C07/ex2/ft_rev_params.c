/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:35:49 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/12 15:53:23 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 0)
	{
		i = 1;
		while (argv[i])
		{
			j = 0;
			while (argv[argc - i][j])
				write(1, &argv[argc - i][j++], 1);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
