/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_insertion_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 15:21:20 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/10 15:21:21 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_insertion_sort(int *arr, size_t len, int(*f)(int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i - 1;
		while (j >= 0 && f(arr[j - 1], arr[j]) == false)
		{
			ft_swap(&arr[j - 1], &arr[j]);
			j--;
		}
		i++;
	}
	return (arr);
}
