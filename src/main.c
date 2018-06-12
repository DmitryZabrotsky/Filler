#include "../filler.h"

// int			back_to_back(t_map *map)
// {
// 	int y;
// 	int x;

// 	y = 0;
// 	while (y < map->y)
// 	{
// 		x = 0;
// 		while (x < map->x)
// 		{
// 			if ((map->map)[y][x] == g_plr)
// 			{
// 				is_enm_near(y, x, map);
// 					return (1);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }

void		will_put(t_map *map, t_map *piece)
{
	g_resx = 0;
	g_resy = 0;
	map->end_y = map->y - piece->y + 1;
	map->end_x = map->x - piece->x + 1;
	if (g_plr_y < g_enm_y)
	{
		move_to_4(map, piece);
		//handle_coords(map);
	}
	else if (g_plr_y > g_enm_y)
	{
		move_to_1(map, piece);
		//handle_coords(map);
	}



	// ft_putstr_fd(GREEN, 2);
	// ft_putstr_fd(ft_itoa(g_resy), 2);
	// ft_putstr_fd(" ", 2);
	// ft_putstr_fd(ft_itoa(g_resx), 2);
	// ft_putendl_fd("", 2);
	// ft_putstr_fd(RESET, 2);

	ft_putstr_fd(ft_itoa(g_resy), 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(ft_itoa(g_resx), 1);
	ft_putstr_fd("\n", 1);
	g_value = 0;
}

int		main(void)
{
	t_map *map;
	t_map *piece;

	parse_player();
	while (1)
	{
		map = parse_map();
		piece = parse_piece();
		find_location(map);
		if (!map || !piece)
			break ;
		
	// ft_putstr_fd(GREEN, 2);
	// ft_putstr_fd("PLAYER: ", 2);
	// ft_putendl_fd(g_player, 2);
	// ft_putstr_fd(RESET, 2);

	// ft_putstr_fd(BLUE, 2);
	// ft_putendl_fd("MAP Y;X:", 2);
	// ft_putendl_fd(ft_itoa(map->y), 2);
	// ft_putendl_fd(ft_itoa(map->x), 2);
	// ft_putstr_fd(RESET, 2);

	// put_arr(map->map, map->y);

	// ft_putstr_fd(BLUE, 2);
	// ft_putendl_fd(ft_itoa(piece->y), 2);
	// ft_putendl_fd(ft_itoa(piece->x), 2);
	// ft_putstr_fd(RESET, 2);
	
	// put_arr(piece->map, piece->y);

		will_put(map, piece);

		del_map(&map);
		del_map(&piece);
	}
}