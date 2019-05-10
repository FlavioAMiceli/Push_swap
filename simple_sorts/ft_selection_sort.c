/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_selection_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 10:56:26 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/10 10:56:28 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_selection_sort(int *arr, size_t len, int(*f)(int, int))
{
	int	i;
	int	j;
	int	n;
	int min;

	n = len;
	i = 0;
	while (i < n - 1)
	{
		min = i;
		j = i + 1;
		while (j < n)
		{
			if (f(arr[j], arr[min]) == true)
				min = j;
			j++;
		}
		if (min != i)
			ft_swap(a[i], a[min]);
		i++;
	}
	return (arr);
}
