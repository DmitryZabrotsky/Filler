#include "../filler.h"

void		move_near_enm_3(t_map *map, t_map *piece)
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
				if_enm_near(map, piece);
					break ;
			}
			x++;
		}
		y++;
	}
}

void		move_near_enm_4(t_map *map, t_map *piece)
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
				g_resy = y;
				g_resx = x;
				if_enm_near(map, piece);
					break ;
			}
		}
		y++;
	}
}

void		move_near_enm_1(t_map *map, t_map *piece)
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
				g_resy = y;
				g_resx = x;
				if_enm_near(map, piece);
					break ;
			}
			x++;
		}
	}
}

void		move_near_enm_2(t_map *map, t_map *piece)
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
				if_enm_near(map, piece);
					break ;
			}
		}
	}
}