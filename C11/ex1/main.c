#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char	*src = "Hello 42 piscine!";
	char	*res;

	res = ft_strdup(src);
	printf("%s", res);
	free(res);
	return (0);
}