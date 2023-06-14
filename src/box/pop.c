/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:55:26 by makurz            #+#    #+#             */
/*   Updated: 2023/06/14 10:59:32 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

// remove the top node of the list and returns it
t_circle	*pop(t_oop *self)
{
	t_circle	*new_top;
	t_circle	*tmp;

	if (self->top == NULL)
		return (NULL);
	if (self->count(self) == 1)
	{
		tmp = self->top;
		self->top->next = NULL;
		self->top->previous = NULL;
		self->top = NULL;
		return (tmp);
	}
	tmp = self->top;
	new_top = self->top->next;
	new_top->previous = self->top->previous;
	self->top->previous->next = new_top;
	self->top = new_top;
	return (tmp);
}
