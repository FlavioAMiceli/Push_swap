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
#include <stdio.h> // remove

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

static void		expand_best_node(t_node **nodes, int size_type, int bound)
{
	t_node	*new_nodes;
	int		move_stock;

	move_stock = get_legal_moves(*nodes, size_type);
	new_nodes = NULL;
	do_moves(&new_nodes, *nodes, move_stock, bound);
	node_delhead(nodes);
	merge_new_nodes(nodes, &new_nodes);
}

char			*heuristic_search(t_node *nodes, size_t n, int bound)
{
	char	*ops;
	static int	count; //remove

	while (!is_solved(nodes, n))
	{
		count++;
		expand_best_node(&nodes, sizeof(nodes->s_a->stack), bound);
	}
	printf("Nodes expanded: %d\n", count);
	ops = ft_strdup(nodes->ops);
	node_delall(&nodes);
	return (ops);
}
