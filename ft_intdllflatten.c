/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intdllflatten.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 16:50:22 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/25 16:50:23 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_intdllflatten(t_dll **alst, int n)
{
	t_dll	*node;
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		node = ft_dlldequeue(alst);
		arr[i] = *((int *)(node->content));
		ft_dlldelone(&node, ft_nodedel);
		i++;
	}
	return (arr);
}
