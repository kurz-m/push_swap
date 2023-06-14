/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:55:44 by makurz            #+#    #+#             */
/*   Updated: 2023/06/14 10:58:26 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

void	box_cleanup(t_box *box)
{
	box->a->deconstructor(&box->a);
	free(box->a);
	box->a = NULL;
	box->b->deconstructor(&box->b);
	free(box->b);
	box->b = NULL;
}

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
	self->count = count;
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
		tmp = NULL;
		if (current == (*self)->top)
			break ;
	}
}
