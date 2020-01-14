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
static t_stack *set_a_stack(t_stack *s, t_stack **a, size_t n)
{
	int		i;
	int		j;
	char	smaller;

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

static int		init_stacks(
	t_stack **src, t_stack **a, t_stack **b, size_t n)
{
	init_stacks_no_tab(a, b, n, sizeof(char));
	if (!(a && b))
		return (FALSE);
	(*b)->stack = (char*)ft_memalloc(sizeof(char) * n);
	(*a)->stack = (char*)malloc(sizeof(char) * n);
	if (!((*a)->stack && (*b)->stack))
		return (FALSE);
	(*addr_a)->start = (*addr_a)->stack;
	(*addr_a)->end = (*addr_a)->stack + (len - 1);
	(*a)->stack = set_a_stack(src, a, n);
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
