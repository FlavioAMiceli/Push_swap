/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heuristic_search.h                                 :+:    :+:            */
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
	unsigned int	n_ops;
	unsigned int	fitness;
	struct s_node	*next;
}					t_node;

/*
**	do_moves/do_*.c
*/
int				get_legal_moves(t_node *current);
void			do_moves(t_node **new_nodes, t_node *current, int move_stock);
t_node			*do_sa(t_node *current);
t_node			*do_sb(t_node *current);
t_node			*do_ss(t_node *current);
t_node			*do_rrr(t_node *current);
t_node			*do_pa(t_node *current);
t_node			*do_rrb(t_node *current);
t_node			*do_pb(t_node *current);
t_node			*do_rra(t_node *current);
t_node			*do_ra(t_node *current);
t_node			*do_rb(t_node *current);
t_node			*do_rr(t_node *current);

/*
**	node/node.c
*/
t_node			*node_stackdup(t_node *new, t_node *current);
t_node			**node_delhead(t_node **nodes);
unsigned int	node_evaluate(
					t_stack *stack_a, t_stack *stack_b, unsigned int n_ops);
void			node_delall(t_node **nodes);
t_node			**node_queue_init(
					t_node **nodes, t_stack **a, t_stack **b, t_size n);
t_node			**node_insert(t_node **new_nodes, t_node *node);
t_node			**insert_new_nodes(t_node **nodes, t_node **new_nodes);

#endif
