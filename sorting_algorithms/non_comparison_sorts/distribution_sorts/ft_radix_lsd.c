/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_radix_lsd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 15:05:49 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/10 15:05:50 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Radix LSD sort
**
**	Space:	O(w + n), w is the number of bits required to store each key.
**	Time:	O(w * n), w is the number of bits required to store each key.
**
**	Stable
**	Parallelization is possible.
**
**	This algorithm sorts keys by grouping them by their individual digits.
**
**	Radix has a lower complexity than comparison based algorithms,
**	but comparison based algorithms are measured in the amount of comparisons.
**	This makes the complexities hard to compare.
**
**	Some alternatives include an in-place MSD radix sort, which is a binary
**	quicksort.
**	MSD is also useful for sorting strings instead of integers.
*/

static	int	*count_sort(int *arr, size_t len, int k)
{
	int	*tab[k];
	int	*output;
	int	i;

	ft_bzero(tab, k);
	output = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		tab[(arr[i] / exp) % 2] += 1;
		i++;
	}
	i = 1;
	while (i <= k)
	{
		tab[i] = tab[i] + tab[i - 1];
	}
	i = len;
	while (i >= 0)
	{
		output[tab[(arr[i] / exp) % 2] = arr[i];
		tab[(arr[i] / exp) % 2] = tab[arr[i]] - 1;
		i--;
	}
	free (arr);
	return (output);
}

static int	*ft_radix_lsd_base2(int *arr, size_t len, int max)
{
	int	exp;

	exp = 1;
	while (max / exp > 0)
	{
		arr = count_sort(arr, len, exp);
		exp *=2;
	}
}

int			*ft_radix_lsd(int *arr, size_t len)
{
	int	max;
	int	i;

	max = arr[0];
	i = 1;
	while (i < len)
	{
		max = max > arr[i] ? max : arr[i];
		i++;
	}
	return (radix_lsd_base2(arr, len, max));
}
