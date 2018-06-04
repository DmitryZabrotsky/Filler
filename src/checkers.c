#include "../filler.h"

static int		check_coord(int y, int x, t_map *map, t_map *piece)
{
	int i;
	int j;

	g_overlap = 0;
	i = 0;
	while (i < piece->y)
	{
		j = 0;
		while (j < piece->x)
		{
			if ((piece->map)[i][j] == '*')
			{
				if ((map->map)[i + y][j + x] == g_p || (map->map)[i + y][j + x] == g_p + 32)
					g_overlap++;
				if ((map->map)[i + y][j + x] == g_e || (map->map)[i + y][j + x] == g_e + 32)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (g_overlap == 1 ?  1 : 0);
}

void		will_put(t_map *map, t_map *piece)
{
	//char *res;
	int end_x;
	int end_y;
	int i;
	int j;

	end_x = map->x - piece->x;
	end_y = map->y - piece->y;
	i = 0;
	while (i <= end_y)
	{
		j = 0;
		while (j <= end_x)
		{
			if (check_coord(i, j, map, piece))
			{
				ft_putstr_fd(CYAN, 2);
				ft_putstr_fd(ft_itoa(i), 2);
				ft_putstr_fd(":", 2);
				ft_putstr_fd(ft_itoa(j), 2);
				ft_putstr_fd(" ", 2);
				ft_putstr_fd(RESET, 2);
			}
			else
			{
				ft_putstr_fd(BLACK, 2);
				ft_putstr_fd(" ", 2);
				ft_putstr_fd(ft_itoa(i), 2);
				ft_putstr_fd(":", 2);
				ft_putstr_fd(ft_itoa(j), 2);
				ft_putstr_fd(" ", 2);
				ft_putstr_fd(RESET, 2);
			}
			j++;
		}
		i++;
	}
}

// char *make_res(int x, int y)
// {
// 	char *res;
// 	char *x;
// 	char *y;
// 	size_t xlen;
// 	size_t ylen;

// 	x = ft_itoa(x);
// 	y = ft_itoa(y);
// 	xlen = ft_strlen(x);
// 	ylen = ft_strlen(y);
// 	if ((res = ft_strnew(xlen + ylen + 3)))
// 	{
// 		ft_memcpy(res, x, xlen);
// 		ft_memcpy(res, " ", 1);
// 		ft_memcpy(res + xlen + 1, y, ylen);
// 		ft_memcpy(res + xlen + 1 + ylen, "\n", 1);
// 		res[xlen + ylen + 2] = '\0';
// 	}
// 	free(x);
// 	free(y);
// 	return (res);
// }