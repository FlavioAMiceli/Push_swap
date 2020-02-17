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

static void		node_stackdup_aux(t_stack *dst, t_stack *src)
{
	dst->stack = (int*)ft_memdup((char*)src->stack, src->size);
	if (dst->stack == NULL)
		ft_putstr_fd("Error in node_stackdup_aux\n", 2);
	dst->start = dst->stack + (src->start - src->stack);
	dst->end = dst->stack + (src->end - src->stack);
	dst->size = src->size;
	dst->len = src->len;
}

t_node			*node_stackdup(t_node *new, t_node *current)
{
	new->s_a = (t_stack*)ft_memalloc(sizeof(t_stack));
	if (new->s_a == NULL)
		ft_putstr_fd("Error in node_stackdup\n", 2);
	node_stackdup_aux(new->s_a, current->s_a);
	new->s_b = (t_stack*)ft_memalloc(sizeof(t_stack));
	if (new->s_b == NULL)
		ft_putstr_fd("Error in node_stackdup\n", 2);
	node_stackdup_aux(new->s_b, current->s_b);
	return (new);
}

void			node_delhead(t_node **nodes)
{
	t_node *next;
	t_node *current;

	current = *nodes;
	next = current->next;
	*nodes = next;
	del_stacks(&(current->s_a), &(current->s_b));
	free(current->ops);
	current->ops = NULL;
	free(current);
	current = NULL;
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

void			node_queue_init(t_node **nodes, t_stack **a, t_stack **b)
{
	t_node	*head;

	head = (t_node*)ft_memalloc(sizeof(t_node));
	if (head == NULL)
		ft_putstr_fd("Error in node_queue_init\n", 2);
	head->s_a = *a;
	head->s_b = *b;
	head->ops = (char*)ft_memalloc(sizeof(char));
	if (head->ops == NULL)
		ft_putstr_fd("Error in node_queue_init\n", 2);
	head->n_ops = 0;
	head->fitness = node_evaluate(*a, *b, 0);
	head->next = NULL;
	*nodes = head;
}

void	node_insert(t_node **new_nodes, t_node *node)
{
	t_node	*current;
	t_node	*previous;

	if (*new_nodes == NULL)
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

static	void	link_next_natural_run(
	t_node **new_current, t_node **old_current)
{
	t_node	*old;
	t_node	*new;

	old = *old_current;
	new = *new_current;
	if (new->fitness < old->fitness)
	{
		while (new->next && new->fitness <= old->fitness)
			new = new->next;
		*new_current = new->next;
		new->next = old;
	}
	else
	{
		while (old->next && old->fitness <= new->fitness)
			old = old->next;
		*old_current = old->next;
		old->next = new;
	}
}

void			merge_new_nodes(t_node **nodes, t_node **new_nodes)
{
	t_node	*old;
	t_node	*new;

	if (!(*nodes))
	{
		*nodes = *new_nodes;
		return ;
	}
	new = *new_nodes;
	old = *nodes;
	if (new->fitness < old->fitness)
		*nodes = new;
	while (new && old)
		link_next_natural_run(&new, &old);
}
