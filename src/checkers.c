#include "../filler.h"

static int		check_coord(int x, int y, t_map *map, t_map *piece)
{
	char p;
	char e;
	int i;
	int j;

	g_overlap = 0;
	p = ft_strequ(g_player, "p1") ? 'O' : 'X'; // + 32 to lower
	e = ft_strequ(g_player, "p1") ? 'X' : 'O';
	i = 0;
	
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

void		will_put(t_map *map, t_map *piece)
{
	//char *res;
	int end_x;
	int end_y;
	int i;
	int j;

	end_x = map->x - piece->x + 1;
	end_y = map->y - piece->y + 1;
	i = 0;
	while (i <= end_x)
	{
		j = 0;
		while (j <= end_y)
		{
			if (check_coord(i, j, map, piece)) // ????

			j++;
		}
		i++;
	}
}