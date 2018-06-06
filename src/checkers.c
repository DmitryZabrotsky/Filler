#include "../filler.h"

static int		check_coord(int y, int x, t_map *map, t_map *piece)
{
	int i;
	int j;
	int end_x;
	int end_y;

	end_x = map->x - piece->x + 1;
	end_y = map->y - piece->y + 1;
	g_overlap = 0;
	i = 0;
	while (i < piece->y)
	{
		j = 0;
		while (j < piece->x)
		{	
			if (i + y > end_y || j + x > end_x)
				return (0);
			if ((piece->map)[i][j] == '*')
			{
				if ((map->map)[i + y][j + x] == g_plr ||
					(map->map)[i + y][j + x] == g_plr + 32)
					g_overlap++;
				if ((map->map)[i + y][j + x] == g_enm ||
					(map->map)[i + y][j + x] == g_enm + 32)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (g_overlap == 1 ?  1 : 0);
}

void		will_put(t_map *map, t_map *piece)
{
	//char *res;
	// int end_x;
	// int end_y;
	int i;
	int j;

	int resi = 0;
	int resy = 0;

	// end_x = map->x - piece->x;
	// end_y = map->y - piece->y;
	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (check_coord(i, j, map, piece))
			{
				resi = i;
				resy = j;
				// ft_putstr_fd(CYAN, 2);
				// ft_putstr_fd(ft_itoa(i), 2);
				// ft_putstr_fd(":", 2);
				// ft_putstr_fd(ft_itoa(j), 2);
				// ft_putstr_fd(" ", 2);
				// ft_putstr_fd(RESET, 2);
			}
			// else
			// {
			// 	ft_putstr_fd(BLACK, 2);
			// 	ft_putstr_fd(" ", 2);
			// 	ft_putstr_fd(ft_itoa(i), 2);
			// 	ft_putstr_fd(":", 2);
			// 	ft_putstr_fd(ft_itoa(j), 2);
			// 	ft_putstr_fd(" ", 2);
			// 	ft_putstr_fd(RESET, 2);
			// }
			j++;
		}
		i++;
	}
	// ft_putstr_fd(GREEN, 2);
	// ft_putstr_fd(ft_itoa(resi), 2);
	// ft_putstr_fd(" ", 2);
	// ft_putstr_fd(ft_itoa(resy), 2);
	// ft_putendl_fd("", 2);
	// ft_putstr_fd(RESET, 2);
	ft_putstr_fd(ft_itoa(resi), 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(ft_itoa(resy), 1);
	ft_putstr_fd("\n", 1);
}