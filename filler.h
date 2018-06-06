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

typedef struct s_map
{
	int			x;
	int			y;
	char		**map;
}				t_map;

t_map	*create_map(void);
void	del_map(t_map **del);
void	put_arr(char **arr, int len);

void	will_put(t_map *map, t_map *piece);

void	find_location(t_map *map);
#endif