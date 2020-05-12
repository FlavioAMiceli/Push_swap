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

static void	sift_to_b(t_stacks *s, int pivot, int len)
{
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
	ft_putchar('\n');
	ft_putendl("sift_to_b");
	ft_putstr("Part len: ");
	ft_putnbr(len);
	ft_putstr(" Pivot : ");
	ft_putnbr(pivot);
	ft_putchar('\n');
	while (pushed < len)
	{
		if (stack_get(s->a, 0) <= pivot)
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
	if (rotated != s->a->len)
	{
		while (rotated > 0)
		{
			rev_rot(&(s->a));
			ft_putendl("rra");
			rotated--;
		}
	}
}

static void	sift_to_a(t_stacks *s, int pivot, int len)
{
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
	ft_putchar('\n');
	ft_putendl("sift_to_a");
	ft_putstr("Part len: ");
	ft_putnbr(len);
	ft_putstr(" Pivot : ");
	ft_putnbr(pivot);
	ft_putchar('\n');
	while (pushed < len)
	{
		if (stack_get(s->b, 0) > pivot)
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
	if (rotated != s->b->len)
	{
		while (rotated > 0)
		{
			rev_rot(&(s->b));
			ft_putendl("rrb");
			rotated--;
		}
	}
}

static void	partition_to_a(t_stacks *s, int *sorted, int lo, int hi)
{
	int	pivot_i;

	ft_putchar('\n');
	ft_putendl("part_a");
	ft_putstr("Part len: ");
	ft_putnbr(hi - lo + 1);
	ft_putchar('\n');
	stack_print(s->a);
	stack_print(s->b);
	if ((hi - lo) + 1 <= BASE_CASE_LEN)
		bc_to_a(s, lo, hi);
	else
	{
		ft_putstr("Hi: ");
		ft_putnbr(hi);
		ft_putstr(" Lo: ");
		ft_putnbr(lo);
		ft_putchar('\n');
		pivot_i = (lo + hi) / 2;
		sift_to_a(s, sorted[pivot_i], hi - pivot_i);
		partition_to_b(s, sorted, pivot_i + 1, hi);
		partition_to_a(s, sorted, lo, pivot_i);
	}
}

void		partition_to_b(t_stacks *s, int *sorted, int lo, int hi)
{
	int	pivot_i;

	ft_putchar('\n');
	ft_putendl("part_b");
	ft_putstr("Part len: ");
	ft_putnbr(hi - lo + 1);
	ft_putchar('\n');
	stack_print(s->a);
	stack_print(s->b);
	if ((hi - lo) + 1 <= BASE_CASE_LEN)
		bc_to_b(s, lo, hi);
	else
	{
		ft_putstr("Hi: ");
		ft_putnbr(hi);
		ft_putstr(" Lo: ");
		ft_putnbr(lo);
		ft_putchar('\n');
		pivot_i = (lo + hi) / 2;
		sift_to_b(s, sorted[pivot_i], pivot_i - lo + 1);
		partition_to_b(s, sorted, pivot_i + 1, hi);
		partition_to_a(s, sorted, lo, pivot_i);
	}
}
