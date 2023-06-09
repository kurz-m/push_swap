/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:57:31 by makurz            #+#    #+#             */
/*   Updated: 2023/06/09 11:50:36 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// struct for the double linked circular list
typedef struct s_circle
{
	int					data;
	int					rank;
	struct s_circle		*next;
	struct s_circle		*previous;
}	t_circle;

// struct for the movements
typedef struct s_cmd
{
	char			*move;
	struct s_cmd	*next;
}	t_cmd;

// object struct for holding the functions
typedef struct s_oop
{
	t_circle	*top;
	int			elements;
	void		(*constructor)(struct s_oop *);
	void		(*deconstructor)(struct s_oop **);
	void		(*indexing)(struct s_oop *);
	int			(*count)(struct s_oop *);
	t_circle	*(*pop)(struct s_oop *);
	int			(*append)(struct s_oop *, t_circle *new_node);
	int			(*prepend)(struct s_oop *, t_circle *new_node);
	int			(*rotate)(struct s_oop *);
	int			(*revrotate)(struct s_oop *);
	int			(*swap)(struct s_oop *);
	void		(*print)(struct s_oop *);
	void		(*print_rank)(struct s_oop *);
}	t_oop;

// box for holding all other structs
typedef struct s_box
{
	int		size;
	t_cmd	*cmd;
	t_oop	*a;
	t_oop	*b;
}	t_box;

// function for oop
void		construct(t_oop *self);
void		desconstruct(t_oop **self);
void		indexing(t_oop *self);
int			count(t_oop *self);
t_circle	*pop(t_oop *self);
int			append(t_oop *self, t_circle *new_node);
int			prepend(t_oop *self, t_circle *new_node);
int			rotate(t_oop *box);
int			revrotate(t_oop *self);
int			swap(t_oop *self);
void		print(t_oop *self);
void		print_rank(t_oop *self);
void		print_cmd(char *move);
t_circle	*new_node(int data);
void		construct_box(t_box *box);
void		box_cleanup(t_box *box);

#endif
