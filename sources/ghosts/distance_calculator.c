#include "../../includes/headers/so_long.h"

int	distance_calculator(int x1, int x2, int y1, int y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
