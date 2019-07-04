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

int	*set_tab(int *sorted_tab, char **tab, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		sorted_tab[i] = ft_atoi(tab[i]);
		i++;
	}
	return (sorted_tab);
}
