/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:55:05 by makurz            #+#    #+#             */
/*   Updated: 2023/06/10 00:35:33 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	update_elements(t_box *box, int update)
{
	if (update == UPDATE_A)
	{
		box->a->elements++;
		box->b->elements--;
	}
	else if (update == UPDATE_B)
	{
		box->a->elements--;
		box->b->elements++;
	}
}

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
				current->rank += 1;
			run = run->next;
			if (run == self->top)
				break ;
		}
		current = current->next;
		if (current == self->top)
			break ;
	}
}

int	count(t_oop *self)
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
