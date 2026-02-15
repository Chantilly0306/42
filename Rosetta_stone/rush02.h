#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;

int		is_valid_nb(char *str);
int		skip_whitespace(char *buf, int i);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strncpy(char *dest, char *src, int n);
char	*read_to_malloc_buf(char *path);
int		count_lines(char *buf);
char	*rosetta_atoa(char *str, int len);
int		simple_atoi(char *str);
int		valid_len(char *str);
int		convert(char *path, char *input, int len);
char	*find_in_dict(char *key, t_dict *dict, int size);
int		print_3_digits(int n, t_dict *dict, int size);
int		print_unit(int len, t_dict *dict, int size);
int		check_unit(t_dict *dict, int size, int len);

#endif
