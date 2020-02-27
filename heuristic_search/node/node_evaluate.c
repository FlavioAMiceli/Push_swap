/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_evaluate.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 19:20:35 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/20 19:20:35 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../heuristic_search.h"

static unsigned int	get_dist_if_one(t_stack *a, t_stack *b, int bound)
{
	int	bound_a;
	int	bound_b;
	int i;

	i = stack_value_index(a, 1);
	if (i >= 0)
	{
		if (bound & A_BOUND)
		{
			bound_a = stack_value_index(a, 0);
			return (N OPS TO GET 1 ABOVE BOUND);
		}
		return (N OPS TO GET 1 AT INDEX 0, MIN OF ROTS AND REVROTS);
	}
	else
	{
		i = stack_value_index(b, 1);
		if (bound & A_BOUND)
			bound_a = stack_value_index(a, 0);
		if (bound & B_BOUND)
			bound_b = stack_value_index(b, 0);
		return (N OPS TO GET 1 ON INDEX 0 OF A, OR ABOVE BOUND ON A);
	}
}

static unsigned int	get_dist_diff_stack(
	t_stack *a, t_stack *b, int bound, t_index *ind)
{
	return (DISTANCE OF GETTING BOTH ON TOP OF SAME STACK, AND SWAP IF NOT ORDERED
			OR GET ONE TO TOP, OTHER TO BOTTOM, PLUS THE PUSH AND REVROT, NEVER SWAP)
}

static unsigned int	get_dist_same_stack_bound(
	t_stack *s, t_index *ind, int bound_index)
{
	return (DISTANCE OF GETTING BOTH ON TOP OF TWO STACKS PLUS A SWAP IF NOT ORDERED,
		OR ONE TOP OF B AND THE OTHER ON BOTTOM OF A PLUS A PUSH AND REVROT)
}

static unsigned int	get_dist_same_stack_no_bound(
	t_stack *s, t_index *ind)
{
	int	on_a;
	int	dist;

	on_a = ind->stack_flag & LOW_ON_A ? TRUE : FALSE;
	if (ind->low > ind->high && on_a)
	{
		dist = (((s->len - 1) - ind->low) * 2) + (ind->high * 3) + 1;
		dist = ft_min(dist, ((s->len - 1) - ind->high) + 2);
	}
	else if (ind->low < ind->high && on_a)
	{
		dist = (((s->len - 1) - ind->high) * 2) + (ind->low * 3) + 2;
		dist = ft_min(dist, ((s->len - 1) - ind->low) + 1);
	}
	else if (ind->low > ind->high && !on_a)
	{
		dist = (((s->len - 1) - ind->low) * 1) + (ind->high * 2) + 2;
		dist = ft_min(dist, ((s->len - 1) - ind->high) + 1);
	}
	else
	{
		dist = (((s->len - 1) - ind->high) * 1) + (ind->low * 2) + 1;
		dist = ft_min(dist, ((s->len - 1) - ind->low) + 2);
	}
	return (dist);
}

static unsigned int	get_distance(t_stack *a, t_stack *b, int bound, int c)
{
	t_index ind;

	if (c == 1)
		return (get_dist_if_one(a, b, bound));
	ind->low = stack_value_index(a, c - 1);
	ind->high = stack_value_index(a, c);
	ind->stack_flag = ind->low >= 0 ? LOW_ON_A : 0x0;
	ind->stack_flag &= ind->high >= 0 ? HIGH_ON_A : 0x0;
	ind->low = ind->low < 0 ? stack_value_index(b, c - 1) : ind->low;
	ind->high = ind->high < 0 ? stack_value_index(b, c) : ind->high;
	if (ind->stack_flag == (LOW_ON_A & HIGH_ON_A))
	{
		if (bound & A_BOUND)
			return (get_dist_same_stack_bound(a, ind, stack_value_index(a, 0)));
		return (get_dist_same_stack_no_bound(a, ind));
	}
	else if (ind->stack_flag == (LOW_ON_A | HIGH_ON_A))
		return (get_dist_diff_stack(a, b, bound, ind));
	if (bound & B_BOUND)
		return (get_dist_same_stack_bound(b, ind, stack_value_index(b, 0)));
	return (get_dist_same_stack_no_bound(b, ind));
}

static unsigned int	max_distance(t_stack *a, t_stack *b, int bound)
{
	int	max_d;
	int	c;
	int	i;

	i = 0;
	c = 1;
	max_d = 0;
	while (c <= (stack_a->size - (bound & A_BOUND)))
	{
		d = get_distance(a, b, bound, c);
		if (d > max_d)
			max_d = d;
		c++;
	}
	return (max_d)
}

static unsigned int	min_revrots(
	t_stack *stack_a, t_stack *stack_b, int bound)
{
	int rra;
	int rrb;
	int	i;

	rra = 0;
	rrb = 0;
	if (bound & A_BOUND)
	{
		i = 0;
		while (stack_get(stack_a, i) != 0)
			i++;
		while (i + rra < stack_a->len)
			rra++;
	}
	if (bound & B_BOUND)
	{
		i = 0;
		while (stack_get(stack_b, i) != 0)
			i++;
		while (i + rrb < stack_b->len)
			rrb++;
	}
	return (ft_max(rra, rrb));
}

unsigned int	node_evaluate(
	t_stack *stack_a, t_stack *stack_b, unsigned int n_ops, int bound)
{
	unsigned int 	score;

	score = stack_b->len + min_revrots(stack_a, stack_b, bound);
	score = ft_max(score, max_distance(stack_a, stack_b, bound));
	return (n_ops + score);
}

//static int		ft_abs(int i)
//{
//	return (i >= 0 ? i : -i);
//}

// unsigned int	node_evaluate(
// 	t_stack *stack_a, t_stack *stack_b, unsigned int n_ops, int bound)
// {
// 	// DE-DIJKSTRA THIS
// 	// MAKE SURE IT WORKS WHEN THERE IS A BOUND
// 	(void)stack_a;
// 	(void)stack_b;
// 	(void)bound;
// 	return (n_ops);
// }
