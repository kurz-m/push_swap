/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:54:58 by makurz            #+#    #+#             */
/*   Updated: 2023/06/07 12:54:59 by makurz           ###   ########.fr       */
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

void	print_index(t_oop *self)
{
	t_circle	*current;

	current = self->top;
	ft_printf("Number: %i\n", current->index);
	while (current->next != self->top)
	{
		current = current->next;
		ft_printf("Number: %i\n", current->index);
	}
}
