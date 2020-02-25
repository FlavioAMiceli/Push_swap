/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_del.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 19:20:35 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/20 19:20:35 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../heuristic_search.h"

void			node_delhead(t_node **nodes)
{
	t_node *next;
	t_node *current;

	current = *nodes;
	next = current->next;
	*nodes = next;
	del_stacks(&(current->s_a), &(current->s_b));
	free(current->ops);
	free(current);
}

void	node_delall(t_node **nodes)
{
	while (nodes && *nodes)
		node_delhead(nodes);
	nodes = NULL;
}