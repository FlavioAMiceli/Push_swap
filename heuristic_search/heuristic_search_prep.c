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
static t_stack *set_src_stack(t_stack *s, t_stack **src, size_t n, int bound)
{
	int		i;
	int		j;
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
	return ((*src)->stack);
}

/*
**	Creates stacks. If original stack is larger than current partition, a bound
**	will be set at the start of the partition.
**	This 0 will be used to tell wether rotations are legal or not.
*/
static int		init_stacks(
	t_stack **s, t_stack **src, t_stack **dst, size_t n)
{
	(*s)->len > n ? bound = TRUE : FALSE;
	init_stacks_no_tab(a, b, n + bound, sizeof(char));
	if (!(a && b))
		return (FALSE);
	(*dst)->stack = (char*)ft_memalloc(sizeof(char) * (bound ? n + 1 : n));
	(*src)->stack = (char*)malloc(sizeof(char) * (bound ? n + 1 : n));
	if (!((*src)->stack && (*dst)->stack))
		return (FALSE);
	(*src)->start = (*src)->stack;
	(*src)->end = (*src)->stack + (n - (1 + bound));
	(*src)->len -= bound;
	(*src)->stack = set_src_stack(s, src, (bound ? n + 1 : n), bound);
	(*dst)->start = (*dst)->stack;
	(*dst)->end = (*dst)->stack;
	return (TRUE);
}

int				basecase_heuristic(
	t_stack **src, t_stack **dst, int to_b, size_t n)
{
	t_stack	**a;
	t_stack	**b;
	char	*ops;

	if (to_b)
	{
		if(!init_stacks(*src, a, b, n))
		{
			del_stacks(a, b);
			return (FALSE);
		}
	}
	else
	{
		if(!init_stacks(*src, b, a, n))
		{
			del_stacks(a, b);
			return (FALSE);
		}
	}
	ops = heuristic_search(a, b, n);
	ft_putstr(ops);
	free(ops);
	return (TRUE);
}
