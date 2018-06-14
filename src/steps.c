#include "../filler.h"

void		move_to_3(t_map *map, t_map *piece)
{
	int y;
	int x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (check_coord(y, x, map, piece))
			{
				g_resy = y;
				g_resx = x;
				break ;
			}
			x++;
		}
		y++;
	}
}

void		move_to_4(t_map *map, t_map *piece)
{
	int y;
	int x;

	y = 0;
	while (y < map->y)
	{
		x = map->x;
		while (--x >= 0)
		{
			if (check_coord(y, x, map, piece))
			{
				handle_coords(y, x, piece, map);
				// g_resy = y;
				// g_resx = x;
				// break ;
			}
		}
		y++;
	}
}

void		move_to_1(t_map *map, t_map *piece)
{
	int y;
	int x;

	y = map->y;
	while (--y >= 0)
	{
		x = 0;
		while (x < map->x)
		{
			if (check_coord(y, x, map, piece))
			{
				handle_coords(y, x, piece, map);
				// g_resy = y;
				// g_resx = x;
				// break ;
			}
			x++;
		}
	}
}

void		move_to_2(t_map *map, t_map *piece)
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
				handle_coords(y, x, piece, map);
				// g_resy = y;
				// g_resx = x;
				// break ;
			}
		}
	}
}