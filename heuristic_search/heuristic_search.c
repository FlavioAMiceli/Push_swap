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

	// printf("Enter is_solved.\n");
	if (node->s_a->len == n)
	{
		i = 1;
		while (i < n)
		{
			if (stack_get(node->s_a, i) < stack_get(node->s_a, i - 1))
			{
				// printf("Exit is_solved 1\n");
				return (FALSE);
			}
			i++;
		}
	}
	else
	{
		// printf("Exit is_solved 2\n");
		return (FALSE);
	}
	// printf("Exit is_solved 3\n");
	return (TRUE);
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
	// printf("Enter ebn.\n");
	move_stock = get_legal_moves(*nodes, size_type);
	printf("move_stock: %d\n", move_stock);
	new_nodes = NULL;
	// printf("Before do_moves: %p, %p\n", nodes, *nodes);
	// printf("Current nodes:\n");
	// for (t_node *node = *nodes; node != NULL; node = node->next)
	// 	printf("	%p :\n%s\n", node, node->ops);
	do_moves(&new_nodes, *nodes, move_stock);
	printf("Current new nodes:\n");
	// for (t_node *new = new_nodes; new != NULL; new = new->next)
		// printf("	%p :\n%s\n", new, new->ops);
	// printf("Before node_delhead: %p, %p\n", nodes, *nodes);
	node_delhead(nodes);
	// printf("After node_delhead: %p %p\n", nodes, &new_nodes);
	merge_new_nodes(nodes, &new_nodes);
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
