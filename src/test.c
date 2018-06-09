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
	return (res ? 1 : 0);
}

int		set_num(int y, int x, int num, int **map, int my, int mx)
{
	int		x1;
	int		y1;

	y1 = y - 1;
	while (y1 > -1 && y1 < my && y1 <= y + 1)
	{
		x1 = x - 1;
		while (x1 > -1 && x1 < mx && x1 <= x + 1)
		{
			// printf("before if[%i][%i]%i", y1, x1, map[y1][x1]);
			if (map[y1][x1] == 0)
			{
				// printf("map[%i][%i]%i", y1, x1, map[y1][x1]);
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

	map[0] = ft_strdup("........................................");
	map[1] = ft_strdup("........................................");
	map[2] = ft_strdup("........................................");
	map[3] = ft_strdup("........................................");
	map[4] = ft_strdup("...OOOOOOO..............................");
	map[5] = ft_strdup("........OOO.............................");
	map[6] = ft_strdup("........OO..............................");
	map[7] = ft_strdup("........................................");
	map[8] = ft_strdup("........................................");
	map[9] = ft_strdup("........................................");
	map[10] = ft_strdup("........................................");
	map[11] = ft_strdup("........................................");
	map[12] = ft_strdup("........................................");
	map[13] = ft_strdup("........................................");
	map[14] = ft_strdup("........................................");
	map[15] = ft_strdup("........................................");
	map[16] = ft_strdup("........................................");
	map[17] = ft_strdup("........................................");
	map[18] = ft_strdup("........................................");
	map[19] = ft_strdup("........................................");
	map[20] = ft_strdup("................................X.......");
	map[21] = ft_strdup("................................X.......");
	map[22] = ft_strdup("...............................XXXXX....");
	map[23] = ft_strdup("........................................");

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

	int target = 1;
	int num = 2;


	while (if_still_zero(y, x, int_arr))
	{	
		i = 0;
		while (i < y)
		{
			j = 0;
			while (j < x)
			{
				//printf("map before if[%i][%i]%i\n", i, j, int_arr[i][j]);
				if (int_arr[i][j] == target)
				{
					//printf("map[%i][%i]%i", i, j, int_arr[i][j]);
					set_num( i, j, num, int_arr, y, x);
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