#include "../filler.h"

void	print_int_arr(int y, int x, int **int_arr)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			//printf("%i", int_arr[i][j]);
	
	ft_putstr_fd(BLUE, 2);
	ft_putstr_fd(ft_itoa(int_arr[i][j]), 2);
	ft_putstr_fd(RESET, 2);
	
			j++;
		}
		ft_putstr_fd("\n", 2);
		//printf("\n");
		i++;
	}
	ft_putstr_fd("\n", 2);
}

void		fill_int_map(int y, int x, t_map *map, t_int_map *int_map)
{
	int i;
	int j;

	int_map->int_arr = (int **)malloc(sizeof(int *) * y);
	
	i = 0;
	while (i < y)
	{
		int_map->int_arr[i] = (int *)malloc(sizeof(int) * x);
		j = 0;
		while (j < x)
		{
			if (map->map[i][j] == 'o' || map->map[i][j] == 'O')
				int_map->int_arr[i][j] = 1;
			else
				int_map->int_arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

int 	if_still_zero(int y, int x, int **int_arr)
{
	int i;
	int j;
	int res;

	res = 0;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (int_arr[i][j] == 0)
				res++;
			j++;
		}
		i++;
	}
	return (res ? 1 : 0);
}

int		set_num(int y, int x, t_int_map *int_map)
{
	int		j;
	int		i;

	// printf("--------------> SET NUM FUNC:\n");
	i = y == 0 ? 0 : y - 1;
	while (i > -1 && i < int_map->y && i <= y + 1)
	{
		j = x == 0 ? 0 : x - 1;
		// printf("i: %i j: %i\n", i, j);
		while (j > -1 && j < int_map->x && j <= x + 1)
		{
			if (int_map->int_arr[i][j] == 0)
				int_map->int_arr[i][j] = int_map->num;
			j++;
		}
		i++;
	}
	return (0);
}

void		handle_int_map(t_int_map *int_map)
{
	int		j;
	int		i;

	while (if_still_zero(int_map->y, int_map->x, int_map->int_arr))
	{	
		i = 0;
		while (i < int_map->y)
		{
			j = 0;
			while (j < int_map->x)
			{
				if (int_map->int_arr[i][j] == int_map->target)
					set_num(i, j, int_map);
				j++;
			}
			i++;
		}
		int_map->target++;
		int_map->num++;
		//print_int_arr(y, x, int_arr);
		//printf("\n");
	}
}

void		handle_coords(t_map *map)
{
	t_int_map	*int_map;

	int_map = create_int_map(map->y, map->x);
	fill_int_map(map->y, map->x, map, int_map);
	handle_int_map(int_map);
	print_int_arr(int_map->y, int_map->x, int_map->int_arr);
}