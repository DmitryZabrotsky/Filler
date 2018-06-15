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

#include "../visualizer.h"

t_map		*create_map(void)
{
	t_map		*ret;

	if ((ret = (t_map *)malloc(sizeof(t_map))))
	{
		ret->x = 0;
		ret->y = 0;
		ret->map = NULL;
		ret->plateau = NULL;
		ret->end_x = 0;
		ret->end_y = 0;
		// ret->score_o = NULL;
		// ret->score_x = NULL;
	}
	return (ret);
}

void		del_map(t_map **del)
{
	if (*del)
	{
		if ((*del)->map)
			ft_arrfree(&(*del)->map);
		if ((*del)->plateau)
			free((*del)->plateau);
		// if ((*del)->score_o)
		// 	free((*del)->score_o);
		// if ((*del)->score_x)
		// 	free((*del)->score_x);
		free(*del);
	}
	*del = NULL;
}

// t_res		*create_res(void)
// {
// 	t_res		*ret;

// 	if ((ret = (t_res *)malloc(sizeof(t_map))))
// 	{
// 		ret->score_o = NULL;
// 		ret->score_x = NULL;
// 	}
// 	return (ret);
// }

// void		del_res(t_res **del)
// {
// 	if (*del)
// 	{
// 		if ((*del)->score_o)
// 			free((*del)->score_o);
// 		if ((*del)->score_x)
// 			free((*del)->score_x);
// 		free(*del);
// 	}
// 	*del = NULL;
// }

void		put_arr(char **arr, int len)
{
	int		i;

	i = 2;
	ft_putstr_fd(YELLOW, 2);
	ft_putendl_fd(arr[0], 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd(YELLOW, 2);
	ft_putendl_fd(arr[1], 2);
	ft_putstr_fd(RESET, 2);
	while (i != len)
	{
		ft_putstr_fd(BLUE, 2);
		ft_putendl_fd(arr[i], 2);
		ft_putstr_fd(RESET, 2);
		i++;
	}
}
