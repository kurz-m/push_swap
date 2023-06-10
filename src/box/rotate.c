/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:55:20 by makurz            #+#    #+#             */
/*   Updated: 2023/06/07 12:55:20 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

int	rotate(t_oop *self)
{
	if (self->top == NULL)
		return (FALSE);
	if (self->top->next == NULL)
		return (FALSE);
	self->top = self->top->next;
	return (TRUE);
}

int	revrotate(t_oop *self)
{
	if (self->top == NULL)
		return (FALSE);
	if (self->top->previous == NULL)
		return (FALSE);
	self->top = self->top->previous;
	return (TRUE);
}
