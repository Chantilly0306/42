#include "rush02.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    char    *path;
    char    *number;
    char    *buf;
    int     lines;

    path = "numbers.dict";
    if (argc == 2)
        number = argv[1];
    else if (argc == 3)
    {
        path = argv[1];
        number = argv[2];
    }
    else
    {
        write(1, "Error\n", 6);
        return (0);
    }
    buf = read_to_malloc_buf(path);
    if (!buf)
    {
        write(1, "Dict Error\n", 11);
        return (0);
    }
    lines = count_lines(buf);

    printf("%d\n", lines);
    printf("%s\n\n", number);
    printf("%s", buf);

    free(buf);
    return (0);
}