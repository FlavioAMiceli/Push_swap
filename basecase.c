/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basecase.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 22:45:38 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/12 22:45:39 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // remove

static void to_b_132(t_stacks *s)
{
	rot(&(s->a));
	swap(&(s->a));
	rev_rot(&(s->a));
	ft_putendl("ra\nsa\nrra");
}

static void to_b_213(t_stacks *s)
{
	swap(&(s->a));
	ft_putendl("sa");
}

static void to_b_231(t_stacks *s)
{
	rot(&(s->a));
	swap(&(s->a));
	rev_rot(&(s->a));
	swap(&(s->a));
	ft_putendl("ra\nsa\nrra\nsa");
}

static void to_b_312(t_stacks *s)
{
	rot(&(s->a));
	push(&(s->a), &(s->b));
	push(&(s->a), &(s->b));
	rev_rot(&(s->a));
	push(&(s->b), &(s->a));
	push(&(s->b), &(s->a));
	ft_putendl("ra\npb\npb\nrra\npa\npa");
}

static void to_b_321(t_stacks *s)
{
	rot(&(s->a));
	swap(&(s->a));
	push(&(s->a), &(s->b));
	push(&(s->a), &(s->b));
	rev_rot(&(s->a));
	push(&(s->b), &(s->a));
	push(&(s->b), &(s->a));
	ft_putendl("ra\nsa\npb\npb\nrra\npa\npa");
}

void bc_to_b(t_stacks *s, int lo, int hi)
{
	printf("\tbc_to_b\n");
	stack_print(s->a);
	stack_print(s->b);
	if ((hi - lo) + 1 < 3)
	{
		if ((hi - lo) + 1 == 2 &&
			stack_get(s->a, 0) > stack_get(s->a, 1))
			to_b_213(s);
	}
	else if (stack_get(s->a, 0) < stack_get(s->a, 1) &&
		stack_get(s->a, 0) < stack_get(s->a, 2))
	{
		if (stack_get(s->a, 1) > stack_get(s->a, 2))
			to_b_132(s);
	}
	else if (stack_get(s->a, 0) < stack_get(s->a, 1))
		to_b_231(s);
	else if (stack_get(s->a, 0) < stack_get(s->a, 2))
		to_b_213(s);
	else if (stack_get(s->a, 1) < stack_get(s->a, 2))
		to_b_312(s);
	else
		to_b_321(s);
}

static void	bc_to_a_small(t_stacks *s, int lo, int hi)
{
	if ((hi - lo) + 1 == 1)
	{
		push(&(s->b), &(s->a));
		ft_putendl("pa");
		return ;
	}
	else if (stack_get(s->b, 0) < stack_get(s->b, 1))
	{
		swap(&(s->b));
		ft_putendl("sb");
	}
	push(&(s->b), &(s->a));
	push(&(s->b), &(s->a));
	ft_putendl("pa\npa");
}

void bc_to_a(t_stacks *s, int lo, int hi)
{
	printf("\tbc_to_a\n");
	stack_print(s->a);
	stack_print(s->b);
	if ((hi - lo) + 1 < 3)
		bc_to_a_small(s, lo, hi);
	else if (stack_get(s->b, 0) < stack_get(s->b, 2) &&
		stack_get(s->b, 1) < stack_get(s->b, 2))
	{
		if (stack_get(s->b, 0) < stack_get(s->b, 1))
		{
			swap(&(s->b));
			ft_putendl("sb");
		}
		push(&(s->b), &(s->a));
		push(&(s->b), &(s->a));
		push(&(s->b), &(s->a));
		ft_putendl("pa\npa\npa");
	}
	else if (stack_get(s->b, 0) > stack_get(s->b, 2) ||
		stack_get(s->b, 1) > stack_get(s->b, 2))
	{
		if (stack_get(s->b, 0) < stack_get(s->b, 1))
		{
			swap(&(s->b));
			ft_putendl("sb");
		}
		push(&(s->b), &(s->a));
		swap(&(s->b));
		push(&(s->b), &(s->a));
		push(&(s->b), &(s->a));
		ft_putendl("pa\nsb\npa\npa");
	}
	else if (stack_get(s->b, 0) > stack_get(s->b, 1))
	{
		push(&(s->b), &(s->a));
		swap(&(s->b));
		push(&(s->b), &(s->a));
		swap(&(s->a));
		push(&(s->b), &(s->a));
		ft_putendl("pa\nsb\npa\nsa\npa");
	}
	else
	rot(&(s->b));
	swap(&(s->b));
	push(&(s->b), &(s->a));
	push(&(s->b), &(s->a));
	rev_rot(&(s->b));
	push(&(s->b), &(s->a));
	ft_putendl("pa\nsb\npa\nsa\npa");
}
