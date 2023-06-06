/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:00:20 by work              #+#    #+#             */
/*   Updated: 2023/06/06 18:35:12 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	swap(t_oop *self)
{
	t_circle	*tmp;

	if (self->top == NULL)
		error_handling(&self, MOVEMENT);
	if (self->top->next == NULL)
		error_handling(&self, MOVEMENT);
	tmp = self->top->next;
	tmp->next->previous = self->top;
	self->top->next = tmp->next;
	tmp->next = self->top;
	tmp->previous = self->top->previous;
	tmp->previous->next = tmp;
	self->top->previous = tmp;
}
