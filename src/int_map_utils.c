/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:17:48 by dzabrots          #+#    #+#             */
/*   Updated: 2018/06/14 17:17:51 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int			if_still_zero(int y, int x, int **int_arr)
{
	int		i;
	int		j;
	int		res;

	res = 0;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (int_arr[i][j] == 0)
				res++;
			j++;
		}
		i++;
	}
	return (res ? 1 : 0);
}

void		fill_int_map(int y, int x, t_map *map, t_int_map *int_map)
{
	int		i;
	int		j;

	int_map->int_arr = (int **)malloc(sizeof(int *) * y);
	i = 0;
	while (i < y)
	{
		int_map->int_arr[i] = (int *)malloc(sizeof(int) * x);
		j = 0;
		while (j < x)
		{
			if (map->map[i][j] == g_enm || map->map[i][j] == g_enm + 32)
				int_map->int_arr[i][j] = 1;
			else
				int_map->int_arr[i][j] = 0;
			j++;
		}
		i++;
	}
}
