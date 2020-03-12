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

void bc_to_b(t_stacks *s, int lo, int hi)
{
	if ((hi - lo) + 1 == 1)
		return ;
	else if (stack_get(s->a, 0) > stack_get(s->a, 1))
	{
		swap(&(s->a));
		ft_putendl("sa");
	}
}

void bc_to_a(t_stacks *s, int lo, int hi)
{
	if ((hi - lo) + 1 == 1)
	{
		push(&(s->b), &(s->a));
		ft_putendl("pa");
	}
	else if (stack_get(s->b, 0) > stack_get(s->b, 1))
	{
		push(&(s->b), &(s->a));
		push(&(s->b), &(s->a));
		ft_putendl("pa\npa");
	}
	else
	{
		swap(&(s->b));
		push(&(s->b), &(s->a));
		push(&(s->b), &(s->a));
		ft_putendl("sb\npa\npa");
	}
}
