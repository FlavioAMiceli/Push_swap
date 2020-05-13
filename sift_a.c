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

void	sift_to_a(t_stacks *s, int pivot, int len)
{
	int	pushed;
	int	rotated;

	pushed = 0;
	rotated = 0;
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
