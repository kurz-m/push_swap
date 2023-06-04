/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:00:20 by work              #+#    #+#             */
/*   Updated: 2023/06/04 15:00:54 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	swap(t_oop *self)
{
	t_circle	*tmp;

	if (self->top == NULL)
		// TODO: empty struct error handling
		exit(1);
	if (self->top->next == NULL)
		// TODO: empty struct error handling
		exit(1);
	tmp = self->top->next;
	tmp->next->previous = self->top;
	self->top->next = tmp->next;
	tmp->next = self->top;
	tmp->previous = self->top->previous;
	tmp->previous->next = tmp;
	self->top->previous = tmp;
}
