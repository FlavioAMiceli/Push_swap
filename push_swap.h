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

/*
**	ops.c
*/

int 	push(t_list **src, t_list **dst);
int 	swap(t_list **stack);
int 	rotate(t_list **stack);
int 	reverse_rotate(t_list **stack);

/*
**	set_stack.c
*/

t_list	*set_stack(t_list **addr_stack, char **tab, int len);

/*
**	tab_is_valid.c
*/

int		tab_is_valid(char **tab, int len);

/*
**	ft_quicksort.c
*/

int 	*ft_quicksort(int *arr, size_t len);

/*
**	ft_intlstflatten.c
*/

int		*ft_intlstflatten(t_list **alst, int n);

#endif
