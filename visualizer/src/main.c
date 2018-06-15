#include "../visualizer.h"

int		main(void)
{
	t_map	*map;
	//t_res	*res;

	while (1)
	{
		map = parse_map();
		//res = parse_res();
		if (!map || (g_scoreo && g_scorex))
			break ;
		//put_arr(map->map, map->y);
		del_map(&map);
	}
	if (g_scoreo && g_scorex)
	{
		ft_putstr_fd(CYAN, 2);
		ft_putendl_fd(g_scoreo, 2);
		ft_putendl_fd(g_scorex, 2);
		ft_putstr_fd(RESET, 2);
	}
	return (0);
}