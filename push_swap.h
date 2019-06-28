/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 08:08:15 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/10 08:08:15 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "./libft/libft.h"

# define NUM_ON_STACK *((int *)(node->content))

typedef struct		s_stack
{
	int				*stack;
	int				*start;
	int				*end;
	int				size;
	int				len;
}					t_stack;

/*
**	ops.c
*/

int 	push(t_stack **src, t_stack **dst);
int 	swap(t_stack **stack);
int 	rot(t_stack **stack);
int 	rev_rot(t_stack **stack);

/*
**	stack_pointer.c
*/

void 	inc_start(t_stack **stack);
void 	dec_start(t_stack **stack);
void 	inc_end(t_stack **stack);
void 	dec_end(t_stack **stack);
int		*shift_stack(t_stack **stack);

/*
**	init_stacks.c
*/

void 	init_stacks(t_stack **addr_a, t_stack **addr_b, char **tab, int len);

/*
**	tab_is_valid.c
*/

int		tab_is_valid(char **tab, int len);

/*
**	ft_quicksort.c
*/

int 	*ft_quicksort(int *arr, size_t len);

#endif
