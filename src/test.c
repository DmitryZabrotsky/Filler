#include "../filler.h"
#include <stdio.h>

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
			printf("%i", int_arr[i][j]);
			j++;
		}
		printf("\n");
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
	//printf("O: %i\n", res);
	return (res ? 1 : 0);
}

int		set_num(int y, int x, int num, int **map, int my, int mx)
{
	int		x1;
	int		y1;

	printf("--------------> SET NUM FUNC:\n");
	y1 = y == 0 ? 0 : y - 1;
	while (y1 > -1 && y1 < my && y1 <= y + 1)
	{
		x1 = x == 0 ? 0 : x - 1;
		printf("y1: %i x1: %i\n", y1, x1);
		while (x1 > -1 && x1 < mx && x1 <= x + 1)
		{
			//printf("before if IN SET_NUM [%i][%i] %i\n", y1, x1, map[y1][x1]);
			if (map[y1][x1] == 0)
			{
				//printf("PRISVOENIE map[%i][%i] %i => num: %i\n", y1, x1, map[y1][x1], num);
				map[y1][x1] = num;
			}
			x1++;
		}
		y1++;
	}
	return (0);
}

void func(void)
{
	int **int_arr;
	char **map;
	int y = 24;
	int x = 40;

	map = (char **)malloc(sizeof(char *) * y);

	map[0] = ft_strdup("O.......................................");
	map[1] = ft_strdup("O.......................................");
	map[2] = ft_strdup("O.......................................");
	map[3] = ft_strdup("O.......................................");
	map[4] = ft_strdup("O.......................................");
	map[5] = ft_strdup("O.......................................");
	map[6] = ft_strdup("O.......................................");
	map[7] = ft_strdup("O.......................................");
	map[8] = ft_strdup("O.......................................");
	map[9] = ft_strdup("O.......................................");
	map[10] = ft_strdup("O.......................................");
	map[11] = ft_strdup("O.......................................");
	map[12] = ft_strdup("O.......................................");
	map[13] = ft_strdup("O.......................................");
	map[14] = ft_strdup("O.......................................");
	map[15] = ft_strdup("O.......................................");
	map[16] = ft_strdup("O.......................................");
	map[17] = ft_strdup("O.......................................");
	map[18] = ft_strdup("O.......................................");
	map[19] = ft_strdup("O.......................................");
	map[20] = ft_strdup("O...............................X.......");
	map[21] = ft_strdup("O...............................X.......");
	map[22] = ft_strdup("O..............................XXXXX....");
	map[23] = ft_strdup("O.......................................");

	int i;
	int j;

	int_arr = (int **)malloc(sizeof(int *) * y);
	
	i = 0;
	while (i < y)
	{
		int_arr[i] = (int *)malloc(sizeof(int) * x);
		j = 0;
		while (j < x)
		{
			if (map[i][j] == 'o' || map[i][j] == 'O')
				int_arr[i][j] = 1;
			else
				int_arr[i][j] = 0;
			j++;
		}
		i++;
	}

	int target;
	int num;


	target = 1;
	num = 2;
	while (if_still_zero(y, x, int_arr))
	{
		// printf("still_zero in map\n");	
		i = 0;
		while (i < y)
		{
			j = 0;
			while (j < x)
			{
				//printf("finding targets: [%i][%i] %i == %i\n", i, j, int_arr[i][j], target);
				if (int_arr[i][j] == target)
				{
					//printf("PRE set_num[%i][%i] %i => num: %i\n", i, j, int_arr[i][j], num);
					set_num(i, j, num, int_arr, y, x);
				}
				j++;
			}
			i++;
		}
		target++;
		num++;
		//print_int_arr(y, x, int_arr);
		//printf("\n");
	}

	print_int_arr(y, x, int_arr);
}

int main(void)
{
	func();
}