/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:19:10 by dzabrots          #+#    #+#             */
/*   Updated: 2018/06/14 17:19:15 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	parse_player(void)
{
	char *s;

	if (get_next_line(0, &s))
	{
		if (ft_strstr(s, "dzabrots.filler"))
			g_player = (ft_strstr(s, "p1") ? "p1" : "p2");
		free(s);
		g_plr = ft_strequ(g_player, "p1") ? 'O' : 'X';
		g_enm = ft_strequ(g_player, "p1") ? 'X' : 'O';
	}
}
