/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_queue_init.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 19:20:35 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/20 19:20:35 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../heuristic_search.h"

void	node_queue_init(t_node **nodes, t_stack **a, t_stack **b, int bound)
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
	head->fitness = node_evaluate(*a, *b, 0, bound);
	head->next = NULL;
	*nodes = head;
}
