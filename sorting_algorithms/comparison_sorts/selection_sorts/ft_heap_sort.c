/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_heap_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 16:24:47 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/05 16:24:50 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Heap sort
**
**	Space: 	O(n) total, O(1) aux
**	Time:	O(n log n) constant, or O(n) best with equal keys.
**
**	Improved selection sort.
**	Slower than a well implemented quicksort, but has a better worst case.
**	Inplace, unstable.
**
**	Divides input in a sorted and unsorted partition, moves the largest element
**	Of the unsorted partition to the sorted partition.
*/

// static	int	*heapify(int *arr, size_t len, int(*f)(int, int))
// {
// 	int	i;
//
// 	i = 1;
// 	while (i < len)
// 	{
// 		sift_
// 	}
// }
//
// int	*ft_heap_sort(int *arr, size_t len, int(*f)(int, int))
// {
// 	int	end;
//
// 	arr = heapify(arr, len, f);
// 	end = len - 1;
// 	while (end > 0)
// 	{
// 		ft_swap(arr[end], arr[0]);
// 		end--;
// 		sift_down(arr, 0, end)
// 	}
// 	return (arr);
// }
