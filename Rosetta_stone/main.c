#include "rush02.h"



int main(int argc, char **argv)
{
    char    *dict_path;
    char    *number_to_convert;

    dict_path = "numbers.dict";
    if (argc == 2)
        number_to_convert = argv[1];
    else if (argc == 3)
    {
        dict_path = argv[1];
        number_to_convert = argv[2];
    }
    else
    {
        write(1, "Error\n", 6);
        return (1);
    }
    open_file(dict_path);
    return (0);
}