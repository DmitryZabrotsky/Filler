#ifndef FILLER_H
# define FILLER_H

# include "./libft/incl/libft.h"
# include <stdio.h>

char	*g_player;
char	g_plr;
char	g_enm;
int		g_overlap;

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

#endif