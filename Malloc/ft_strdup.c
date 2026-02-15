#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		length;
	char	*new_str;

	if (!src)
		return (0);
	length = 0;
	while (src[length] != 0)
		length++;
	new_str = (char *)malloc(sizeof(char) * (length + 1));
	if (!new_str)
		return (0);
	i = 0;
	while (i < length)
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*src = NULL;
	char	*res;

	res = ft_strdup(src);
	printf("%s", res);
	free(res);
	return (0);
}*/
/*The strdup() function returns a pointer to a new string which is a duplicate
 * of the string s.  Memory for the new string is obtained with malloc(3), 
 * and can be freed with free(3).*/
