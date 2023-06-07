/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:55:26 by makurz            #+#    #+#             */
/*   Updated: 2023/06/08 01:57:44 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

void	pop(t_oop *self)
{
	t_circle	*new_top;

	if (self->top == NULL)
		return ;
	// TODO: cannot be null => change to list lenght
	if (self->top->next == NULL)
	{
		self->top->next = NULL;
		self->top->previous = NULL;
		self->top = NULL;
		return ;
	}
	// FIX: does not seem to work
	new_top = self->top->next;
	self->top->next = new_top->next;
	self->top->previous->next = new_top;
	self->top = new_top;
}
