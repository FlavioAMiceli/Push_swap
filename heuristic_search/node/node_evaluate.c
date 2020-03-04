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
	int	dist;
	int i;

	i = stack_value_index(a, 1);
	if (i >= 0)
	{
		if (bound & A_BOUND)
		{
			bound_a = stack_value_index(a, 0);
			if (bound_a < i)
				return (((a->len - 1) - bound_a) * 2);
			return ((((a->len - 1) - bound_a) * 2) + ((i + 1) * 2));
		}
		return (ft_min(i, (a->len - 1) - i));
	}
	else
	{
		i = stack_value_index(b, 1);
		bound_a = stack_value_index(a, 0);
		bound_b = stack_value_index(b, 0);
		dist = bound_a >= 0 ? (((a->len - 1) - bound_a) * 2) : 0;
		dist = bound_a < 0 && a->len > 0 ? a->len : dist;
		if (bound_b >= 0)
		{
			if (bound_b < i)
				dist += ((b->len - 1) - i) + 1;
			dist += (i + 2);
		}
		else
			dist += ft_min((i + 2), ((b->len - 1) - i + 1));
		return (dist);
	}
}

static unsigned int	get_dist_diff_stack_bound(
	t_stack *a, t_stack *b, t_index *ind, int bound)
{
	(void)a;
	(void)b;
	(void)ind;
	(void)bound;
	ft_putendl("get_dist_diff_stack_bound NYI!");
	return (0);
	// return (DISTANCE OF GETTING BOTH ON TOP OF SAME STACK, AND SWAP IF NOT ORDERED
	// 		OR GET ONE TO TOP, OTHER TO BOTTOM, PLUS THE PUSH AND REVROT, NEVER SWAP)
}

/*
**	Calculates the minimum ops required to get two numbers next to eachother.
**	The different cases deal with which number starts on stack a.
**	There are two paths considered, getting both to the top of their stack,
**	pushing one and swapping if necessary, or
**	getting one to the bottom of stack a, the other to the top and revroting.
**
**	TODO: Don't we need to add the length of stack b to this number?
*/
static unsigned int	get_dist_diff_stack_no_bound(
	t_stack *a, t_stack *b, t_index *ind)
{
	int	dist;

	if (ind->stack_flag & LOW_ON_A)
	{
		dist = ((a->len - 1) - ind->low) + ((b->len - 1) - ind->high) + 2;
		dist = ft_min(dist, ind->low + ((b->len - 1) - ind->high) + 1);
	}
	else
	{
		dist = ((b->len - 1) - ind->low) + ((a->len - 1) - ind->high) + 1;
		dist = ft_min(dist, ind->high + ((b->len - 1) - ind->low) + 1);
	}
	return (dist);
}

static unsigned int	get_dist_same_stack_bound(
	t_stack *s, t_index *ind, int bound_index)
{
	(void)s;
	(void)ind;
	(void)bound_index;
	ft_putendl("get_dist_same_stack_bound NYI!");
	return (0);
	// return (DISTANCE OF GETTING BOTH ON TOP OF TWO STACKS PLUS A SWAP IF NOT ORDERED,
	// 	OR ONE TOP OF B AND THE OTHER ON BOTTOM OF A PLUS A PUSH AND REVROT)
}

/*
**	Calculates the minimum ops required to get two numbers next to eachother.
**	The different cases deal with either number being on the lower index,
**	and with them being on either stack a or stack b.
**	In general there are two ways to get them together.
**	One path is to push them both to top, removing any numbers inbetween.
**	The other is to move one to the bottom and the other to the top.
**	Everything pushed to b needs to be pushed back aswell.
**
**	TODO: shouldn't the length of b be added to this number?
*/
static unsigned int	get_dist_same_stack_no_bound(
	t_stack *s, t_index *ind, int on_a)
{
	int	dist;

	if (on_a && ind->low > ind->high)
	{
		dist = (((s->len - 1) - ind->low) * 2) + (ind->high * 3) + 1;
		dist = ft_min(dist, ((s->len - 1) - ind->high) + 2);
	}
	else if (on_a && ind->high != ind->low + 1)
	{
		dist = (((s->len - 1) - ind->high) * 2) + (ind->low * 3) + 2;
		dist = ft_min(dist, ((s->len - 1) - ind->low) + 1);
	}
	else if (ind->low > ind->high)
	{
		dist = (((s->len - 1) - ind->low) * 1) + (ind->high * 2) + 2;
		dist = ft_min(dist, ((s->len - 1) - ind->high) + 1);
	}
	else if (ind->high != ind->low + 1)
	{
		dist = (((s->len - 1) - ind->high) * 1) + (ind->low * 2) + 1;
		dist = ft_min(dist, ((s->len - 1) - ind->low) + 2);
	}
	else
		return (0);
	return (dist);
}

static unsigned int	get_distance(t_stack *a, t_stack *b, int bound, int c)
{
	t_index ind;

	if (c == 1)
		return (get_dist_if_one(a, b, bound));
	ind.low = stack_value_index(a, c - 1);
	ind.high = stack_value_index(a, c);
	ind.stack_flag = ind.low >= 0 ? LOW_ON_A : 0x0;
	ind.stack_flag &= ind.high >= 0 ? HIGH_ON_A : 0x0;
	ind.low = ind.low < 0 ? stack_value_index(b, c - 1) : ind.low;
	ind.high = ind.high < 0 ? stack_value_index(b, c) : ind.high;
	if (ind.stack_flag == (LOW_ON_A & HIGH_ON_A))
	{
		if (bound & A_BOUND)
			return (get_dist_same_stack_bound(a, (&ind), stack_value_index(a, 0)));
		return (get_dist_same_stack_no_bound(a, (&ind), TRUE));
	}
	else if (ind.stack_flag == (LOW_ON_A | HIGH_ON_A))
	{
		if (bound)
			return (get_dist_diff_stack_bound(a, b, (&ind), bound));
		return (get_dist_diff_stack_no_bound(a, b, (&ind)));
	}
	if (bound & B_BOUND)
		return (get_dist_same_stack_bound(b, (&ind), stack_value_index(b, 0)));
	return (get_dist_same_stack_no_bound(b, (&ind), FALSE));
}

static unsigned int	max_distance(t_stack *a, t_stack *b, int bound)
{
	int	max_d;
	int	d;
	int	c;
	int	i;

	i = 0;
	c = 1;
	max_d = 0;
	while (c <= ((int)(a->size / sizeof(int)) - (bound & A_BOUND)))
	{
		d = get_distance(a, b, bound, c);
		if (d > max_d)
			max_d = d;
		c++;
	}
	return (max_d);
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
