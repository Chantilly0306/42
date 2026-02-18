/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:57:35 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/12 18:46:35 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	compare_ascii(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (0);
		else
			i++;
	}
	return (0);
}

void	print_params(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			write(1, &argv[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	if (argc > 0)
	{
		i = 1;
		while (argv[i])
		{
			j = i + 1;
			while (argv[j])
			{
				if (compare_ascii(argv[i], argv[j]))
				{
					temp = argv[i];
					argv[i] = argv[j];
					argv[j] = temp;
				}
				j++;
			}
			i++;
		}
		print_params(argv);
	}
	return (0);
}
