/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:18:06 by dzabrots          #+#    #+#             */
/*   Updated: 2018/06/14 17:18:11 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visualizer.h"

static int			parse_xy(char *s, char coord)
{
	char			**arr;
	int				res;

	res = -1;
	arr = ft_strsplit(s, ' ');
	if (coord == 'x')
		res = ft_atoi(arr[2]);
	else if (coord == 'y')
		res = ft_atoi(arr[1]);
	ft_arrfree(&arr);
	return (res);
}

static char			**parse_board(int i)
{
	char			**board;
	char			*s;
	int				len;
	int				j;

	len = i + 2;
	j = 0;
	if (i > 90)
		usleep(110000);
	else
		usleep(30000);
	system("clear");
	if ((board = (char **)malloc(sizeof(char *) * len)))
	{
		board[i] = NULL;
		while (j < i)
		{
			if (get_next_line(0, &s))
			{
					ft_putstr_fd(BLACK, 2);
					ft_putendl_fd(s, 2);
					ft_putstr_fd(RESET, 2);
				board[j] = ft_strdup(s);
				free(s);
			}
			j++;
		}
	}
	return (board);
}

// t_res				*parse_res(void)
// {
// 	t_res			*res;
// 	char			*s;

// 	res = create_res();
// 	if (get_next_line(0, &s))
// 	{
// 		if ((ft_strstr(s, "== O fin:")))
// 			res->score_o = ft_strdup(s);
// 		free(s);
// 	}
// 	if (get_next_line(0, &s))
// 	{
// 		if ((ft_strstr(s, "== X fin:")))
// 			res->score_x = ft_strdup(s);
// 		free(s);
// 	}
// 	// ft_putstr_fd(RED, 2);
// 	// ft_putendl_fd(res->score_o, 2);
// 	// ft_putendl_fd(res->score_x, 2);
// 	// ft_putstr_fd(RESET, 2);
// 	return (res);
// }

t_map				*parse_map(void)
{
	char			*s;
	t_map			*map;

	map = create_map();
	if (get_next_line(0, &s))
	{
		if (ft_strstr(s, "Plateau"))
		{
			map->plateau = ft_strdup(s);
			map->x = parse_xy(s, 'x');
			map->y = parse_xy(s, 'y');
			free(s);
			map->map = parse_board(map->y + 1);
		}
		else if ((ft_strstr(s, "== O fin:")))
		{	
			g_scoreo = ft_strdup(s);
			free(s);
		}
		else if ((ft_strstr(s, "== X fin:")))
		{
			g_scorex = ft_strdup(s);
			free(s);
		}
		else
			free (s);
	}
	return (map);
}
