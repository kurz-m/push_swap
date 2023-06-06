/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:56:09 by work              #+#    #+#             */
/*   Updated: 2023/06/06 21:04:51 by work             ###   ########.fr       */
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
