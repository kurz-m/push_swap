/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:15:17 by work              #+#    #+#             */
/*   Updated: 2023/06/06 17:33:07 by work             ###   ########.fr       */
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
