/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cocktail_sort.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 10:47:30 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/10 10:47:31 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int *ft_cocktail_sort(int *arr, size_t len, int(*f)(int, int))
{
	int	i;
	int	pass;
	int	swapped;

	swapped = true;
	pass = 0;
	while (swapped)
	{
		i = pass;
		swapped = false;
		while (i < len - pass - 1)
		{
			if (f(arr[i], arr[i + 1]) == false)
			{
				ft_swap(&arr[i], &arr[i + 1]);
				swapped = true;
			}
			i++;
		}
		while (i > pass + 1)
		{
			if (f(arr[i - 1], arr[i]) == false)
			{
				ft_swap(&arr[i - 1], &arr[i]);
				swapped = true;
			}
			i--;
		}
		pass++;
	}
	return (arr);
}
