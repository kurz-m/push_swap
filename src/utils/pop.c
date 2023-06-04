/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:02:47 by work              #+#    #+#             */
/*   Updated: 2023/06/04 15:44:40 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

void	pop(t_oop *self)
{
	t_circle	*tmp_top;

	tmp_top = self->top->next;
	self->top->next = tmp_top->next;
	self->top->previous->next = tmp_top;
	self->top = tmp_top;
}
