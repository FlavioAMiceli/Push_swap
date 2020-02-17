/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heuristic_search_prep.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 06:23:15 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/14 06:23:15 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "heuristic_search.h"

/*
** Set chars from 1 to n in (*a)->stack in the same order as numbers appear
** in src->stack
*/
static void	set_src_stack(t_stack *s, t_stack **src, size_t n, int bound)
{
	size_t	i;
	size_t	j;
	char	smaller;

	if (bound)
	{
		(*src)->stack[0] = 0;
		i = 1;
	}
	else
		i = 0;
	while (i < n)
	{
		smaller = 0;
		j = 0;
		while (j < n)
		{
			if (stack_get(s, i) > stack_get(s, j))
				smaller++;
			j++;
		}
		(*src)->stack[i] = smaller + 1;
		i++;
	}
}

/*
**	Creates stacks. If original stack is larger than current partition, a bound
**	will be set at the start of the partition.
**	This 0 will be used to tell wether rotations are legal or not.
*/
static int	init_stacks_heuristic(
	t_stack *s, t_stack **src, t_stack **dst, size_t n)
{
	int	bound;

	bound = (size_t)s->len > n ? TRUE : FALSE;
	init_stacks_no_tab(src, dst, n + bound, sizeof(int));
	if (!(src && dst))
		return (FALSE);
	(*dst)->stack = (int*)ft_memalloc(sizeof(int) * (bound ? n + 1 : n));
	(*src)->stack = (int*)ft_memalloc(sizeof(int) * (bound ? n + 1 : n));
	if (!((*src)->stack && (*dst)->stack))
		return (FALSE);
	(*src)->start = (*src)->stack;
	(*src)->end = (*src)->stack + (n - (1 + bound));
	set_src_stack(s, src, (bound ? n + 1 : n), bound);
	(*dst)->start = (*dst)->stack;
	(*dst)->end = (*dst)->stack;
	return (TRUE);
}

int			basecase_heuristic(
	t_stack **src, int to_b, size_t n)
{
	t_stack	*a;
	t_stack	*b;
	char	*ops;

	if (to_b)
	{
		if(!init_stacks_heuristic(*src, &a, &b, n))
		{
			del_stacks(&a, &b);
			return (FALSE);
		}
	}
	else
	{
		if(!init_stacks_heuristic(*src, &b, &a, n))
		{
			del_stacks(&a, &b);
			return (FALSE);
		}
	}
	ops = heuristic_search(&a, &b, n);
	ft_putendl("Exit HS, STILL NEED TO PROGRAM SORT OF PARTITION ON REAL STACK"); // REMOFENJKN
	ft_putstr(ops);
	free(ops);
	return (TRUE);
}
