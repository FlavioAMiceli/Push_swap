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

#include "push_swap.h"

/*
** Set chars from 1 to n in (*a)->stack in the same order as numbers appear
** in src->stack
*/
static t_stack *set_a_stack(t_stack *s, t_stack **a, size_t n, int bound)
{
	int		i;
	int		j;
	char	smaller;

	if (bound)
	{
		(*a)->stack[0] = 0;
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
		(*a)->stack[i] = smaller + 1;
		i++;
	}
	return ((*a)->stack);
}

/*
**	Creates stacks. If original stack is larger than current partition, a bound
**	will be set at the start of the partition.
**	This 0 will be used to tell wether rotations are legal or not.
*/
static int		init_stacks(
	t_stack **src, t_stack **a, t_stack **b, size_t n)
{
	(*src)->len > n ? bound = TRUE : FALSE;
	init_stacks_no_tab(a, b, n + bound, sizeof(char));
	if (!(a && b))
		return (FALSE);
	(*b)->stack = (char*)ft_memalloc(sizeof(char) * (bound ? n + 1 : n));
	(*a)->stack = (char*)malloc(sizeof(char) * (bound ? n + 1 : n));
	if (!((*a)->stack && (*b)->stack))
		return (FALSE);
	(*addr_a)->start = (*addr_a)->stack;
	(*addr_a)->end = (*addr_a)->stack + (n - (1 + bound));
	(*addr_a)->len -= bound;
	(*a)->stack = set_a_stack(src, a, (bound ? n + 1 : n), bound);
	(*addr_b)->start = (*addr_b)->stack;
	(*addr_b)->end = (*addr_b)->stack;
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
		del_stacks(a, b);
		return (FALSE);
	}
	else
	{
		if(!init_stacks(*src, b, a, n))
		del_stacks(a, b);
		return (FALSE);
	}
	ops = heuristic_search(a, b, n);
	ft_putstr(ops);
	return (TRUE);
}
