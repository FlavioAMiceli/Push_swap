/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 19:20:35 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/20 19:20:35 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "heuristic_search.h"

t_stack	*node_stackdup_aux(t_stack *dst, t_stack *src)
{
	dst->stack = (int*)malloc(src->size);
	dst->stack = ft_memdup(src->stack, src->size);
	dst->start = dst->stack + (src->start - src->stack);
	dst->end = dst->stack + (src->end - src->stack);
	dst->size = src->size;
	dst->len = src->len;
	return (dst);
}

t_node	*node_stackdup(t_node *new, t_node *current)
{
	new->stack_a = (t_stack*)malloc(sizeof(t_stack));
	new->stack_a = node_stackdup_aux(new->stack_a, current->stack_a);
	new->stack_b = (t_stack*)malloc(sizeof(t_stack));
	new->stack_b = node_stackdup_aux(new->stack_b, current->stack_b);
	return (new);
}
t_node	**node_delhead(t_node **nodes)
{
	t_node *next;
	t_node *current;

	current = *nodes;
	next = current->next;
	nodes = &next;
	del_stacks(&(current->stack_a), &(current->stack_b));
	free(ops);
	free(current);
	return (&next);
}
unsigned int	node_evaluate(
	t_stack *stack_a, t_stack *stack_b, unsigned int n_ops)
{
	// DE-DIJKSTRA THIS
	(void)stack_a;
	(void)stack_b;
	return (n_ops);
}
void	node_delall(t_node **nodes)
{
	while (*nodes)
		node_delhead(nodes);
	nodes = NULL;
}
t_node	**node_queue_init(t_node **nodes, t_stack **a, t_stack **b, t_size n)
{
	// CODE
}
t_node	**node_insert(t_node **new_nodes, t_node *node)
{
	// CODE
}
t_node	**insert_new_nodes(t_node **nodes, t_node **new_nodes)
{
	// CODE
}
