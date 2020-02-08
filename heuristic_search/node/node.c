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
#include <stdio.h> // remove me!

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
	while (nodes && *nodes)
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

void	node_insert(t_node **new_nodes, t_node *node)
{
	t_node	*current;
	t_node	*previous;

	if (new_nodes == NULL || *new_nodes == NULL)
	{
		*new_nodes = node;
		return ;
	}
	current = *new_nodes;
	if (node->fitness < current->fitness)
	{
		node->next = current;
		*new_nodes = node;
		return ;
	}
	previous = current;
	current = current->next;
	while (current && (node->fitness > current->fitness))
	{
		previous = current;
		current = current->next;
	}
	previous->next = node;
	node->next = current;
}

static	int		list_len(t_node *node)
{
	// REMOVE ME!
	int i;

	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

static	t_node	*link_next_natural_run(
	t_node **new_current, t_node **old_current, t_node **sorted)
{
	t_node	*old;
	t_node	*new;

	old = *old_current;
	new = *new_current;
	if (new->fitness < old->fitness)
	{
		while (new->next && new->fitness <= old->fitness)
			new = new->next;
		sorted = &new;
		new_current = &(new->next);
	}
	else
	{
		while (old->next && old->fitness <= new->fitness)
			old = old->next;
		sorted = &old;
		old_current = &(old->next);
	}
	return (*sorted);
}

t_node			**merge_new_nodes(t_node **nodes, t_node **new_nodes)
{
	t_node	*old;
	t_node	*new;
	t_node	*sorted;

	printf("merge_new_nodes\n");
	if (!nodes || !(*nodes))
	{
		printf("merge_new_nodes?\n");
		nodes = new_nodes;
		return (nodes);
	}
	printf("merge_new_nodes, after empty old check.\n");
	printf("old len: %d\n", list_len(*nodes));
	printf("new len: %d\n", list_len(*new_nodes));
	new = *new_nodes;
	old = *nodes;
	if (new->fitness < old->fitness)
		nodes = new_nodes;
	sorted = link_next_natural_run(&new, &old, &sorted);
	while (new && old)
	{
		sorted->next = new->fitness < old->fitness ? new : old;
		sorted = link_next_natural_run(&new, &old, &sorted);
	}
	sorted->next = old ? old : new;
	return (nodes);
}
