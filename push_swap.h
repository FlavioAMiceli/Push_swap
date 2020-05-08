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

/*
**	stack_pointer_ops.c
*/
# define BASE_CASE_LEN 3

typedef struct		s_stack
{
	int				*stack;
	int				*start;
	int				*end;
	int				size;
	int				len;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

/*
**	sift.c
*/
void 				partition_to_b(t_stacks *s, int *sorted, int lo, int hi);

/*
**	ops.c
*/
int					push(t_stack **src, t_stack **dst);
int					swap(t_stack **stack);
int					rot(t_stack **stack);
int					rev_rot(t_stack **stack);

/*
**	stack_pointer_ops.c
*/
void				inc_start(t_stack **s);
void				dec_start(t_stack **s);
void				inc_end(t_stack **s);
void				dec_end(t_stack **s);
void				shift_stack(t_stack **s);

/*
**	stack_management.c
*/
void				init_stacks_no_tab(
	t_stack **addr_a, t_stack **addr_b, size_t len, size_t size_type);
void				init_stacks(\
	t_stack **addr_a, t_stack **addr_b, char **tab, int len);
void				del_stacks(\
	t_stack **addr_a, t_stack **addr_b);

/*
**	tab_is_valid.c
*/
int					tab_is_valid(char **tab, int len);

/*
**	set_tab.c
*/
int					*set_tab(int *sorted_tab, char **tab, int n);

/*
**	ft_quicksort.c
*/
int					*ft_quicksort(int *arr, size_t len);

/*
**	math.c
*/
int					ceil_log(int exp, int base);

/*
**	stack_wrapper_functions.c
*/
int					stack_get(t_stack *s, int i);
void				stack_set(t_stack *s, int value, int i);
int					stack_value_index(t_stack *s, int value);
void				stack_print(t_stack *s);

/*
**	basecase.c
*/
void 				bc_to_a(t_stacks *s, int lo, int hi);
void 				bc_to_b(t_stacks *s, int lo, int hi);

#endif
