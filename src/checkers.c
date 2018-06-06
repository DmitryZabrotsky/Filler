#include "../filler.h"

static int		check_coord(int y, int x, t_map *map, t_map *piece)
{
	int i;
	int j;
	int end_x;
	int end_y;

	end_x = map->x - piece->x + 1;
	end_y = map->y - piece->y + 1;
	g_overlap = 0;
	i = 0;
	while (i < piece->y)
	{
		j = 0;
		while (j < piece->x)
		{	
			if (i + y > end_y || j + x > end_x)
				return (0);
			if ((piece->map)[i][j] == '*')
			{
				if ((map->map)[i + y][j + x] == g_plr ||
					(map->map)[i + y][j + x] == g_plr + 32)
					g_overlap++;
				if ((map->map)[i + y][j + x] == g_enm ||
					(map->map)[i + y][j + x] == g_enm + 32)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (g_overlap == 1 ?  1 : 0);
}

static int		check_upper(int i, int j, t_map *map)
{
	int y;
	int x;

	y = g_bufy;
	x = g_bufx;
	if (i + y + 1 < map->y)
	{
		if (j + x - 1 >= 0)
		{
			if ((map->map)[i + y + 1][j + x - 1] == g_enm ||
				(map->map)[i + y + 1][j + x - 1] == g_enm + 32)
			return (1);
		}
		if (j + x + 1 < map->x)
		{
			if ((map->map)[i + y + 1][j + x + 1] == g_enm ||
				(map->map)[i + y + 1][j + x + 1] == g_enm + 32)
			return (1);
		}
		if ((map->map)[i + y + 1][j + x] == g_enm ||
			(map->map)[i + y + 1][j + x] == g_enm + 32)
		return (1);
	}
	return (0);
}

static int		check_near(int i, int j, t_map *map)
{
	int y;
	int x;

	y = g_bufy;
	x = g_bufx;
	if (j + x - 1 >= 0)
	{
		if ((map->map)[i + y][j + x - 1] == g_enm ||
			(map->map)[i + y][j + x - 1] == g_enm + 32)
		return (1);
	}
	if (j + x + 1 < map->x)
	{
		if ((map->map)[i + y][j + x + 1] == g_enm ||
			(map->map)[i + y][j + x + 1] == g_enm + 32)
		return (1);
	}
	return (0);
}

static int		check_lower(int i, int j, t_map *map)
{
	int y;
	int x;

	y = g_bufy;
	x = g_bufx;
	if (i + y - 1 >= 0)
	{
		if (j + x - 1 >= 0)
		{
			if ((map->map)[i + y - 1][j + x] == g_enm ||
				(map->map)[i + y - 1][j + x] == g_enm + 32)
			return (1);
		}
		if (j + x + 1 < map->x)
		{
			if ((map->map)[i + y - 1][j + x] == g_enm ||
				(map->map)[i + y - 1][j + x] == g_enm + 32)
			return (1);
		}
		if ((map->map)[i + y - 1][j + x] == g_enm ||
			(map->map)[i + y - 1][j + x] == g_enm + 32)
		return (1);
	}
	return (0);
}

static int		enm_near(int y, int x, t_map *map, t_map *piece)
{
	int i;
	int j;
	int end_x;
	int end_y;

	g_bufy = y;
	g_bufx = x;
	end_x = map->x - piece->x + 1;
	end_y = map->y - piece->y + 1;
	i = 0;
	while (i < piece->y)
	{
		j = 0;
		while (j < piece->x)
		{
			if (i + y > end_y || j + x > end_x)
				return (0);
			if ((piece->map)[i][j] == '*')
			{
				if (check_upper(i, j, map) ||
					check_near(i, j, map) ||
					check_lower(i, j, map))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static void		go_down(int end_y, int end_x, t_map *map, t_map *piece)
{
	int i;
	int j;

	i = 0;
	while (i < end_y)
	{
		j = 0;
		while (j < end_x)
		{
			if (check_coord(i, j, map, piece))
			{
				g_resi = i;
				g_resy = j;
				if (enm_near(i, j, map, piece))
					break ;
				// ft_putstr_fd(CYAN, 2);
				// ft_putstr_fd(ft_itoa(i), 2);
				// ft_putstr_fd(":", 2);
				// ft_putstr_fd(ft_itoa(j), 2);
				// ft_putstr_fd(" ", 2);
				// ft_putstr_fd(RESET, 2);
			}
			j++;
		}
		i++;
	}
}

static void		go_up(int end_y, int end_x, t_map *map, t_map *piece)
{
	int i;
	int j;

	i = end_y - 1;
	while (i)
	{
		j = end_x - 1;
		while (j)
		{
			// ft_putstr_fd(ft_itoa(i), 2);
			// ft_putstr_fd(" ", 2);
			// ft_putstr_fd(ft_itoa(j), 2);
			// ft_putendl_fd("", 2);
			if (check_coord(i, j, map, piece))
			{
				g_resi = i;
				g_resy = j;
				if (enm_near(i, j, map, piece))
					break ;
			}
			j--;
		}
		i--;
	}
}

void		will_put(t_map *map, t_map *piece)
{
	//char *res;
	int end_x;
	int end_y;

	g_resi = 0;
	g_resy = 0;
	end_y = map->y - piece->y + 1;
	end_x = map->x - piece->x + 1;
	if (g_plr_y < g_enm_y)
		go_down(end_y, end_x, map, piece);
	if (g_plr_y > g_enm_y)
		go_up(end_y, end_x, map, piece);
	// ft_putstr_fd(GREEN, 2);
	// ft_putstr_fd(ft_itoa(resi), 2);
	// ft_putstr_fd(" ", 2);
	// ft_putstr_fd(ft_itoa(resy), 2);
	// ft_putendl_fd("", 2);
	// ft_putstr_fd(RESET, 2);
	ft_putstr_fd(ft_itoa(g_resi), 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(ft_itoa(g_resy), 1);
	ft_putstr_fd("\n", 1);
}