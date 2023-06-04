/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:12:33 by work              #+#    #+#             */
/*   Updated: 2023/06/04 20:09:55 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	construct_stacks(t_oop **stack_a, t_oop **stack_b)
{
	(*stack_a)->constructor = construct;
	(*stack_a)->constructor(*stack_a);
	(*stack_b)->constructor = construct;
	(*stack_b)->constructor(*stack_b);
}

void	construct(t_oop *self)
{
	self->top = NULL;
	self->deconstructor = desconstruct;
	self->indexing = indexing;
	self->pop = pop;
	self->append = append;
	self->prepend = prepend;
	self->rotate = rotate;
	self->revrotate = revrotate;
	self->swap = swap;
	self->print = print;
}

void	desconstruct(t_oop *self)
{
	t_circle	*current;
	t_circle	*tmp;

	current = self->top;
	while (1)
	{
		tmp = current;
		current = current->next;
		free(tmp);
		if (current == self->top)
			break ;
	}
}

void	indexing(t_oop *self)
{
	t_circle	*current;
	t_circle	*run;

	current = self->top;
	while (1)
	{
		run = self->top;
		while (1)
		{
			if (current->data > run->data)
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
