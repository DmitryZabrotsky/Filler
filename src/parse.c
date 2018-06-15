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

#include "../filler.h"

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
				board[j] = ft_strdup(s + 4);
				free(s);
			}
			j++;
		}
	}
	return (board);
}

t_map				*parse_map(void)
{
	char			*s;
	t_map			*map;

	map = create_map();
	if (get_next_line(0, &s))
	{
		if (ft_strstr(s, "Plateau"))
		{
			map->x = parse_xy(s, 'x');
			map->y = parse_xy(s, 'y');
		}
		free(s);
	}
	map->map = parse_board(map->y);
	return (map);
}

static char			**parse_figure(int i)
{
	char			**figure;
	char			*s;
	int				len;
	int				j;

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

t_map				*parse_piece(void)
{
	char			*s;
	t_map			*piece;

	piece = create_map();
	if (get_next_line(0, &s))
	{
		if (ft_strstr(s, "Piece"))
		{
			piece->x = parse_xy(s, 'x');
			piece->y = parse_xy(s, 'y');
		}
		free(s);
	}
	piece->map = parse_figure(piece->y);
	return (piece);
}
