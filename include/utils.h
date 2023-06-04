/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:14:19 by work              #+#    #+#             */
/*   Updated: 2023/06/04 03:39:36 by work             ###   ########.fr       */
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
	void		(*constructor)(struct s_oop *, t_circle *nwq_node);
	void		(*rotate)(struct s_oop *, t_circle *new_node);
	void		(*revrotate)(struct s_oop *, t_circle *new_node);
	void		(*append)(struct s_oop *, t_circle *new_node);
	void		(*prepend)(struct s_oop *, t_circle *new_node);
}	t_oop;

// void		append(t_circle **head, t_circle *new_node);
void		append(t_circle **head, t_circle *new_node);
t_circle	*new_node(int data);
void		prepend(t_circle **head, t_circle *new_node);
void		revrotate(t_circle **head);
void		rotate(t_circle **head);
t_circle	*swap(t_circle *stack);

#endif
