#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

void    display_error()

int main(int argc, char **argv)
{
    int i;

    if (argc == 1)
        display_file(0);
    else
    {
        i = 0;
        while (argv[i])
        {
            if (argv[i][0] == '-' && argv[i][1] == 'c')
                c = 1;
        }
    }
}