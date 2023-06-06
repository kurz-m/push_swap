/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:28:54 by makurz            #+#    #+#             */
/*   Updated: 2023/06/06 19:24:58 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "utils.h"
# include <limits.h>

# ifndef DEBUGGING
#  define DEBUGGING 0
# endif

// Defines
# define PARSE 42
# define MOVEMENT 21
# define ALLOC_FAIL 5
# define TRUE 1
# define FALSE 0

int		parse_input(t_container *container, int argc, char **argv);
void	error_handling(t_container *container, int error_code);
void	parse_error(t_container *container, char **nbs);
int		check_sorted(t_oop *stack);
void	container_cleanup(t_container *container);

#endif
