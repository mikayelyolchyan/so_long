#include "../../includes/headers/so_long.h"

int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || \
		c == '\r' || c == '\v' || c == '\f');
}
