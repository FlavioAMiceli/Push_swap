/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_stack.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 18:32:48 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/14 18:32:49 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*set_stack(t_list **addr_stack, char **tab, int len)
{
	int	i;
	int	*num;

	i = len - 1;
	while (i >= 0)
	{
		num = (int *)malloc(sizeof(int));
		*num = ft_atoi(tab[i]);
		ft_lstadd(addr_stack, ft_lstnew(num, sizeof(int)));
		i--;
	}
	return (*addr_stack);
}
