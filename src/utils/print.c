/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:54:58 by makurz            #+#    #+#             */
/*   Updated: 2023/06/09 23:50:46 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

void	print(t_oop *self)
{
	t_circle	*current;

	current = self->top;
	ft_printf("Number: %i\n", current->data);
	while (current->next != self->top)
	{
		current = current->next;
		ft_printf("Number: %i\n", current->data);
	}
}

void	print_rank(t_oop *self)
{
	t_circle	*current;

	current = self->top;
	ft_printf("Number: %i\n", current->rank);
	while (current->next != self->top)
	{
		current = current->next;
		ft_printf("Number: %i\n", current->rank);
	}
}

static void	print_optimize(char *prev_cmd, int size)
{
	while (size-- > 0)
	{
		write (1, prev_cmd, 1);
		if (size == 0)
			write (1, "\n", 1);
	}
}

// static void print_push(char *prev_cmd, char **move)
// {
// 	if ((move[0][1] == 'a' && prev_cmd[1] == 'b')
// 		|| (move[0][1] == 'b' && prev_cmd[1] == 'a'))
// 		*move = NULL ;
// 	else
// 		write(1, prev_cmd, ft_strlen(prev_cmd));
// }

void	print_cmd(char *move)
{
	static char		*prev_cmd = NULL;
	int				comp;

	comp = 1;
	if (prev_cmd == NULL)
	{
		prev_cmd = move;
		return ;
	}
	if (ft_strlen(prev_cmd) == 4)
		comp++;
	if (*move == 'p' || *prev_cmd == 'p')
		// print_push(prev_cmd, &move);
		write(1, prev_cmd, ft_strlen(prev_cmd));
	else if ((move[comp] == 'a' && prev_cmd[comp] == 'b')
		|| (move[comp] == 'b' && prev_cmd[comp] == 'a'))
	{
		print_optimize(prev_cmd, ft_strlen(move) - 1);
		move = NULL;
	}
	else
		write(1, prev_cmd, ft_strlen(prev_cmd));
	prev_cmd = move;
}
