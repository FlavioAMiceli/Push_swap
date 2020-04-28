/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sift.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 19:42:26 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/10 19:42:26 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./heuristic_search/heuristic_search.h"
#include <stdio.h> // remove

static void	sift_to_b(t_stacks *s, int pivot, int len)
{
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
	// printf("\tsift_to_b\n\tpivot: %d len: %d\n", pivot, len);
	// stack_print(s->a);
	// stack_print(s->b);
	while (pushed < len)
	{
		if (stack_get(s->a, 0) < pivot)
		{
			push(&(s->a), &(s->b));
			ft_putendl("pb");
			pushed++;
			continue ;
		}
		rot(&(s->a));
		ft_putendl("ra");
		rotated++;
	}
	while (rotated > 0)
	{
		rev_rot(&(s->a));
		ft_putendl("rra");
		rotated--;
	}
}

static void	sift_to_a(t_stacks *s, int pivot, int len)
{
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
	// printf("\tsift_to_a\n\tpivot: %d len: %d\n", pivot, len);
	// stack_print(s->a);
	// stack_print(s->b);
	while (pushed < len)
	{
		if (stack_get(s->b, 0) >= pivot)
		{
			push(&(s->b), &(s->a));
			ft_putendl("pa");
			pushed++;
			continue ;
		}
		rot(&(s->b));
		ft_putendl("rb");
		rotated++;
	}
	while (rotated > 0)
	{
		rev_rot(&(s->b));
		ft_putendl("rrb");
		rotated--;
	}
}

static void partition_to_a(t_stacks *s, int *sorted, int lo, int hi)
{
	int	pivot_i;
	// TODO: Instead of bc on single stack, always sift and then check for bc.
	// printf("\tto_a\n");
	// printf("\tlo: %d hi: %d\n", lo, hi);
	if ((hi - lo) + 1 <= BASE_CASE_LEN)
	{
		if ((hi - lo) + 1 <= 3)
			bc_to_a(s, lo, hi);
		else
			basecase_heuristic(&(s->a), &(s->b), 0, (hi - lo) + 1);
	}
	else
	{
		pivot_i = (lo + hi) / 2;
		sift_to_a(s, sorted[pivot_i], (hi - pivot_i) + 1);
		partition_to_b(s, sorted, pivot_i + 1, hi);
		partition_to_a(s, sorted, lo, pivot_i);
	}
}

void 		partition_to_b(t_stacks *s, int *sorted, int lo, int hi)
{
	int	pivot_i;
	// TODO: Instead of bc on single stack, always sift and then check for bc.
	// printf("\tto_b\n");
	// printf("\tlo: %d hi: %d\n", lo, hi);
	if ((hi - lo) + 1 <= BASE_CASE_LEN)
	{
		if ((hi - lo) + 1 <= 3)
			bc_to_b(s, lo, hi);
		else
			basecase_heuristic(&(s->a), &(s->b), (hi - lo) + 1, 0);
	}
	else
	{
		pivot_i = (lo + hi + 1) / 2;
		sift_to_b(s, sorted[pivot_i], pivot_i - lo);
		partition_to_b(s, sorted, pivot_i, hi);
		partition_to_a(s, sorted, lo, pivot_i - 1);
	}
}
