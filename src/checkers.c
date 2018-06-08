#include "../filler.h"

int		check_coord(int y, int x, t_map *map, t_map *piece)
{
	int i;
	int j;

	g_overlap = 0;
	i = 0;
	while (i < piece->y)
	{
		j = 0;
		while (j < piece->x)
		{	
			if (i + y > map->y - 1 || j + x > map->x - 1)
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

int		is_enm_near(int x, int y, t_map *map)
{
	int		x1;
	int		y1;

	y1 = y - 1;
	while (y1 > -1 && y1 < map->y && y1 <= y + 1)
	{
		x1 = x - 1;
		while (x1 > -1 && x1 < map->x && x1 <= x + 1)
		{
			if (map->map[y1][x1] == g_enm|| map->map[y1][x1] == g_enm - 32)
				return (1);
			x1++;
		}
		y1++;
	}
	return (0);
}

int			if_enm_near(t_map *map, t_map *piece)
{
	int i;
	int j;

	i = 0;
	while (i < piece->y)
	{
		j = 0;
		while (j < piece->x)
		{
			if ((piece->map)[i][j] == '*')
			{	
				if (is_enm_near(i, j, map))
					return (1);
			}
			j++;
		}
	i++;
	}
	return (0);
}