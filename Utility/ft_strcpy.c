char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	*src = "Helloooword!";
	char	dest[30];
	char	*res;

	res = ft_strcpy(dest, src);
	printf("%s\n", res);
	return (0);
}*/
/*These functions copy the string pointed to by src, into a string at the
 buffer pointed to by dst. The programmer is responsible for allocating a 
destination buffer large enough.*/
