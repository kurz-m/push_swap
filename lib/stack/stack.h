/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:14:19 by work              #+#    #+#             */
/*   Updated: 2023/05/30 19:28:28 by makurz           ###   ########.fr       */
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

t_circle	*new_node(int data);
void		add_front(t_circle **lst, t_circle *node);

#endif
