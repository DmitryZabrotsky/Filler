#include "../filler.h"

static int		check_coord(int y, int x, t_map *map, t_map *piece)
{
	int i;
	int j;
	// int end_x;
	// int end_y;

	// end_x = map->x - piece->x + 1;
	// end_y = map->y - piece->y + 1;
	g_overlap = 0;
	i = 0;
	while (i < piece->y)
	{
		j = 0;
		while (j < piece->x)
		{	
			if (i + y > map->end_y || j + x > map->end_x)
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

// void		upperleft(t_map *map, t_map *piece)
// {
// 	int y;
// 	int x;

// 	y = 0;
// 	while (y < map->end_y)
// 	{
// 		x = 0;
// 		while (x < map->end_x)
// 		{
// 			if (check_coord(y, x, map, piece))
// 			{
// 				g_resy = y;
// 				g_resx = x;
// 				break ;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void		upperright(t_map *map, t_map *piece)
// {
// 	int y;
// 	int x;

// 	y = 0;
// 	while (y < map->end_y)
// 	{
// 		x = map->x;
// 		while (--x >= 0)
// 		{
// 			if (check_coord(y, x, map, piece))
// 			{
// 				g_resy = y;
// 				g_resx = x;
// 				break ;
// 			}
// 		}
// 		y++;
// 	}
// }

// void		lowerleft(t_map *map, t_map *piece)
// {
// 	int y;
// 	int x;

// 	y = map->y;
// 	while (--y >= 0)
// 	{
// 		x = 0;
// 		while (x++ < map->end_x)
// 		{
// 			if (check_coord(y, x, map, piece))
// 			{
// 				g_resy = y;
// 				g_resx = x;
// 				break ;
// 			}
// 		}
// 	}
// }

void		lowerright(t_map *map, t_map *piece)
{
	int y;
	int x;

	y = map->y;
	while (--y >= 0)
	{
		x = map->x;
		while (--x >= 0)
		{
			if (check_coord(y, x, map, piece))
			{
				g_resy = y;
				g_resx = x;
				break ;
			}
		}
	}
}

void		will_put(t_map *map, t_map *piece)
{
	g_resx = 0;
	g_resy = 0;
	map->end_y = map->y - piece->y + 1;
	map->end_x = map->x - piece->x + 1;
	// if (g_plr_y < g_enm_y)
	// 	go_down(end_y, end_x, map, piece);
	// if (g_plr_y > g_enm_y)
	// 	go_up(end_y, end_x, map, piece);

	// upperleft(map, piece);
	// upperright(map, piece);
	// lowerleft(map, piece);
	lowerright(map, piece);

	// ft_putstr_fd(GREEN, 2);
	// ft_putstr_fd(ft_itoa(g_resy), 2);
	// ft_putstr_fd(" ", 2);
	// ft_putstr_fd(ft_itoa(g_resx), 2);
	// ft_putendl_fd("", 2);
	// ft_putstr_fd(RESET, 2);
	ft_putstr_fd(ft_itoa(g_resy), 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(ft_itoa(g_resx), 1);
	ft_putstr_fd("\n", 1);
}