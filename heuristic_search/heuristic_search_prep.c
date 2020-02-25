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
static void	set_stack(t_stack *s, t_stack **src, size_t n, int bound)
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
	(*dst)->stack = (int*)malloc(sizeof(int) * (bound ? n + 1 : n));
	(*src)->stack = (int*)malloc(sizeof(int) * (bound ? n + 1 : n));
	if (!((*src)->stack && (*dst)->stack))
		return (FALSE);
	(*src)->start = (*src)->stack;
	(*src)->end = (*src)->stack + (n - (1 + bound));
	set_src_stack(s, src, (bound ? n + 1 : n), bound);
	(*dst)->start = (*dst)->stack;
	(*dst)->end = (*dst)->stack;
	return (TRUE);
}

static int	init_stack_heuristic(
	t_stack *org, t_stack **cpy, int n, int n_current, int bound)
{
	t_stack	*new;

	new = (t_stack *)ft_memalloc(sizeof(t_stack));
	if (!new)
		return (FALSE);
	new->size = (n + bound) * sizeof(int);
	new->len = n_current + bound;
	new->stack = (int *)ft_memalloc(sizeof(int) * (bound ? n + 1 : n));
	if (!(new->stack))
		return (FALSE);
	new->start = new->stack;
	new->end = new->stack + (n_current - (1 + bound));
	set_stack(org, &new, (bound ? n_current + 1 : n_current), bound);
	*cpy = new;
	return (TRUE);
}

int			basecase_heuristic(
	t_stack *origin_a, t_stack *origin_b, size_t n_a, size_t n_b)
{
	t_node	*node;
	t_stack	*a;
	t_stack	*b;
	char	*ops;

	bound = (size_t)origin_a->len > n_a ? A_BOUND : 0x0;
	bound |= (size_t)origin_b->len > n_b ? B_BOUND : 0x0;
	if(!init_stack_heuristic(origin_a, &a, n_a, n_a + n_b, bound & A_BOUND ? TRUE : FALSE))
		{
			del_stacks(&a, &b);
			return (FALSE);
		}
	}
	if(!init_stack_heuristic(origin_b, &b, n_b, n_a + n_b, bound & B_BOUND ? TRUE : FALSE))
		{
			del_stacks(&a, &b);
			return (FALSE);
		}
	}
	node_queue_init(&nodes, &a, &b, bound);
	ops = heuristic_search(&nodes, n_a + n_b, bound);
	ft_putendl("Exit HS, STILL NEED TO PROGRAM SORT OF PARTITION ON REAL STACK"); // REMOFENJKN
	ft_putstr(ops);
	free(ops);
	return (TRUE);
}
