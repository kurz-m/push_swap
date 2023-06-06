/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:14:19 by work              #+#    #+#             */
/*   Updated: 2023/06/06 21:06:05 by work             ###   ########.fr       */
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
	int			(*rotate)(struct s_oop *);
	int			(*revrotate)(struct s_oop *);
	int			(*swap)(struct s_oop *);
	void		(*print)(struct s_oop *);
	void		(*print_index)(struct s_oop *);
}	t_oop;

typedef struct s_box
{
	t_oop	*a;
	t_oop	*b;
}	t_box;

// function for oop
void		construct(t_oop *self);
void		desconstruct(t_oop **self);
void		indexing(t_oop *self);
void		pop(t_oop *self);
void		append(t_oop *self, t_circle *new_node);
void		prepend(t_oop *self, t_circle *new_node);
int			rotate(t_oop *box);
int			revrotate(t_oop *self);
int			swap(t_oop *self);
void		print(t_oop *self);
void		print_index(t_oop *self);
t_circle	*new_node(int data);
void		construct_container(t_box *box);

// other utils
int			count_elements(t_oop *self);

#endif
