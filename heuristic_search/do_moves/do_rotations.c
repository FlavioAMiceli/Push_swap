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
#include <stdio.h> //REMOBE ME

t_node	*do_ra(t_node *current)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	printf("do_ra current         : %p\n", current);
	printf("do_ra new after malloc: %p\n", new);
	new = node_stackdup(new, current);
	printf("do_ra current p-stackd: %p\n", current);
	printf("do_ra new after stackd: %p\n", new);
	if (!new ||
		!rot(&(new->s_a)))
	{
		ft_putstr_fd("Error in do_ra\n", 2);
		exit(0);
	}
	new->n_ops++;
	new->fitness = node_evaluate(new->s_a, new->s_b, new->n_ops);
	new->ops = ft_strjoin(current->ops, "ra\n");
	new->next = NULL;
	return (new);
}

t_node	*do_rb(t_node *current)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new = node_stackdup(new, current);
	if (!new ||
		!rot(&(new->s_b)))
	{
		ft_putstr_fd("Error in do_rb\n", 2);
		exit(0);
	}
	new->n_ops++;
	new->fitness = node_evaluate(new->s_a, new->s_b, new->n_ops);
	new->ops = ft_strjoin(current->ops, "rb\n");
	new->next = NULL;
	return (new);
}

t_node	*do_rr(t_node *current)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new = node_stackdup(new, current);
	if (!new ||
		!rot(&(new->s_a)) ||
		!rot(&(new->s_b)))
	{
		ft_putstr_fd("Error in do_rr\n", 2);
		exit(0);
	}
	new->n_ops++;
	new->fitness = node_evaluate(new->s_a, new->s_b, new->n_ops);
	new->ops = ft_strjoin(current->ops, "rr\n");
	new->next = NULL;
	return (new);
}
