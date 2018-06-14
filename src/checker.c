/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:17:30 by dzabrots          #+#    #+#             */
/*   Updated: 2018/06/14 17:17:38 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int				check_coord(int y, int x, t_map *map, t_map *piece)
{
	int			i;
	int			j;

	g_overlap = 0;
	i = -1;
	while (++i < piece->y)
	{
		j = -1;
		while (++j < piece->x)
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
		}
	}
	return (g_overlap == 1 ? 1 : 0);
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
