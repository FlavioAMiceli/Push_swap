/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 16:14:48 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/14 16:14:49 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		tab_is_valid(char **tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (ft_isdigit(tab[i][j]) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static t_list	*set_stack(t_list **addr_stack, char **tab, int len)
{
	int	i;
	int	*num;

	i = len - 1;
	while (i >= 0)
	{
		num = (int *)malloc(sizeof(int));
		*num = ft_atoi(tab[i]);
		ft_lstadd(addr_stack, ft_lstnew(num, sizeof(int)));
		i--;
	}
	return (*addr_stack);
}

static int		do_instruction(char *op, t_list **stack_a, t_list **stack_b)
{
	(void)op;
	(void)stack_a;
	(void)stack_b;
	return (FALSE);
}

static int		is_sorted(t_list **stack_a, t_list **stack_b, char **tab, int n)
{
	(void)stack_a;
	(void)stack_b;
	(void)tab;
	(void)n;
	return (FALSE);
}

int				main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;
	int		is_valid;
	int		ret;

	if (argc < 2 || tab_is_valid(&argv[1], argc - 1) == FALSE)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	stack_a = set_stack(&stack_a, &argv[1], argc - 1);
	ret = get_next_line(0, &line);
	while (ret != 0)
	{
		is_valid = do_instruction(line, &stack_a, &stack_b);
		if (is_valid == FALSE)
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		free(line);
		ret = get_next_line(0, &line);
	}
	is_valid = is_sorted(&stack_a, &stack_b, &argv[1], argc - 1);
	{
		ft_putendl_fd("KO", 2);
		return (1);
	}
	ft_putendl_fd("OK", 2);
	return (1);
}
