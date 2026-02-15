#include "rush02.h"

void	fill_dict(char *buf, t_dict *dict, int i, int k)
{
	int		j;
	char	tmp[1024];

	while (buf[i])
	{
		i = skip_whitespace(buf, i);
		if (buf[i] == '\0')
			break ;
		j = 0;
		while (buf[i] >= '0' && buf[i] <= '9' && j < 127)
			tmp[j++] = buf[i++];
		tmp[j] = '\0';
		if (!is_valid_nb(tmp))
			return ;
		dict[k].key = ft_strdup(tmp);
		while (buf[i] != ':')
			i++;
		i = skip_whitespace(buf, i + 1);
		j = 0;
		while (buf[i] >= 32 && buf[i] <= 126 && j < 1023)
			tmp[j++] = buf[i++];
		tmp[j] = '\0';
		dict[k++].value = ft_strdup(tmp);
	}
}

int	translate(char *num, t_dict *dict, int size)
{
	int		len;
	int		first;
	int		value;
	char	tmp[4];

	len = ft_strlen(num);
	if (len == 0)
		return (1);
	first = len % 3;
	if (first == 0)
		first = 3;
	ft_strncpy(tmp, num, first);
	tmp[first] = '\0';
	value = simple_atoi(tmp);
	if (value > 0)
	{
		if (!print_3_digits(value, dict, size))
			return (0);
		if (len > 3 && !print_unit(len - first + 1, dict, size))
			return (0);
		if (ft_strlen(num + first) > 0 && simple_atoi(num + first) > 0)
			write(1, " ", 1);
	}
	return (translate(num + first, dict, size));
}

void	free_dict(t_dict *dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}

int	check_unit(t_dict *dict, int size, int len)
{
	char	*tmp;
	int		current;
	int		i;

	if (len % 3 == 0)
		current = len - 2;
	else
		current = len - (len % 3) + 1;
	while (current > 37)
	{
		tmp = malloc(sizeof(char) * (current + 1));
		if (!tmp)
			return (0);
		tmp[0] = '1';
		i = 1;
		while (i < current)
			tmp[i++] = '0';
		tmp[i] = '\0';
		if (!find_in_dict(tmp, dict, size))
			return (free(tmp), 0);
		free(tmp);
		current -= 3;
	}
	return (1);
}

int	convert(char *path, char *input, int len)
{
	char	*num;
	char	*buf;
	t_dict	*dict;
	int		size;

	num = rosetta_atoa(input, len);
	buf = read_to_malloc_buf(path);
	if (!num || !buf)
		return (free(num), free(buf), 0);
	size = count_lines(buf);
	dict = malloc(sizeof(t_dict) * size);
	if (!dict)
		return (free(num), free(buf), 0);
	fill_dict(buf, dict, 0, 0);
	if (len > 37)
		if (check_unit(dict, size, len) == 0)
			return (free_dict(dict, size), free(num), free(buf), 0);
	if (num[0] == '0' && ft_strlen(num) == 1)
		ft_putstr(find_in_dict("0", dict, size));
	else if (!translate(num, dict, size))
		return (write(1, "Dict Error\n", 11),
			free_dict(dict, size), free(num), free(buf), 0);
	write(1, "\n", 1);
	return (free_dict(dict, size), free(num), free(buf), 1);
}