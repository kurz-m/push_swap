/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:28:54 by makurz            #+#    #+#             */
/*   Updated: 2023/06/06 14:32:23 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "utils.h"
# include <limits.h>

// Defines
# define PARSE 42
# define TRUE 1
# define FALSE 0

typedef struct s_container
{
	t_oop	*stack_a;
	t_oop	*stack_b;
	int		elements;
}	t_container;

int		parse_input(t_oop **stack, int argc, char **argv);
void	error_handling(t_oop **stack, int error_code);
void	parse_error(t_oop **stack, char **nbs);
int		check_sorted(t_oop *stack);

#endif
