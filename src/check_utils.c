#include "../filler.h"

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
					g_plr_y = i;
				if ((map->map)[i][j] == g_enm)
					g_enm_y = i;
				j++;
			}
			i++;
		}
		use++;
	}
}