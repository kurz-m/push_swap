/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:28:54 by makurz            #+#    #+#             */
/*   Updated: 2023/06/06 18:38:39 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "utils.h"
# include <limits.h>

// Defines
# define PARSE 42
# define MOVEMENT 21
# define TRUE 1
# define FALSE 0

int		parse_input(t_oop **stack, int argc, char **argv);
void	error_handling(t_oop **stack, int error_code);
void	parse_error(t_oop **stack, char **nbs);
int		check_sorted(t_oop *stack);

#endif
