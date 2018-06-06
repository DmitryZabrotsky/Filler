#include "../filler.h"

static void		set_plr_coords(int y, int x)
{
	g_plr_y = y;
	g_plr_x = x;
}

static void		set_enm_coords(int y, int x)
{
	g_enm_y = y;
	g_enm_x = x;
}

void			find_location(t_map *map)
{
	int			i;
	int			j;
	static int	use = 0;

	i = 0;
	if (!use)
	{
		while (i < map->y)
		{
			j = 0;
			while (j < map->x)
			{
				if ((map->map)[i][j] == g_plr)
					set_plr_coords(i, j);
				if ((map->map)[i][j] == g_enm)
					set_enm_coords(i, j);
				j++;
			}
			i++;
		}
		use++;
	}
}