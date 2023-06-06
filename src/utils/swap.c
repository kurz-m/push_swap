/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:00:20 by work              #+#    #+#             */
/*   Updated: 2023/06/06 21:06:30 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

int	swap(t_oop *self)
{
	t_circle	*tmp;

	if (self->top == NULL)
		return (FALSE);
	if (self->top->next == NULL)
		return (FALSE);
	tmp = self->top->next;
	tmp->next->previous = self->top;
	self->top->next = tmp->next;
	tmp->next = self->top;
	tmp->previous = self->top->previous;
	tmp->previous->next = tmp;
	self->top->previous = tmp;
	return (TRUE);
}
