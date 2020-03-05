/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   merge_new_nodes.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 19:20:35 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/20 19:20:35 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../heuristic_search.h"

static	void	link_next_natural_run(
	t_node **new_current, t_node **old_current)
{
	t_node	*old;
	t_node	*new;
	t_node	*tmp;

	old = *old_current;
	new = *new_current;
	// // TEST
	// t_node	*current; //remove
	// current = old;
	// while (current)
	// {
	// 	ft_putstr("old node score: ");
	// 	ft_putnbr(current->fitness);
	// 	ft_putchar('\n');
	// 	current = current->next;
	// }
	// current = new;
	// while (current)
	// {
	// 	ft_putstr("	new node score: ");
	// 	ft_putnbr(current->fitness);
	// 	ft_putchar('\n');
	// 	current = current->next;
	// }
	// ft_putchar('\n');
	// // TEST
	if (new->fitness < old->fitness)
	{
		while (new && new->fitness < old->fitness)
		{
			tmp = new;
			new = new->next;
		}
		tmp->next = old;
		*new_current = new;
	}
	else
	{
		while (old && old->fitness <= new->fitness)
		{
			tmp = old;
			old = old->next;
		}
		tmp->next = new;
		*old_current = old;
	}
}

void			merge_new_nodes(t_node **nodes, t_node **new_nodes)
{
	t_node	*old;
	t_node	*new;

	// // TEST
	// t_node	*current; //remove
	// current = *nodes;
	// while (current)
	// {
	// 	ft_putstr("node score: ");
	// 	ft_putnbr(current->fitness);
	// 	ft_putchar('\n');
	// 	current = current->next;
	// }
	// current = *new_nodes;
	// while (current)
	// {
	// 	ft_putstr("new node score: ");
	// 	ft_putnbr(current->fitness);
	// 	ft_putchar('\n');
	// 	current = current->next;
	// }
	// ft_putchar('\n');
	// // TEST
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

void			node_insert(t_node **new_nodes, t_node *node)
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
