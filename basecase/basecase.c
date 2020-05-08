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

#include "basecase.h"

void		bc_to_b(t_stacks *s, int lo, int hi)
{
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

static void	swap_b(t_stacks *s)
{
	swap(&(s->b));
	ft_putendl("sb");
}

void		bc_to_a(t_stacks *s, int lo, int hi)
{
	if ((hi - lo) + 1 < 3)
		bc_to_a_small(s, lo, hi);
	else if (stack_get(s->b, 0) < stack_get(s->b, 2) &&
		stack_get(s->b, 1) < stack_get(s->b, 2))
	{
		if (stack_get(s->b, 0) < stack_get(s->b, 1))
			to_a_123(s);
		else
			to_a_213(s);
	}
	else if (stack_get(s->b, 0) > stack_get(s->b, 2) &&
		stack_get(s->b, 1) > stack_get(s->b, 2))
	{
		if (stack_get(s->b, 0) < stack_get(s->b, 1))
			swap_b(s);
		to_a_321(s);
	}
	else
	{
		if (stack_get(s->b, 0) < stack_get(s->b, 1))
			swap_b(s);
		to_a_312(s);
	}
}
