/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:00:28 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/08 17:31:13 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_line(int line[4], int expected_view_count)
{
	int	i;
	int	max_height;
	int	view_count;

	i = 0;
	max_height = 0;
	view_count = 0;
	while (i < 4)
	{
		if (line[i] > max_height)
		{
			view_count++;
			max_height = line[i];
		}
		i++;
	}
	return (view_count == expected_view_count);
}

void	get_line_data(int grid[4][4], int i, int line[4])
{
	int	index;

	index = 0;
	while (index < 4)
	{
		if (i / 4 == 0)
			line[index] = grid[index][i];
		else if (i / 4 == 1)
			line[index] = grid[3 - index][i - 4];
		else if (i / 4 == 2)
			line[index] = grid[i - 8][index];
		else if (i / 4 == 3)
			line[index] = grid[i - 12][3 - index];
		index++;
	}
}

int	check_all_views(int input[16], int grid[4][4])
{
	int	i;
	int	line[4];

	i = 0;
	while (i < 16)
	{
		get_line_data(grid, i, line);
		if (check_line(line, input[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_no_repeat(int grid[4][4], int position, int nb)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (nb == grid[position / 4][i])
			return (0);
		if (nb == grid[i][position % 4])
			return (0);
		i++;
	}
	return (1);
}

int	fill_nb(int input[16], int grid[4][4], int position)
{
	int	nb;

	if (position == 16)
		return (check_all_views(input, grid));
	nb = 1;
	while (nb <= 4)
	{
		if (check_no_repeat(grid, position, nb))
		{
			grid[position / 4][position % 4] = nb;
			if (fill_nb(input, grid, position + 1))
				return (1);
		}
		grid[position / 4][position % 4] = 0;
		nb++;
	}
	return (0);
}
