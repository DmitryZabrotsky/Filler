/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:18:54 by dzabrots          #+#    #+#             */
/*   Updated: 2018/06/14 17:19:00 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void		will_put(t_map *map, t_map *piece)
{
	char	*y;
	char	*x;

	g_resx = 0;
	g_resy = 0;
	map->end_y = map->y - piece->y + 1;
	map->end_x = map->x - piece->x + 1;
	if (map->y * map->x <= 256 && g_plr_y > g_enm_y)
		move_to_4(map, piece);
	else if (g_plr_y < g_enm_y)
		move_to_4(map, piece);
	else if (g_plr_y > g_enm_y)
		move_to_1(map, piece);
	y = ft_itoa(g_resy);
	x = ft_itoa(g_resx);
	ft_putstr_fd(y, 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(x, 1);
	ft_putstr_fd("\n", 1);
	g_value = 0;
	free(y);
	free(x);
}

int			main(void)
{
	t_map	*map;
	t_map	*piece;

	parse_player();
	while (1)
	{
		map = parse_map();
		piece = parse_piece();
		find_location(map);
		if (!map || !piece)
			break ;
		will_put(map, piece);
		del_map(&map);
		del_map(&piece);
	}
}
