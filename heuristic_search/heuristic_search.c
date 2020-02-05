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
	if (node->s_a->start == node->s_a->stack && node->s_a->len == n)
	{
		i = 1;
		while (i < n)
		{
			if (node->s_a->start[i] < node->s_a->start[i - 1])
				return (FALSE);
		}
	}
	return (TRUE);
}

static t_node	*expand_best_node(t_node **nodes)
{
	t_node	*new_nodes;
	int		move_stock;

	(*nodes)->s_a->len = 2;
	(*nodes)->s_b->len = 2;
	stack_set((*nodes)->s_a, 1, 0);
	stack_set((*nodes)->s_a, 3, 1);
	stack_set((*nodes)->s_a, 0, 2);
	stack_set((*nodes)->s_a, 0, 3);
	stack_set((*nodes)->s_b, 4, 0);
	stack_set((*nodes)->s_b, 2, 1);
	stack_set((*nodes)->s_b, 0, 2);
	stack_set((*nodes)->s_b, 0, 3);
	printf("\nStack a:\n");
	for (int i = 0; i < (*nodes)->s_a->size / (int)sizeof(int); i++)
		printf("%d ", stack_get((*nodes)->s_a, i));
	printf("\nStack b:\n");
	for (int i = 0; i < (*nodes)->s_b->size / (int)sizeof(int); i++)
		printf("%d ", stack_get((*nodes)->s_b, i));
	move_stock = get_legal_moves(*nodes);
	printf("\n%d\n", move_stock);
	new_nodes = NULL;
	printf("%p, %p\n", nodes, *nodes);
	do_moves(&new_nodes, *nodes, move_stock);
	printf("%p, %p\n", nodes, *nodes);
	nodes = node_delhead(nodes);
	printf("%p, %p\n", nodes, *nodes);
	nodes = merge_new_nodes(nodes, &new_nodes);
	printf("%p, %p\n", nodes, *nodes);
	return (*nodes);
}

char			*heuristic_search(t_stack **a, t_stack **b, size_t n)
{
	t_node	*nodes;
	char	*ops;

	nodes = node_queue_init(&nodes, a, b);
	while (!is_solved(nodes, n))
		nodes = expand_best_node(&nodes);
	ft_putendl("Alleen maar tot hier?"); // REMOVE
	ft_putendl(nodes->ops);
	ops = ft_strdup(nodes->ops);
	ft_putendl("Tot hier?"); // REMOVE
	node_delall(&nodes);
	ft_putendl("Tot hier zelfs?"); // REMOVE
	return (ops);
}
