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

// More error checks. Empty input, letters as input,
// size of input int out of bound for int.

// static int		is_sorted(\
// 	t_stack **stack_a, t_stack **stack_b, int *sorted, int n)
// {
// 	shift_stack(stack_a);
// 	if ((*stack_b)->len != 0
// 	|| ft_memcmp(sorted, (*stack_a)->start, n * sizeof(int)) != 0)
// 	{
// 		del_stacks(stack_a, stack_b);
// 		return (FALSE);
// 	}
// 	del_stacks(stack_a, stack_b);
// 	return (TRUE);
// }

static int		get_pivot(int low, int high, int *sorted)
{
	return (sorted[low + ((low + high) / 2)]);
}

static t_list	*partition_to_b(
	t_stacks **stacks, int pivot, int lo, int hi)
{
	n = (hi - lo) / 2;
	while (n)
	{
		if ((*stacks)->a->head > pivot)
		{
			push((*stacks)->a, (*stacks)->b);
			ft_lstadd(*ops, ft_lstnew("pb", 3));
			n--;
		}
		else
		{
			rot((*stack)->a);
			ft_lstadd(*ops, ft_lstnew("ra", 3));
		}
	}
	lo += (lo + hi) / 2;
	pivot = get_pivot(lo, hi, sorted);
	ft_lstappend(&ops, partition_to_a(stacks, pivot, lo, hi));
	return (ops);
}

static void		push_swap(t_stacks **stacks, int *sorted)
{
	t_list	*ops;
	int		pivot;
	int		lo;
	int		hi;
	int		i;

	lo = 0;
	while (is_sorted(
		(*stacks)->a, (*stacks)->b, sorted, (*stacks)->a->len) == FALSE)
	{
		i = 0;
		hi = (*stacks)->a->size - 1;
		pivot = get_pivot(lo, hi, sorted);
		ft_lstappend(&ops, partition_to_b(stacks, pivot, lo, hi));
		hi = lo + ((hi - lo) / 2);
		pivot = get_pivot(lo, hi, sorted);
		ft_lstappend(&ops, partition_to_a(stacks, pivot, lo, hi));
		lo = hi;
	}
}

int				main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			sorted_tab[argc - 1];

	if (argc < 2 || tab_is_valid(&argv[1], argc - 1) == FALSE)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	init_stacks(&(stacks->a), &(stacks->b), &argv[1], argc - 1);
	(void)set_tab(sorted_tab, &argv[1], argc - 1);
	(void)ft_quicksort(sorted_tab, argc - 1);
	push_swap(&stacks, sorted_tab);
	return (0);
}
