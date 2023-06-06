/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:10:05 by work              #+#    #+#             */
/*   Updated: 2023/06/06 18:16:50 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	indexing(t_oop *self)
{
	t_circle	*current;
	t_circle	*run;

	current = self->top;
	if (NULL == current)
		return ;
	while (1)
	{
		run = self->top;
		while (1)
		{
			if (current->data >= run->data)
				current->index += 1;
			run = run->next;
			if (run == self->top)
				break ;
		}
		current = current->next;
		if (current == self->top)
			break ;
	}
}

int	count_elements(t_oop *self)
{
	int			count;
	t_circle	*current;

	count = 0;
	current = self->top;
	if (current == NULL)
		return (0);
	count++;
	while (current->next != self->top)
	{
		count++;
		current = current->next;
	}
	self->elements = count;
	return (count);
}
