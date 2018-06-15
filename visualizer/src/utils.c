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
	}
	return (ret);
}

void		put_arr(char **arr, int len)
{
	int		i;

	i = 0;
	while (i != len)
	{
		ft_putstr_fd(BLUE, 2);
		ft_putendl_fd(arr[i], 2);
		ft_putstr_fd(RESET, 2);
		i++;
	}
}
