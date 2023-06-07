/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:55:51 by makurz            #+#    #+#             */
/*   Updated: 2023/06/08 01:58:00 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"
#include <stdio.h>

// FIX: does not work after pop
int	append(t_oop *self, t_circle *new_node)
{
	t_circle	*tmp;

	if (new_node == NULL)
		return (FALSE);
	if (self->top == NULL)
	{
		self->top = new_node;
		self->top->next = new_node;
		self->top->previous = new_node;
		return (TRUE);
	}
	tmp = self->top->previous;
	self->top->previous = new_node;
	tmp->next = new_node;
	new_node->previous = tmp;
	new_node->next = self->top;
	return (TRUE);
}

// FIX: does not work after pop
int	prepend(t_oop *self, t_circle *new_node)
{
	// t_circle	*tmp;

	if (new_node == NULL)
		return (FALSE);
	if (self->top == NULL)
	{
		self->top = new_node;
		self->top->next = new_node;
		self->top->previous = new_node;
		return (TRUE);
	}
	new_node->previous = self->top->previous;
	new_node->next = self->top;
	self->top->previous->next = new_node;
	self->top->previous = new_node;
	self->top = new_node;
	// tmp = self->top->previous;
	// self->top->previous = new_node;
	// tmp->next = new_node;
	// new_node->previous = tmp;
	// new_node->next = self->top;
	// self->top = new_node;
	return (TRUE);
}
