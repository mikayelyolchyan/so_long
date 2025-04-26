#include "../../includes/headers/so_long.h"

int check_extension(char *filename)
{
    int len;

    if (!filename)
    {
        ft_putstr_fd("Error: Filename is NULL\n", 2);
        return (0);
    }
    len = ft_strlen(filename);
    if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
    {
        ft_putstr_fd("Error: File must have .ber extension\n", 2);
        return (0);
    }
    return (1);
}
