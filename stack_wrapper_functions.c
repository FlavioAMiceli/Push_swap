/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_wrapper_functions.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 21:05:21 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/01/14 21:05:22 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Returns value at index i in stack.
*/
int		stack_get(t_stack **s, int i)
{
	// TODO
	// TEST EVERYTHING!
	// IF start = S_SIZE - (S_START - S_STACK) is wrong,
	// Than it's also wrong in shift_stack in stack_pointer_ops!
	int	start_n;

	start_n = S_SIZE - (S_START - S_STACK);
	if (i > start_n)
		return (S_STACK[i - (start_n - 1)]);
	return (S_START[i]);
}

/*
**	Sets value at index i in stack.
*/
void	stack_set(t_stack **s, int value, int i)
{
	int	start_n;

	start_n = S_SIZE - (S_START - S_STACK);
	if (i > start_n)
		S_STACK[i - (start_n - 1)] = value;
	S_START[i] = value;
}
