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

#include "../heuristic_search.h"

static t_stack	*node_stackdup_aux(t_stack *dst, t_stack *src)
{
	dst->stack = (int*)malloc(src->size);
	dst->stack = (int*)ft_memdup((char*)src->stack, src->size);
	dst->start = dst->stack + (src->start - src->stack);
	dst->end = dst->stack + (src->end - src->stack);
	dst->size = src->size;
	dst->len = src->len;
	return (dst);
}

t_node			*node_stackdup(t_node *new, t_node *current)
{
	new->s_a = (t_stack*)malloc(sizeof(t_stack));
	new->s_a = node_stackdup_aux(new->s_a, current->s_a);
	new->s_b = (t_stack*)malloc(sizeof(t_stack));
	new->s_b = node_stackdup_aux(new->s_b, current->s_b);
	return (new);
}

t_node			**node_delhead(t_node **nodes)
{
	t_node *next;
	t_node *current;

	current = *nodes;
	next = current->next;
	if (!next)
		nodes = NULL;
	else
		nodes = &next;
	del_stacks(&(current->s_a), &(current->s_b));
	free(current->ops);
	free(current);
	return (nodes);
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
t_node			*node_queue_init(t_node **nodes, t_stack **a, t_stack **b)
{
	t_node	*head;

	head = (t_node*)malloc(sizeof(t_node));
	head->s_a = *a;
	head->s_b = *b;
	head->ops = (char*)ft_memalloc(sizeof(char));
	head->n_ops = 0;
	head->fitness = node_evaluate(*a, *b, 0);
	head->next = NULL;
	nodes = &head;
	return (*nodes);
}
t_node			**node_insert(t_node **new_nodes, t_node *node)
{
	t_node	*current;
	t_node	*previous;

	if (new_nodes == NULL || *new_nodes == NULL)
	{
		new_nodes = &node;
		return (new_nodes);
	}
	current = *new_nodes;
	if (node->fitness < current->fitness)
	{
		node->next = current;
		new_nodes = &node;
		return (new_nodes);
	}
	while (node->fitness > current->fitness)
	{
		previous = current;
		current = previous->next;
	}
	previous->next = node;
	node->next = current;
	return (new_nodes);
}

t_node			**merge_new_nodes(t_node **nodes, t_node **new_nodes)
{
	t_node	*old;
	t_node	*new;
	t_node	*sorted;

	// nodes is empty, new_nodes are all existing states.
	if (!nodes || !(*nodes))
	{
		nodes = new_nodes;
		return (nodes);
	}
	new = *new_nodes;
	old = *nodes;
	// set the head of nodes and find the first natural series.
	if (new->fitness < old->fitness)
	{
		nodes = new_nodes;
		sorted = new;
		while (sorted->next && sorted->fitness <= old->fitness)
			sorted = sorted->next;
	}
	else
	{
		sorted = old;
		while (sorted->next && sorted->fitness <= new->fitness)
			sorted = sorted->next;
	}
	// find next natural series. Will alternate between new and old.
	while (new && old)
	{
		if (new->fitness < old->fitness)
		{

		}
		else
		{

		}
	}
	return (nodes);
}
