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
}				t_map;

t_map			*create_map(void);

void			parse_player(void);
t_map			*parse_map(void);

void			print_line(char *s, int x);

#endif