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

void				print_line(char *s, int x)
{
	int i;
	i = 0;

	if (ft_strstr(s, "0123456789"))
	{
		ft_putstr_fd(WHITE, 2);
		ft_putendl_fd(s, 2);
		ft_putstr_fd(RESET, 2);
	}
	else if (s[3] == ' ')
	{
		while (i <= 3)
		{
			ft_putstr_fd(WHITE, 2);
			ft_putchar_fd(s[i], 2);
			ft_putstr_fd(RESET, 2);
			i++;
		}
		while (i < x + 4)
		{
			if (s[i] == '.')
			{
				ft_putstr_fd(BLACK, 2);
				ft_putchar_fd(s[i], 2);
				ft_putstr_fd(RESET, 2);
			}
			else if (s[i] == 'O' || s[i] == 'o')
			{
				ft_putstr_fd(BLUE, 2);
				ft_putchar_fd(s[i], 2);
				ft_putstr_fd(RESET, 2);
			}
			else if (s[i] == 'X' || s[i] == 'x')
			{
				ft_putstr_fd(YELLOW, 2);
				ft_putchar_fd(s[i], 2);
				ft_putstr_fd(RESET, 2);
			}
			i++;
		}
		ft_putendl_fd("", 2);
	}
}

static void			parse_board(int i, int x)
{
	char			*s;
	int				len;
	int				j;

	len = i;
	j = 0;
	while (j < i)
	{
		if (get_next_line(0, &s))
		{
			// ft_putstr_fd(MAGENTA, 2);
			// ft_putendl_fd(s, 2);
			// ft_putstr_fd(RESET, 2);
			print_line(s, x);
			free(s);
		}
		j++;
	}
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
			if (map->y > 90)
				usleep(110000);
			else if (map->y > 20)
				usleep(45000);
			else
				usleep(20000);
			system("clear");
			
			ft_putstr_fd(WHITE, 2);
			ft_putendl_fd(s, 2);
			ft_putstr_fd(RESET, 2);
			
			free(s);
			parse_board(map->y + 1, map->x);

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
