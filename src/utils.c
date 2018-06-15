/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:18:29 by dzabrots          #+#    #+#             */
/*   Updated: 2018/06/14 17:18:31 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

t_map		*create_map(void)
{
	t_map		*ret;

	if ((ret = (t_map *)malloc(sizeof(t_map))))
	{
		ret->x = 0;
		ret->y = 0;
		ret->map = NULL;
		ret->end_x = 0;
		ret->end_y = 0;
	}
	return (ret);
}

t_int_map	*create_int_map(int y, int x)
{
	t_int_map *ret;

	if ((ret = (t_int_map *)malloc(sizeof(t_int_map))))
	{
		ret->int_arr = NULL;
		ret->y = y;
		ret->x = x;
		ret->target = 1;
		ret->num = 2;
	}
	return (ret);
}

void		del_map(t_map **del)
{
	if (*del)
	{
		if ((*del)->map)
			ft_arrfree(&(*del)->map);
		free(*del);
	}
	*del = NULL;
}

void		del_int_map(t_int_map **del)
{
	int		i;

	if (*(del) && (*del)->int_arr)
	{
		i = 0;
		while (i < (*del)->y)
		{
			free((*del)->int_arr[i]);
			i++;
		}
		free((*del)->int_arr);
	}
	free(*del);
	*del = NULL;
}

void		put_arr(char **arr, int len)
{
	int		i;

	i = 0;
	while (i != len)
	{
		ft_putstr_fd(YELLOW, 2);
		ft_putendl_fd(arr[i], 2);
		ft_putstr_fd(RESET, 2);
		i++;
	}
}
