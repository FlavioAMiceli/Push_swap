/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sift_a.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 19:42:26 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/10 19:42:26 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a(t_stacks *s)
{
	push(&(s->b), &(s->a));
	ft_putendl("pa");
}

static void	rot_b(t_stacks *s)
{
	rot(&(s->b));
	ft_putendl("rb");
}

static void	rev_rot_b(t_stacks *s)
{
	rev_rot(&(s->b));
	ft_putendl("rrb");
}

void		sift_to_a(t_stacks *s, int pivot, int len)
{
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
	while (pushed < len)
	{
		if (stack_get(s->b, 0) > pivot)
		{
			push_a(s);
			pushed++;
			continue ;
		}
		rot_b(s);
		rotated++;
	}
	if (rotated != s->b->len)
	{
		while (rotated > 0)
		{
			rev_rot_b(s);
			rotated--;
		}
	}
}
