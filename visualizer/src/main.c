#include "../visualizer.h"

int		main(void)
{
	t_map	*map;
	//t_res	*res;

	while (1)
	{
		map = parse_map();
		//res = parse_res();
		// put_arr(map->map, map->y + 1);
		if (!map || (g_scoreo && g_scorex))
			break ;
	}
	if (g_scoreo && g_scorex)
	{
		ft_putstr_fd(GREEN, 2);
		ft_putendl_fd(g_scoreo, 2);
		ft_putendl_fd(g_scorex, 2);
		ft_putstr_fd(RESET, 2);
		free(g_scoreo);
		free(g_scorex);
	}
	return (0);
}