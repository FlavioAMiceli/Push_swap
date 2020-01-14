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

static int		get_pivot(int lo, int hi, int *sorted)
{
	return (sorted[low + ((low + high) / 2)]);
}

// static void		to_b(t_stack **a, t_stack **b, int pivot, int lo, int hi)
// {
// 	n = (hi - lo) / 2;
// 	while (n)
// 	{
// 		if (A_HEAD > pivot)
// 		{
// 			push(a, b);
// 			ft_putendl("pb");
// 			n--
// 		}
// 		else
// 		{
// 			rot(a);
// 			ft_putendl("ra");
// 		}
// 	}
// }
//
// static void		to_a(t_stack **a, t_stack **b, int pivot, int lo, int hi)
// {
// 	n = (hi - lo) / 2;
// 	while (n)
// 	{
// 		if (B_HEAD > pivot)
// 		{
// 			push(b, a);
// 			ft_putendl("pa");
// 			n--
// 		}
// 		else
// 		{
// 			rot(b);
// 			ft_putendl("rb");
// 		}
// 	}
// }

static void		push_swap(t_stack **a, t_stack **b, int *sorted)
{
	lo = 0;
	hi = A_SIZE - 1;
	while (A_LEN > BASE_CASE_LEN)
	{
		pivot = get_pivot(lo, hi, sorted);
		to_b(a, b, pivot, lo, hi);
		hi = lo + ((hi - lo) / 2);
		// ADD HI TO LINKED LIST, USE LINKED LIST FOR LO AND HI BOUNDS IN NEXT WHILE LOOP?
	}
	// RUN BASECASE ONCE OR TWICE, THEN PUSH TO A TILL BC REACHED AGAIN. REPEAT.
	while (B_LEN > BASE_CASE_LEN) //MAYBE WHILE LL IS NOT NULL or 1 LONG?
	{
		// IF BASECASE? RUN THAT INSTEAD?
		to_a(a, b, pivot, lo, hi);
	}
}

// TODO
// size of input int out of bound for int.

static void 	put_stack(t_stack **s)
{
	int	i;

	i = 0;
	while (&(S_START[i]) <= &(S_STACK[S_SIZE - 1]))
	{
		ft_putnbr(S_START[i]);
		i++;
	}
	i = 0;
	while (&(S_STACK[i] < S_START)
	{
		ft_putnbr(S_STACK[i]);
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	int		sorted_tab[argc - 1];

	if (argc < 2 || tab_is_valid(&argv[1], argc - 1) == FALSE)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	init_stacks(&a, &b, &argv[1], argc - 1);
	(void)set_tab(sorted_tab, &argv[1], argc - 1);
	(void)ft_quicksort(sorted_tab, argc - 1);
	if (no_duplicates(sorted_tab) == FALSE)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	push_swap(&a, &b, sorted_tab);
	put_stack(&a);
	return (0);
}
