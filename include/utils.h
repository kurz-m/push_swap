/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:14:19 by work              #+#    #+#             */
/*   Updated: 2023/06/02 09:12:17 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_circle
{
	int					data;
	int					index;
	struct s_circle		*next;
	struct s_circle		*previous;
}	t_circle;

void		append(t_circle **head, t_circle *new_node);
t_circle	*new_node(int data);
void		prepend(t_circle **head, t_circle *new_node);
void		revrotate(t_circle **head);
void		rotate(t_circle **head);
t_circle	*swap(t_circle *stack);

#endif
