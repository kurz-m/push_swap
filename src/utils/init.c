/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:12:33 by work              #+#    #+#             */
/*   Updated: 2023/06/06 19:09:59 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	construct_container(t_container *container)
{
	container->a->constructor = construct;
	container->a->constructor(container->a);
	container->b->constructor = construct;
	container->b->constructor(container->b);
}

void	construct(t_oop *self)
{
	self->top = NULL;
	self->elements = 0;
	self->max = 0;
	self->deconstructor = desconstruct;
	self->indexing = indexing;
	self->pop = pop;
	self->append = append;
	self->prepend = prepend;
	self->rotate = rotate;
	self->revrotate = revrotate;
	self->swap = swap;
	self->print = print;
	self->print_index = print_index;
}

void	desconstruct(t_oop **self)
{
	t_circle	*current;
	t_circle	*tmp;

	if ((*self)->top == NULL)
		return ;
	current = (*self)->top;
	while (1)
	{
		tmp = current;
		current = current->next;
		free(tmp);
		if (current == (*self)->top)
			break ;
	}
}
