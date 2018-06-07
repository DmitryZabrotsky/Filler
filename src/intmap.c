#include "../filler.h"

// void	build_the_wall_around(int y, int x, int ***res, t_map *map, int num)
// {
// 	if (y - 1 >= 0)
// 	{
// 		if ((*res)[y - 1][x - 1] != 1 && (*res)[y - 1][x - 1] != 0)
// 			(*res)[y - 1][x - 1] = num;
// 		if ((*res)[y - 1][x] != 1 && (*res)[y - 1][x] != 0)
// 			(*res)[y - 1][x] = num;
// 		if ((*res)[y - 1][x + 1] != 1 && (*res)[y - 1][x + 1] != 0)
// 			(*res)[y - 1][x + 1] = num;
// 		//ft_putendl_fd("1", 2);
// 	}
// 	if (y + 1 < map->y)
// 	{
// 		if ((*res)[y + 1][x - 1] != 1 && (*res)[y - 1][x - 1] != 0)
// 			(*res)[y + 1][x - 1] = num;
// 		if ((*res)[y + 1][x] != 1 && (*res)[y - 1][x] != 0)
// 			(*res)[y + 1][x] = num;
// 		if ((*res)[y + 1][x + 1] != 1 && (*res)[y - 1][x + 1] != 0)
// 			(*res)[y + 1][x + 1] = num;
// 		//ft_putendl_fd("2", 2);
// 	}
// 	if (x - 1 >= 0)
// 	{
// 		if ((*res)[y][x - 1] != 1 && (*res)[y][x - 1] != 0)
// 			(*res)[y][x - 1] = num;
// 		//ft_putendl_fd("3", 2);
// 	}
// 	if (x + 1 < map->x)
// 	{
// 		if ((*res)[y][x + 1] != 1 && (*res)[y][x + 1] != 0)
// 			(*res)[y][x + 1] = num;
// 		//ft_putendl_fd("4", 2);
// 	}
// }