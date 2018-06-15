/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_map_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:18:43 by dzabrots          #+#    #+#             */
/*   Updated: 2018/06/14 17:18:46 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static int				set_num(int y, int x, t_int_map *int_map)
{
	int			i;
	int			j;

	i = y == 0 ? 0 : y - 1;
	while (i > -1 && i < int_map->y && i <= y + 1)
	{
		j = x == 0 ? 0 : x - 1;
		while (j > -1 && j < int_map->x && j <= x + 1)
		{
			if (int_map->int_arr[i][j] == 0)
				int_map->int_arr[i][j] = int_map->num;
			j++;
		}
		i++;
	}
	return (0);
}

static void			handle_int_map(t_int_map *int_map)
{
	int			i;
	int			j;

	while (if_still_zero(int_map->y, int_map->x, int_map->int_arr))
	{
		i = 0;
		while (i < int_map->y)
		{
			j = 0;
			while (j < int_map->x)
			{
				if (int_map->int_arr[i][j] == int_map->target)
					set_num(i, j, int_map);
				j++;
			}
			i++;
		}
		int_map->target++;
		int_map->num++;
	}
}

static void			choose_coord(int y, int x, int value)
{
	if (g_value == 0)
	{
		g_value = value;
		g_resy = y;
		g_resx = x;
	}
	g_resy = value < g_value ? y : g_resy;
	g_resx = value < g_value ? x : g_resx;
	g_value = value < g_value ? value : g_value;
}

static void			find_lightest_coord(int y, int x, t_map *piece,
				t_int_map *int_map)
{
	int			i;
	int			j;
	int			current_value;

	current_value = 0;
	i = 0;
	while (i < piece->y)
	{
		j = 0;
		while (j < piece->x)
		{
			if (i + y > int_map->y - 1 || j + x > int_map->x - 1)
				break ;
			if ((piece->map)[i][j] == '*')
				current_value += int_map->int_arr[i + y][j + x];
			j++;
		}
		i++;
	}
	choose_coord(y, x, current_value);
}

void			handle_coords(int y, int x, t_map *piece, t_map *map)
{
	t_int_map	*int_map;

	int_map = create_int_map(map->y, map->x);
	fill_int_map(map->y, map->x, map, int_map);
	handle_int_map(int_map);
	find_lightest_coord(y, x, piece, int_map);
	del_int_map(&int_map);
}
