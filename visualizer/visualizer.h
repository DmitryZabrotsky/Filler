#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "../libft/incl/libft.h"
# include <signal.h>

char		*g_scoreo;
char		*g_scorex;

typedef struct	s_map
{
	int			x;
	int			y;
	char		**map;
	char		*plateau;
	int			end_x;
	int			end_y;
}				t_map;

// typedef struct	s_res
// {
// 	char		*score_o;
// 	char		*score_x;
// }				t_res;

t_map			*create_map(void);
// t_res			*create_res(void);

void			parse_player(void);
t_map			*parse_map(void);
// t_res			*parse_res(void);

void			put_arr(char **arr, int len);

void			del_map(t_map **del);
// void			del_res(t_res **del);

#endif