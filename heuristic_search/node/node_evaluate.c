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
// 	t_stack *stack_a, t_stack *stack_b, unsigned int n_ops)
// {
// 	// DE-DIJKSTRA THIS
// 	// MAKE SURE IT WORKS WHEN THERE IS A BOUND
// 	(void)stack_a;
// 	(void)stack_b;
// 	return (n_ops);
// }