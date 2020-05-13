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

static void	push_b(t_stacks *s)
{
	push(&(s->a), &(s->b));
	ft_putendl("pb");
}

static void	rot_a(t_stacks *s)
{
	rot(&(s->a));
	ft_putendl("ra");
}

static void	rev_rot_a(t_stacks *s)
{
	rev_rot(&(s->a));
	ft_putendl("rra");
}

void		sift_to_b(t_stacks *s, int pivot, int len)
{
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
	while (pushed < len)
	{
		if (stack_get(s->a, 0) <= pivot)
		{
			push_b(s);
			pushed++;
			continue ;
		}
		rot_a(s);
		rotated++;
	}
	if (rotated != s->a->len)
	{
		while (rotated > 0)
		{
			rev_rot_a(s);
			rotated--;
		}
	}
}
