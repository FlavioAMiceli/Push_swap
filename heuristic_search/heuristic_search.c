/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heuristic_search.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 21:35:30 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/14 21:35:31 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "heuristic_search.h"
#include <stdio.h> // remove me!

static int		is_solved(t_node *node, int n)
{
	int	i;

	if (node->s_a->len == n)
	{
		i = 1;
		while (i < n)
		{
			if (stack_get(node->s_a, i) < stack_get(node->s_a, i - 1))
				return (FALSE);
			i++;
		}
	}
	else
		return (FALSE);
	return (TRUE);
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

static t_node	*expand_best_node(t_node **nodes, int size_type)
{
	t_node	*new_nodes;
	int		move_stock;

	// (*nodes)->s_a->len = 0;
	// (*nodes)->s_b->len = 4;
	// stack_set((*nodes)->s_a, 2, 0);
	// stack_set((*nodes)->s_a, 1, 1);
	// stack_set((*nodes)->s_a, 0, 2);
	// stack_set((*nodes)->s_a, 0, 3);
	// stack_set((*nodes)->s_b, 3, 0);
	// stack_set((*nodes)->s_b, 4, 1);
	// stack_set((*nodes)->s_b, 1, 2);
	// stack_set((*nodes)->s_b, 2, 3);
	// printf("\nStack a:\n");
	// for (int i = 0; i < (*nodes)->s_a->size / size_type; i++)
	// 	printf("%d ", stack_get((*nodes)->s_a, i));
	// printf("\nStack b:\n");
	// for (int i = 0; i < (*nodes)->s_b->size / size_type; i++)
	// 	printf("%d ", stack_get((*nodes)->s_b, i));
	move_stock = get_legal_moves(*nodes, size_type);
	// printf("\n%d\n", move_stock);
	new_nodes = NULL;
	// printf("%p, %p\n", nodes, *nodes);
	do_moves(&new_nodes, *nodes, move_stock);
	// printf("Before node_delhead: %p, %p\n", nodes, *nodes);
	nodes = node_delhead(nodes);
	printf("After node_delhead: %p %p\n", nodes, &new_nodes);
	if (nodes)
		printf("old len: %d\n", list_len(*nodes));
	printf("huh");
	printf("new len: %d\n", list_len(new_nodes));
	nodes = merge_new_nodes(nodes, &new_nodes);
	printf("old len: %d\n", list_len(*nodes));
	printf("new len: %d\n", list_len(new_nodes));
	// printf("After mnn: %p, %p\n", nodes, *nodes);
	return (*nodes);
}

char			*heuristic_search(t_stack **a, t_stack **b, size_t n)
{
	t_node	*nodes;
	char	*ops;

	nodes = node_queue_init(&nodes, a, b);
	while (!is_solved(nodes, n))
		nodes = expand_best_node(&nodes, sizeof(*((*a)->stack)));
	ft_putendl("Alleen maar tot hier?"); // REMOVE
	ft_putendl(nodes->ops);
	ops = ft_strdup(nodes->ops);
	ft_putendl("Tot hier?"); // REMOVE
	node_delall(&nodes);
	ft_putendl("Tot hier zelfs?"); // REMOVE
	return (ops);
}
