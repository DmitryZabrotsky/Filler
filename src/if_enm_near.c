#include "../filler.h"

void		enm_side_3(t_map *map, t_map *piece)
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
				if_enm_near(y, x, map, piece);
					break ;
			}
			x++;
		}
		y++;
	}
}

void		enm_side_4(t_map *map, t_map *piece)
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
				if_enm_near(y, x, map, piece);
					break ;
			}
		}
		y++;
	}
}

void		enm_side_1(t_map *map, t_map *piece)
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
				if_enm_near(y, x, map, piece);
					break ;
			}
			x++;
		}
	}
}

void		enm_side_2(t_map *map, t_map *piece)
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
				if_enm_near(y, x, map, piece);
					break ;
			}
		}
	}
}