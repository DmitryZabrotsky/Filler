#include "../visualizer.h"

static void	print_cols(char *s)
{
		ft_putstr_fd(WHITE, 2);
		ft_putendl_fd(s, 2);
		ft_putstr_fd(RESET, 2);
}

static void	print_rows(char *s)
{
	int i;
	
	i = 0;
	while (i <= 3)
	{
		ft_putstr_fd(WHITE, 2);
		ft_putchar_fd(s[i], 2);
		ft_putstr_fd(RESET, 2);
		i++;
	}
}

static void	print_chars(char *s, int x)
{
	int i;
	
	i = 3;
	while (i < x + 4)
	{
		if (s[i] == '.')
		{
			ft_putstr_fd(BLACK, 2);
			ft_putchar_fd(s[i], 2);
			ft_putstr_fd(RESET, 2);
		}
		else if (s[i] == 'O' || s[i] == 'o')
		{
			ft_putstr_fd(BLUE, 2);
			ft_putchar_fd(s[i], 2);
			ft_putstr_fd(RESET, 2);
		}
		else if (s[i] == 'X' || s[i] == 'x')
		{
			ft_putstr_fd(YELLOW, 2);
			ft_putchar_fd(s[i], 2);
			ft_putstr_fd(RESET, 2);
		}
		i++;
	}
}

void				print_line(char *s, int x)
{
	int i;
	i = 0;

	if (ft_strstr(s, "0123456789"))
		print_cols(s);
	else if (s[3] == ' ')
	{
		print_rows(s);
		print_chars(s, x);
		ft_putendl_fd("", 2);
	}
}
