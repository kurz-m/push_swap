/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:54:58 by makurz            #+#    #+#             */
/*   Updated: 2023/06/09 00:09:06 by work             ###   ########.fr       */
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

void	print_cmd(t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd;
	while (current != NULL)
	{
		ft_printf("ERROR\n");
		if (ft_strncmp(current->move, "rb", 2)
			&& ft_strncmp(current->next->move, "ra", 2))
		{
			ft_printf("rr\n");
			current = current->next->next;
		}
		else
		{
			ft_printf("%s", current->move);
			current = current->next;
		}
	}
}
