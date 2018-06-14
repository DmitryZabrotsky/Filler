/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:18:19 by dzabrots          #+#    #+#             */
/*   Updated: 2018/06/14 17:18:21 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				handle_coords(y, x, piece, map);
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
				handle_coords(y, x, piece, map);
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
				handle_coords(y, x, piece, map);
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
				handle_coords(y, x, piece, map);
		}
	}
}
