/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:33:00 by hsilin            #+#    #+#             */
/*   Updated: 2026/02/13 14:02:59 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!is_sep(str[i], sep) && (is_sep(str[i + 1], sep) || !str[i + 1]))
			words++;
		i++;
	}
	return (words);
}

int	count_c(char *str, char *sep, int j)
{
	int	c;

	c = 0;
	while (str[j] && !is_sep(str[j], sep))
	{
		c++;
		j++;
	}
	return (c);
}

char	*fill_c(char *str, int pos, int len)
{
	int		i;
	char	*word;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[pos];
		i++;
		pos++;
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		words;
	int		i;
	int		pos;
	int		len;

	if (!str || !charset)
		return (NULL);
	words = count_word(str, charset);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = 0;
	i = 0;
	pos = 0;
	while (i < words)
	{
		while (str[pos] && is_sep(str[pos], charset))
			pos++;
		len = count_c(str, charset, pos);
		res[i] = fill_c(str, pos, len);
		pos += len;
		i++;
	}
	return (res);
}

int	main(void)
{
	char	**res;
	int		i;

	res = ft_split("Hello!?W orld, 42!", "-");
	i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		free (res[i]);
		i++;
	}
	free (res);
	return (0);
}
