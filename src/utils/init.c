/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:55:44 by makurz            #+#    #+#             */
/*   Updated: 2023/06/07 22:45:55 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	construct_box(t_box *box)
{
	box->size = 0;
	box->a->constructor = construct;
	box->a->constructor(box->a);
	box->b->constructor = construct;
	box->b->constructor(box->b);
}

void	construct(t_oop *self)
{
	self->top = NULL;
	self->elements = 0;
	self->deconstructor = desconstruct;
	self->indexing = indexing;
	self->pop = pop;
	self->append = append;
	self->prepend = prepend;
	self->rotate = rotate;
	self->revrotate = revrotate;
	self->swap = swap;
	self->print = print;
	self->print_rank = print_rank;
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
