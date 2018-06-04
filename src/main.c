#include "../filler.h"

void	parse_player(void)
{
	char *s;

	get_next_line(0, &s);
	if (ft_strstr(s, "dzabrots.filler"))
		g_player = (ft_strstr(s, "p1") ? "p1" : "p2");
	free(s);
	g_plr = ft_strequ(g_player, "p1") ? 'O' : 'X';
	g_enm = ft_strequ(g_player, "p1") ? 'X' : 'O';
}

int		parse_xy(char *s, char coord)
{
	char **arr;
	int res;

	res = -1;
	arr = ft_strsplit(s, ' ');
	if (coord == 'x')
		res = ft_atoi(arr[2]);
	else if (coord == 'y')
		res = ft_atoi(arr[1]);
	ft_arrfree(&arr);
	return (res);
}

char	**parse_board(int i)
{
	char **board;
	char *s;
	int len;
	int j;

	len = i + 1;
	j = 0;
	if ((board = (char **)malloc(sizeof(char *) * len)))
	{
		board[i] = NULL;
		if (get_next_line(0, &s))
			free(s);
		while (j < i)
		{
			if (get_next_line(0, &s))
			{	
				// ft_putstr_fd(WHITE, 2);
				// ft_putendl_fd(s, 2);
				// ft_putstr_fd(RESET, 2);
				board[j] = ft_strdup(s + 4);
				free(s);
			}
			j++;
		}
	}
	return (board);
}

t_map	*parse_map(void)
{
	char *s;
	t_map *map;

	map = create_map();
	if (get_next_line(0, &s))
	{
		if (ft_strstr(s, "Plateau"))
		{
			map->x = parse_xy(s, 'x');
			map->y = parse_xy(s, 'y');
		}
	}
	map->map = parse_board(map->y);
	return (map);
}

char	**parse_figure(int i)
{
	char **figure;
	char *s;
	int len;
	int j;

	len = i + 1;
	j = 0;
	if ((figure = (char **)malloc(sizeof(char *) * len)))
	{
		figure[i] = NULL;
		while (j < i)
		{
			if (get_next_line(0, &s))
			{	
				figure[j] = ft_strdup(s);
				free(s);
			}
			j++;
		}
	}
	return (figure);
}

t_map	*parse_piece(void)
{
	char *s;
	t_map *piece;

	piece = create_map();
	if (get_next_line(0, &s))
	{
		if (ft_strstr(s, "Piece"))
		{
			piece->x = parse_xy(s, 'x');
			piece->y = parse_xy(s, 'y');
		}
	}
	piece->map = parse_figure(piece->y);
	return (piece);
}

int		main(void)
{
	//char *s;
	t_map *map;
	t_map *piece;

	parse_player();
	while (1)
	{
		map = parse_map();
		piece = parse_piece();

		if (!map || !piece)
			break ;
	// ft_putstr_fd(GREEN, 2);
	// ft_putendl_fd(g_player, 2);
	// ft_putstr_fd(RESET, 2);

	// ft_putstr_fd(BLUE, 2);
	// ft_putendl_fd(ft_itoa(map->x), 2);
	// ft_putendl_fd(ft_itoa(map->y), 2);
	// ft_putstr_fd(RESET, 2);

	// put_arr(map->map, map->y);

	// ft_putstr_fd(BLUE, 2);
	// ft_putendl_fd(ft_itoa(piece->x), 2);
	// ft_putendl_fd(ft_itoa(piece->y), 2);
	// ft_putstr_fd(RESET, 2);
	
	// put_arr(piece->map, piece->y);

		will_put(map, piece);
	
		del_map(&map);
		del_map(&piece);
	}
	// while (1)
	// {
	// 	while (get_next_line(0, &s))
	// 	{
	// 		ft_putstr_fd(RED, 2);
	// 		ft_putendl_fd(s, 2);
	// 		ft_putstr_fd(RESET, 2);
	// 		free(s);
	// 	}
	// 	//ft_putendl_fd("3 3\n", 0);
	// }
}