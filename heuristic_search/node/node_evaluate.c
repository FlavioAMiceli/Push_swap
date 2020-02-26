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
#include <stdio.h> //remove

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

// int	*arr;
// int	i;
// int	n;
// int max_d;
// // TODO: MAKE THIS WORK CORRECTLY WITH BOUNDS.
// // SHOULD INVOLVE CHECKING IF N == 0, AND ADJUSTING INDEX AFTER 0 HAS BEEN FOUND
//
// arr = (int*)malloc(stack_a->size - (bound & A_BOUND));
// i = 0;
// while (i < stack_b->len)
// {
// 	n = stack_get(stack_b, i);
// 	arr[stack_b->len - i] = n;
// 	i++;
// }
// i = 0;
// while (i < stack_a->len)
// {
// 	n = stack_get(stack_a, i);
// 	arr[i + stack_b->len] = n;
// 	i++;
// }
// i = 0;
// n = 1;
// free(arr);

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
	t_stack *a, t_stack *b, int bound, int c)
{
	return (DISTANCE OF GETTING BOTH ON TOP OF SAME STACK, AND SWAP IF NOT ORDERED
			OR GET ONE TO TOP, OTHER TO BOTTOM, PLUS THE PUSH AND REVROT, NEVER SWAP)
}

static unsigned int	get_dist_same_stack_bound(
	t_stack *s, int s_is_a, int i, int j, int bound_index)
{
	return (DISTANCE OF GETTING BOTH ON TOP OF TWO STACKS PLUS A SWAP IF NOT ORDERED,
		OR ONE TOP OF B AND THE OTHER ON BOTTOM OF A PLUS A PUSH AND REVROT)
}

static unsigned int	get_dist_same_stack_no_bound(
	t_stack *s, int s_is_a, int i, int j)
{
	return (DISTANCE OF GETTING BOTH ON TOP OF TWO STACKS PLUS A SWAP IF NOT ORDERED,
		OR ONE TOP OF B AND THE OTHER ON BOTTOM OF A PLUS A PUSH AND REVROT)
}

static unsigned int	get_distance(t_stack *a, t_stack *b, int bound, int c)
{
	int i;

	if (c == 1)
		return (get_distance_if_one(a, b, bound));
	return (DISTANCE OF c TO c - 1);
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

unsigned int	node_evaluate(
	t_stack *stack_a, t_stack *stack_b, unsigned int n_ops, int bound)
{
	unsigned int 	score;

	score = stack_b->len + min_revrots(stack_a, stack_b, bound);
	score = ft_max(score, max_distane(stack_a, stack_b, bound));
	printf("score : %d b-len : %d\n", score, stack_b->len);
	return (n_ops + score);
}

//static int		ft_abs(int i)
//{
//	return (i >= 0 ? i : -i);
//}

// unsigned int	node_evaluate(
// 	t_stack *stack_a, t_stack *stack_b, unsigned int n_ops)
// {
// 	int	score;
// 	int	i;
// 	// DE-DIJKSTRA THIS
// 	// MAKE SURE IT WORKS WHEN THERE IS A BOUND
// 	score = n_ops;
// 	i = 0;
// 	while (i < stack_a->len)
// 	{
// 		score += ft_abs((stack_get(stack_a, i) - (1 + stack_b->len)) - i);
// 		i++;
// 	}
// 	i = 0;
// 	while (i <stack_b->len)
// 	{
// 		score += ft_abs((stack_get(stack_b, i) - 1) - (stack_b->len - 1 - i));
// 		i++;
// 	}
// 	return (score);
// }

/*unsigned int	node_evaluate(
	t_stack *stack_a, t_stack *stack_b, unsigned int n_ops)
{
	int index_one;
	int	n;
	int	i;
	int *arr;

	// DE-DIJKSTRA THIS
	// MAKE SURE IT WORKS WHEN THERE IS A BOUND
	arr = (int*)malloc(stack_a->size);
	i = 0;
	while (i < stack_b->len)
	{
		n = stack_get(stack_b, i);
		arr[stack_b->len - i] = n;
		if (n == 1)
			index_one = stack_b->len - i;
		i++;
	}
	i = 0;
	while (i < stack_a->len)
	{
		n = stack_get(stack_a, i);
		arr[i + stack_b->len] = n;
		if (n == 1)
			index_one = i + stack_b->len;
		i++;
	}
	n = 0;
	i = 0;
	while (i < (int)(stack_a->size / sizeof(int)))
	{
		if (i != index_one)
			n += ft_abs((index_one + arr[i] - 1) - i); // HOW FAR THE NUMBER AT arr[i] IS COMPARED TO WHERE IT SHOULD BE COMPARED TO index_one
		i++;
	}
	return (n + n_ops);
}*/

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
