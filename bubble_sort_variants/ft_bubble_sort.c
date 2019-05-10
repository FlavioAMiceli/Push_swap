/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bubble_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 09:41:02 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/10 09:41:03 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int *ft_bubble_sort(int *arr, size_t len, int(*f)(int, int))
{
	int	i;
	int	pass;
	int	swapped;

	swapped = true;
	pass = 0;
	while (swapped)
	{
		i = 1;
		swapped = false;
		while (i < len - pass)
		{
			if (f(arr[i - 1], arr[i]) == false)
			{
				ft_swap(&arr[i - 1], &arr[i]);
				swapped = true;
			}
			i++;
		}
		pass++;
	}
	return (arr);
}
