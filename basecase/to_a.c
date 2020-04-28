/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   to_a.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 22:45:38 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/12 22:45:39 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "basecase.h"

void	bc_to_a_small(t_stacks *s, int lo, int hi)
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

void	to_a_123(t_stacks *s)
{
	rot(&(s->b));
	swap(&(s->b));
	push(&(s->b), &(s->a));
	push(&(s->b), &(s->a));
	rev_rot(&(s->b));
	push(&(s->b), &(s->a));
	ft_putendl("rb\nsb\npa\npa\nrrb\npa");
}

void	to_a_213(t_stacks *s)
{
	push(&(s->b), &(s->a));
	swap(&(s->b));
	push(&(s->b), &(s->a));
	swap(&(s->a));
	push(&(s->b), &(s->a));
	ft_putendl("pa\nsb\npa\nsa\npa");
}

void	to_a_312(t_stacks *s)
{
	push(&(s->b), &(s->a));
	swap(&(s->b));
	push(&(s->b), &(s->a));
	push(&(s->b), &(s->a));
	ft_putendl("pa\nsb\npa\npa");
}

void	to_a_321(t_stacks *s)
{
	push(&(s->b), &(s->a));
	push(&(s->b), &(s->a));
	push(&(s->b), &(s->a));
	ft_putendl("pa\npa\npa");
}
