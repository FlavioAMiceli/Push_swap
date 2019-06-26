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

static int		do_instruction(char *op, t_list **stack_a, t_list **stack_b)
{
	return ((ft_strcmp(op, "sa") == 0 && swap(stack_a))
		|| (ft_strcmp(op, "sb") == 0 && swap(stack_b))
		|| (ft_strcmp(op, "ss") == 0 && ft_min(swap(stack_a), swap(stack_b)))
		|| (ft_strcmp(op, "pa") == 0 && push(stack_b, stack_a))
		|| (ft_strcmp(op, "pb") == 0 && push(stack_a, stack_b))
		|| (ft_strcmp(op, "ra") == 0 && rot(stack_a))
		|| (ft_strcmp(op, "rb") == 0 && rot(stack_b))
		|| (ft_strcmp(op, "rr") == 0 && ft_min(rot(stack_a), rot(stack_b)))
		|| (ft_strcmp(op, "rra") == 0 && rev_rot(stack_a))
		|| (ft_strcmp(op, "rrb") == 0 && rev_rot(stack_b))
		|| (ft_strcmp(op, "rrr") == 0 &&
		ft_min(rev_rot(stack_a), rev_rot(stack_b))));
	return (FALSE);
}

static int		is_sorted(t_list **stack_a, t_list **stack_b, char **tab, int n)
{
	int		*sorted_stack;
	int		sorted[n];
	int		i;

	i = 0;
	while (i < n)
	{
		sorted[i] = ft_atoi(tab[i]);
		i++;
	}
	ft_quicksort(sorted, n);
	sorted_stack = ft_intlstflatten(stack_a, n);
	if (*stack_b != NULL
		|| ft_memcmp(sorted, sorted_stack, n * sizeof(int)) != 0)
		return (FALSE);
	return (TRUE);
}

static	int		put_msg(char *str, int fd)
{
	ft_putendl_fd(str, fd);
	return (fd - 1);
}

int				main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;
	int		is_valid;
	int		ret;

	if (argc < 2 || tab_is_valid(&argv[1], argc - 1) == FALSE)
		return (put_msg("Error", 2));
	stack_a = set_stack(&stack_a, &argv[1], argc - 1);
	ret = get_next_line(0, &line);
	while (ret > 0)
	{
		is_valid = do_instruction(line, &stack_a, &stack_b);
		if (is_valid == FALSE)
			return (put_msg("Error", 2));
		free(line);
		ret = get_next_line(0, &line);
	}
	is_valid = is_sorted(&stack_a, &stack_b, &argv[1], argc - 1);
	if (is_valid)
		return (put_msg("OK", 1));
	return (put_msg("KO", 1));
}
