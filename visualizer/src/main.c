#include "../visualizer.h"
static void	winner_o(void)
{
		ft_putstr_fd(RED, 2);
		ft_putendl_fd(g_scoreo + 2, 2);
		ft_putstr_fd(RESET, 2);
		ft_putstr_fd(GREEN, 2);
		ft_putendl_fd(g_scorex + 2, 2);
		ft_putstr_fd(RESET, 2);
}

static void	winner_x(void)
{
		ft_putstr_fd(GREEN, 2);
		ft_putendl_fd(g_scoreo + 2, 2);
		ft_putstr_fd(RESET, 2);
		ft_putstr_fd(RED, 2);
		ft_putendl_fd(g_scorex + 2, 2);
		ft_putstr_fd(RESET, 2);
}

static void	winners_xy(void)
{
		ft_putstr_fd(CYAN, 2);
		ft_putendl_fd(g_scoreo + 2, 2);
		ft_putendl_fd(g_scorex + 2, 2);
		ft_putstr_fd(RESET, 2);
}

int		main(void)
{
	t_map	*map;

	while (1)
	{
		map = parse_map();
		if (!map || (g_scoreo && g_scorex))
			break ;
		free(map);
	}
	if (g_scoreo && g_scorex)
	{
		ft_putendl_fd("", 2);
		if (ft_atoi(g_scorex + 9) > ft_atoi(g_scoreo + 9))
			winner_o();
		else if (ft_atoi(g_scorex + 9) < ft_atoi(g_scoreo + 9))
			winner_x();
		else
			winners_xy();
		free(g_scoreo);
		free(g_scorex);
	}
	ft_putendl_fd("", 2);
	return (0);
}