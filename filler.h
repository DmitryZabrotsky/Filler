/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:33:59 by dzabrots          #+#    #+#             */
/*   Updated: 2018/06/14 17:34:01 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libft/incl/libft.h"

char			*g_player;
char			g_plr;
char			g_enm;
int				g_overlap;
int				g_plr_y;
int				g_plr_x;
int				g_enm_y;
int				g_enm_x;
int				g_value;
int				g_resy;
int				g_resx;

typedef struct	s_map
{
	int			x;
	int			y;
	char		**map;
	int			end_x;
	int			end_y;
}				t_map;

typedef struct	s_int_map
{
	int			**int_arr;
	int			y;
	int			x;
	int			target;
	int			num;
}				t_int_map;

t_map			*create_map(void);
t_int_map		*create_int_map(int y, int x);

void			parse_player(void);
t_map			*parse_map(void);
t_map			*parse_piece(void);
void			find_location(t_map *map);

void			del_map(t_map **del);
void			del_int_map(t_int_map **del);
void			put_arr(char **arr, int len);

int				check_coord(int y, int x, t_map *map, t_map *piece);

int				if_still_zero(int y, int x, int **int_arr);
void			fill_int_map(int y, int x, t_map *map, t_int_map *int_map);
void			handle_coords(int y, int x, t_map *piece, t_map *map);

void			move_to_1(t_map *map, t_map *piece);
void			move_to_2(t_map *map, t_map *piece);
void			move_to_3(t_map *map, t_map *piece);
void			move_to_4(t_map *map, t_map *piece);

#endif
