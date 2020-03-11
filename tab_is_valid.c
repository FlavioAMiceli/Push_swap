/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tab_is_valid.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 18:36:05 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/06/14 18:36:05 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** checks if each character in tab is an ascii digit
*/
int		tab_is_valid(char **tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (ft_isdigit(tab[i][j]) == FALSE)
				if (j != 0 || (tab[i][0] != '+' && tab[i][0] != '-'))
					return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
