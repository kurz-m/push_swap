/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:56:09 by work              #+#    #+#             */
/*   Updated: 2023/06/06 18:35:02 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	rotate(t_oop *self)
{
	if (self->top == NULL)
		error_handling(&self, MOVEMENT);
	if (self->top->next == NULL)
		error_handling(&self, MOVEMENT);
	self->top = self->top->next;
}

void	revrotate(t_oop *self)
{
	if (self->top == NULL)
		error_handling(&self, MOVEMENT);
	if (self->top->previous == NULL)
		error_handling(&self, MOVEMENT);
	self->top = self->top->previous;
}
