/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_stackdup.c                                    :+:    :+:            */
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
