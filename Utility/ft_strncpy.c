#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	len;

	if (!src)
		return (0);
	i = 0;
	len = 0;
	while(src[len])
		len++;
	while (i < n)
	{
		if (src[i])
			dest[i] = src[i];
		else
			dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[30];
	char	*res;

	res = ft_strncpy(dest, "Hello World!", 5);
	printf("%s\n", res);
}*/
