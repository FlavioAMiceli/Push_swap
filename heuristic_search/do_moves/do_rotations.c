/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_rotations.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:45:25 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/20 16:45:25 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../heuristic_search.h"

t_node	*do_ra(t_node *current)
{
	t_node	*new;

	new = (t_node*)ft_memalloc(sizeof(t_node));
	new = node_stackdup(new, current);
	if (!new ||
		!rot(&(new->s_a)))
		ft_putstr_fd("Error in do_ra\n", 2);
	new->n_ops++;
	new->fitness = node_evaluate(new->s_a, new->s_b, new->n_ops);
	new->ops = ft_strjoin(current->ops, "ra\n");
	new->next = NULL;
	new->last_op = RA | (current->last_op & B_OPS);
	return (new);
}

t_node	*do_rb(t_node *current)
{
	t_node	*new;

	new = (t_node*)ft_memalloc(sizeof(t_node));
	new = node_stackdup(new, current);
	if (!new ||
		!rot(&(new->s_b)))
		ft_putstr_fd("Error in do_rb\n", 2);
	new->n_ops++;
	new->fitness = node_evaluate(new->s_a, new->s_b, new->n_ops);
	new->ops = ft_strjoin(current->ops, "rb\n");
	new->next = NULL;
	new->last_op = RB | (current->last_op & A_OPS);
	return (new);
}

t_node	*do_rr(t_node *current)
{
	t_node	*new;

	new = (t_node*)ft_memalloc(sizeof(t_node));
	new = node_stackdup(new, current);
	if (!new ||
		!rot(&(new->s_a)) ||
		!rot(&(new->s_b)))
		ft_putstr_fd("Error in do_rr\n", 2);
	new->n_ops++;
	new->fitness = node_evaluate(new->s_a, new->s_b, new->n_ops);
	new->ops = ft_strjoin(current->ops, "rr\n");
	new->next = NULL;
	new->last_op = RA | RB;
	return (new);
}
