/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basecase.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 17:05:15 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/18 17:05:16 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASECASE_H

# define BASECASE_H

# include "../push_swap.h"

void bc_to_a_small(t_stacks *s, int lo, int hi);
void to_a_123(t_stacks *s);
void to_a_213(t_stacks *s);
void to_a_312(t_stacks *s);
void to_a_321(t_stacks *s);

void to_b_132(t_stacks *s);
void to_b_213(t_stacks *s);
void to_b_231(t_stacks *s);
void to_b_312(t_stacks *s);
void to_b_321(t_stacks *s);

void bc_to_b(t_stacks *s, int lo, int hi);
void bc_to_a(t_stacks *s, int lo, int hi);

#endif
