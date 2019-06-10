/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 08:08:04 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/05/10 08:08:06 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_instructions(t_list **alst)
{
	t_list	*current;
	char	**line;

	get_next_line(0, line);
	if (*line)
	{
		current = ft_lstnew(line, ft_strlen(line));
		*alst = current;
		ft_memdel(line);
		get_next_line(0, line);
	}
	while (*line)
	{
		ft_lstappend(&current, ft_lstnew(line, ft_strlen(line)));
		current = current->next;
		ft_memdel(line);
		get_next_line(0, line);
	}
	ft_memdel(line);
	return (alst);
}

int			main(int argc, char **argv)
{
	t_list	**queue;
	int		arr[argc - 1];
	int		sorted[argc - 1];
	int		i;

	queue = get_instructions(queue);
	if (is_valid(queue, argv) == FALSE)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		arr[i] = ft_atoi(argv[i]);
		i++;
	}
	sorted = ft_sort(arr, argc - 1);
	if (checker(sorted, argc - 1, queue))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (0);
}
