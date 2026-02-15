#include <stdio.h>

int	is_str(char *str, char *to_find, int pos)
{
	int	i;
	int	len;
	int	left_len;

	i = 0;
	len = 0;
	left_len = 0;
	while (to_find[len])
		len++;
	while (str[pos + left_len])
		left_len++;
	if (left_len < len)
		return (0);
	while (i < len)
	{
		if (str[pos++] != to_find[i++])
			return (0);
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (!str || !to_find)
		return (0);
	if (*to_find == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] != to_find[0])
			i++;
		else
		{
			if (is_str(str, to_find, i))
				return (&str[i]);
			i++;
		}
	}
	return (0);
}
/*
int	main(void)
{
	char	*res;

	res = ft_strstr("Hello 2025 paris piscine 2026, 2027", "2026");
	if (res == NULL)
		printf("null");
	else
		printf("%.4s\n", res);
	return (0);
}*/
