/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_tab.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 15:45:41 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/07/04 15:45:44 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*
**	Takes the strings from input tab and turns them into an int array.
*/

int	*set_tab(int *int_tab, char **tab, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		int_tab[i] = ft_atoi(tab[i]);
		i++;
	}
	return (int_tab);
}
