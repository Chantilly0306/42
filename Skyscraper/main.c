/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:13:32 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/08 17:34:09 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	fill_nb(int input[16], int grid[4][4], int position);

void	print_nb(int grid[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = '0' + grid[i][j];
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	turn_str_to_arr(char *string, int input[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (string[i] != 0)
	{
		if (string[i] >= '1' && string[i] <= '4')
		{
			input[j] = string[i] - '0';
			j++;
		}
		i++;
	}
}

int	check_input(char *string)
{
	int	i;

	i = 0;
	while (string[i] != 0)
		i++;
	if (i != 31)
		return (0);
	i = 0;
	while (i < 31)
	{
		if (i % 2 == 0)
		{
			if (string[i] < '1' || string[i] > '4')
				return (0);
		}
		else if (string[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	input[16];
	int	grid[4][4];

	if (argc == 2 && check_input(argv[1]))
	{
		turn_str_to_arr(argv[1], input);
		init_grid(grid);
		if (fill_nb(input, grid, 0) == 1)
			print_nb(grid);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
