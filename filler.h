#ifndef FILLER_H
# define FILLER_H

# include "./libft/incl/libft.h"
# include <stdio.h>

char	*g_player;
char	g_plr;
char	g_enm;
int		g_overlap;
int		g_plr_y;
int		g_plr_x;
int		g_enm_y;
int		g_enm_x;
int		g_value;
int 	g_resy;
int 	g_resx;

int		g_bufy;
int		g_bufx;

typedef struct s_map
{
	int			x;
	int			y;
	char		**map;
	int			end_x;
	int			end_y;
}				t_map;

typedef struct s_int_map
{
	int			**int_arr;
	int			y;
	int			x;
	int			target;
	int			num;	
}				t_int_map;

t_map	*create_map(void);
t_int_map	*create_int_map(int y, int x); //

void	parse_player(void);
t_map	*parse_map(void);
t_map	*parse_piece(void);

void	del_map(t_map **del);
void	put_arr(char **arr, int len);
void	del_int_map(t_int_map **del);

void	will_put(t_map *map, t_map *piece);
void	handle_coords(int y, int x, t_map *piece, t_map *map); //

void	find_location(t_map *map);

int		check_coord(int y, int x, t_map *map, t_map *piece);
int		if_enm_near(t_map *map, t_map *piece);
int		is_enm_near(int x, int y, t_map *map);

void		move_to_1(t_map *map, t_map *piece);
void		move_to_2(t_map *map, t_map *piece);
void		move_to_3(t_map *map, t_map *piece);
void		move_to_4(t_map *map, t_map *piece);

void		move_near_enm_1(t_map *map, t_map *piece);
void		move_near_enm_2(t_map *map, t_map *piece);
void		move_near_enm_3(t_map *map, t_map *piece);
void		move_near_enm_4(t_map *map, t_map *piece);

#endif