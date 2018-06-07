#include "../filler.h"

t_map	*create_map(void)
{
	t_map *ret;
	if ((ret = (t_map *)malloc(sizeof(t_map))))
	{
		ret->x = 0;
		ret->y = 0;
		ret->map = NULL;
		ret->end_x = 0;
		ret->end_y = 0;
	}
	return (ret);
}

void	del_map(t_map **del)
{
	if (*del)
	{
		if ((*del)->map)
			ft_arrfree(&(*del)->map);
		free(*del);
	}
	*del = NULL;
}

void	put_arr(char **arr, int len)
{
	int i;

	i = 0;
	while (i != len)
	{
		// ft_putstr_fd(RED, 2);
		// ft_putendl_fd("TRYING TO OUT ARR", 2);
		// ft_putstr_fd(RESET, 2);

		ft_putstr_fd(YELLOW, 2);
		ft_putendl_fd(arr[i], 2);
		ft_putstr_fd(RESET, 2);
		i++;
	}
}