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
	if (ft_strcmp(op, "sa") == 0)
		return (swap(stack_a));
	else if (ft_strcmp(op, "sb") == 0)
		return (swap(stack_b));
	else if (ft_strcmp(op, "ss") == 0)
		return (ft_min(swap(stack_a), swap(stack_b)));
	else if (ft_strcmp(op, "pa") == 0)
		return (push(stack_a, stack_b));
	else if (ft_strcmp(op, "pb") == 0)
		return (push(stack_b, stack_a));
	else if (ft_strcmp(op, "ra") == 0)
		return (rotate(stack_a));
	else if (ft_strcmp(op, "rb") == 0)
		return (rotate(stack_b));
	else if (ft_strcmp(op, "rr") == 0)
		return (ft_min(rotate(stack_a), rotate(stack_b)));
	else if (ft_strcmp(op, "rra") == 0)
		return (reverse_rotate(stack_a));
	else if (ft_strcmp(op, "rrb") == 0)
		return (reverse_rotate(stack_b));
	else if (ft_strcmp(op, "rrr") == 0)
		return (ft_min(reverse_rotate(stack_a), reverse_rotate(stack_b)));
	return (FALSE);
}

static int		is_sorted(t_list **stack_a, t_list **stack_b, char **tab, int n)
{
	t_list	*node;
	int		sorted[n];
	int		i;

	i = 0;
	while (i < n)
	{
		sorted[i] = ft_atoi(tab[i]);
		i++;
	}
	ft_quicksort(sorted, n);
	i = 0;
	while (i < n)
	{
		node = ft_lstdequeue(stack_a);
		if (sorted[i] != *((int *)(node->content)) || *stack_b != NULL)
		{
			free(sorted);
			ft_lstdel(&node, ft_nodedel);
			return (FALSE);
		}
		ft_lstdelone(&node, ft_nodedel);
		i++;
	}
	return (TRUE);
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
