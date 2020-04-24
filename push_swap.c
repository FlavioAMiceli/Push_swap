/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 18:05:33 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/14 18:05:34 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./heuristic_search/heuristic_search.h"

static int		is_sorted(\
	t_stack **stack_a, t_stack **stack_b, int *sorted, int n)
{
	shift_stack(stack_a);
	if ((*stack_b)->len != 0
	|| ft_memcmp(sorted, (*stack_a)->stack, n * sizeof(int)) != 0)
	{
		del_stacks(stack_a, stack_b);
		return (FALSE);
	}
	del_stacks(stack_a, stack_b);
	return (TRUE);
}

static void push_swap(t_stacks *s, int *sorted, int n)
{
	partition_to_b(s, sorted, 0, n - 1);
	// if (n <= BASE_CASE_LEN)
	// 	basecase_heuristic(a, b, n, 0);
	// else
	// 	partition_to_b(&s, sorted, 0, n - 1);
	stack_print(s->a);
	stack_print(s->b);
	if (!is_sorted(&(s->a), &(s->b), sorted, n))
		ft_putendl_fd("Stack was not sorted! Go fix the code!", 2);
}

int			main(int argc, char **argv)
{
	t_stacks	s;
	// t_stack	*stack_a;
	// t_stack	*stack_b;
	int			sorted_tab[argc - 1];

	if (argc < 2 || tab_is_valid(&argv[1], argc - 1) == FALSE)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	init_stacks(&(s.a), &(s.b), &argv[1], argc - 1);
	(void)set_tab(sorted_tab, &argv[1], argc - 1);
	(void)ft_quicksort(sorted_tab, argc - 1);
	push_swap(&s, sorted_tab, argc - 1);
	return (0);
}
