/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:55:51 by makurz            #+#    #+#             */
/*   Updated: 2023/06/14 10:59:08 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

// append a new node to the end of the list
int	append(t_oop *self, t_circle *new_node)
{
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
	return (TRUE);
}

// prepend a new node to the beginning of the list
int	prepend(t_oop *self, t_circle *new_node)
{
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
	return (TRUE);
}
