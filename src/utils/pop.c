/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:55:26 by makurz            #+#    #+#             */
/*   Updated: 2023/06/08 16:18:31 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

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

// t_circle	*pop(t_oop *self)
// {
// 	t_circle	*new_top;
// 	t_circle	*tmp;
// 
// 	tmp = NULL;
// 		return (NULL);
// 	if (self->count(self) == 1)
// 	{
// 		tmp = self->top;
// 		self->top->next = NULL;
// 		self->top->previous = NULL;
// 		self->top = NULL;
// 		return (tmp);
// 	}
// 	new_top = self->top->next;
// 	new_top->previous = self->top->previous;
// 	self->top->previous->next = new_top;
// 	self->top = new_top;
// }
