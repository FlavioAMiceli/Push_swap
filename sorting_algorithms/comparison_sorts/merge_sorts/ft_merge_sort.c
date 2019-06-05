/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_merge_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 18:54:29 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/05 18:54:30 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Merge sort
**
**
*/

static void	swaproles(int **arr, int **temp)
{
	*arr ^= *temp;
	*temp_arr ^= *arr;
	*arr ^= *temp;
}

static int	*bottom_up_merge(int *arr, int left, int right, int end, int *temp)
{
	
}

int			*ft_merge_sort(int *arr, size_t len, int(*f)(int, int))
{
	int	*temp_arr[len];
	int	i;
	int	width;

	width = 1;
	while (width < len)
	{
		i = 0;
		while (i < len)
		{
			temp_arr = bottom_up_merge(arr, i,/
				ft_min(i + width, n), ft_min(i + 2 * width, n), temp_arr);
			i += 2 * width;
		}
		swaproles(&arr, &temp_arr);
	}
	return (arr);
}
