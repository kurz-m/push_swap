/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:58:57 by work              #+#    #+#             */
/*   Updated: 2023/06/04 14:59:41 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"
#include <stdio.h>

void	append(t_oop *self, t_circle *new_node)
{
	t_circle	*tmp;

	if (self->top == NULL)
	{
		self->top = new_node;
		self->top->next = new_node;
		self->top->previous = new_node;
		return ;
	}
	tmp = self->top->previous;
	self->top->previous = new_node;
	tmp->next = new_node;
	new_node->previous = tmp;
	new_node->next = self->top;
}

void	prepend(t_oop *self, t_circle *new_node)
{
	t_circle	*tmp;

	if (self->top == NULL)
	{
		self->top = new_node;
		self->top->next = new_node;
		self->top->previous = new_node;
		return ;
	}
	tmp = self->top->previous;
	self->top->previous = new_node;
	tmp->next = new_node;
	new_node->previous = tmp;
	new_node->next = self->top;
	self->top = new_node;
}
