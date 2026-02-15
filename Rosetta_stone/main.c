#include "rush02.h"

int main(int argc, char **argv)
{
    char    *path;
    char    *input;
    int     len;

    path = "numbers.dict";
    if (argc < 2 || argc > 3)
        return (write(1, "Error\n", 6), 0);
    if (argc == 3)
        path = argv[1];
    input = argv[argc - 1];
    len = valid_len(input);
    if (len == 0)
        return (write(1, "Error\n", 6), 0);
    if (convert(path, input, len) == 0)
		write(1, "Dict Error\n", 11);
    return (0);
}