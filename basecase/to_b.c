/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   to_b.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 22:45:38 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/12 22:45:39 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "basecase.h"

void	to_b_132(t_stacks *s)
{
	rot(&(s->a));
	swap(&(s->a));
	rev_rot(&(s->a));
	ft_putendl("ra\nsa\nrra");
}

void	to_b_213(t_stacks *s)
{
	swap(&(s->a));
	ft_putendl("sa");
}

void	to_b_231(t_stacks *s)
{
	rot(&(s->a));
	swap(&(s->a));
	rev_rot(&(s->a));
	swap(&(s->a));
	ft_putendl("ra\nsa\nrra\nsa");
}

void	to_b_312(t_stacks *s)
{
	rot(&(s->a));
	push(&(s->a), &(s->b));
	push(&(s->a), &(s->b));
	rev_rot(&(s->a));
	push(&(s->b), &(s->a));
	push(&(s->b), &(s->a));
	ft_putendl("ra\npb\npb\nrra\npa\npa");
}

void	to_b_321(t_stacks *s)
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
