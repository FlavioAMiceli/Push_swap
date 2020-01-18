/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heuristic_node.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 17:05:15 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/18 17:05:16 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEURISTIC_NODE_H

# define HEURISTIC_NODE_H

/*
**	For legal move stocks
*/
// PB and RRA are always available together. Aswell as (PA RRB), (SS RRR)
enum				e_moves
{
	SA = 1,
	SB = 2,
	SS_RRR = 4,
	PA_RRB = 8,,
	PB_RRA = 16,
	RA = 32,
	RB = 64,
	RR = 128,
};

typedef struct		s_node
{
	t_stack			*s_a;
	t_stack			*s_b;
	char			*ops;
	unsigned int	fitness;
	unsigned int	n_ops;
	struct s_node	*next;
}					t_node;

#endif
