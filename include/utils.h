/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:14:19 by work              #+#    #+#             */
/*   Updated: 2023/06/06 19:31:33 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_circle
{
	int					data;
	int					index;
	struct s_circle		*next;
	struct s_circle		*previous;
}	t_circle;

typedef struct s_oop
{
	t_circle	*top;
	int			elements;
	int			max;
	void		(*constructor)(struct s_oop *);
	void		(*deconstructor)(struct s_oop **);
	void		(*indexing)(struct s_oop *);
	void		(*pop)(struct s_oop *);
	void		(*append)(struct s_oop *, t_circle *new_node);
	void		(*prepend)(struct s_oop *, t_circle *new_node);
	void		(*rotate)(struct s_oop *);
	void		(*revrotate)(struct s_oop *);
	void		(*swap)(struct s_oop *);
	void		(*print)(struct s_oop *);
	void		(*print_index)(struct s_oop *);
}	t_oop;

typedef struct s_container
{
	t_oop	*a;
	t_oop	*b;
}	t_container;

// function for oop
void		construct(t_oop *self);
void		desconstruct(t_oop **self);
void		indexing(t_oop *self);
void		pop(t_oop *self);
void		append(t_oop *self, t_circle *new_node);
void		prepend(t_oop *self, t_circle *new_node);
void		rotate(t_container *container);
void		revrotate(t_oop *self);
void		swap(t_oop *self);
void		print(t_oop *self);
void		print_index(t_oop *self);
t_circle	*new_node(int data);
void		construct_container(t_container *container);

// other utils
int			count_elements(t_oop *self);

#endif
