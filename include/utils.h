/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:14:19 by work              #+#    #+#             */
/*   Updated: 2023/06/04 15:23:38 by work             ###   ########.fr       */
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
	void		(*constructor)(struct s_oop *);
	void		(*pop)(struct s_oop *);
	void		(*append)(struct s_oop *, t_circle *new_node);
	void		(*prepend)(struct s_oop *, t_circle *new_node);
	void		(*rotate)(struct s_oop *);
	void		(*revrotate)(struct s_oop *);
	void		(*swap)(struct s_oop *);
	void		(*print)(struct s_oop *);
}	t_oop;

// function for oop
void		construct(t_oop *self);
void		pop(t_oop *self);
void		append(t_oop *self, t_circle *new_node);
void		prepend(t_oop *self, t_circle *new_node);
void		rotate(t_oop *self);
void		revrotate(t_oop *self);
void		swap(t_oop *self);
void		print(t_oop *self);
t_circle	*new_node(int data);
void		init_stacks(t_oop **stack_a, t_oop **stack_b);

// void		append(t_circle **head, t_circle *new_node);
// void		append(t_circle **head, t_circle *new_node);
// t_circle	*new_node(int data);
// void		prepend(t_circle **head, t_circle *new_node);
// void		revrotate(t_circle **head);
// void		rotate(t_circle **head);
// t_circle	*swap(t_circle *stack);

#endif
