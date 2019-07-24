/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   merge.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 15:00:41 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/07/24 15:00:42 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void merge_asc(t_stack **src, t_stack **dst, int to_a, t_lenghts *len)
{
	while (len->bottom || len->top)
	{
		if (len->top && len->bottom && *(*src)->start < *(*src)->end)
		{
			push(src, dst);
			(len->bottom)--;
			if (to_a)
				ft_putendl("pa");
			else
				ft_putendl("pb");
		}
		else
		{
			rot(src);
			push(src, dst);
			(len->top)--;
			if (to_a)
				ft_putendl("rb\npa");
			else
				ft_putendl("ra\npb");
		}
	}
}

void merge_desc(t_stack **src, t_stack **dst, int to_a, t_lenghts *len)
{
	while (len->bottom || len->top)
	{
		if (len->top && len->bottom && *(*src)->start > *(*src)->end)
		{
			push(src, dst);
			(len->bottom)--;
			if (to_a)
				ft_putendl("pa");
			else
				ft_putendl("pb");
		}
		else
		{
			rot(src);
			push(src, dst);
			(len->top)--;
			if (to_a)
				ft_putendl("rb\npa");
			else
				ft_putendl("ra\npb");
		}
	}
}
