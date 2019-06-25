/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlstflatten.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 16:50:22 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/25 16:50:23 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_intlstflatten(t_list **alst, int n)
{
	t_list	*node;
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		node = ft_lstdequeue(alst);
		arr[i] = *((int *)(node->content));
		ft_lstdelone(&node, ft_nodedel);
		i++;
	}
	return (arr);
}
