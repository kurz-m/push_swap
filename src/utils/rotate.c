/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:56:09 by work              #+#    #+#             */
/*   Updated: 2023/06/04 14:58:24 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	rotate(t_oop *self)
{
	if (self->top == NULL)
		// TODO: error handling
		exit(1);
	if (self->top->next == NULL)
		// TODO: error handling
		exit(1);
	self->top = self->top->next;
}

void	revrotate(t_oop *self)
{
	if (self->top == NULL)
		// TODO: error handling
		exit(1);
	if (self->top->previous == NULL)
		// TODO: error handling
		exit(1);
	self->top = self->top->previous;
}
