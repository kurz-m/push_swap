/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:28:54 by makurz            #+#    #+#             */
/*   Updated: 2023/06/05 16:31:29 by makurz           ###   ########.fr       */
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
	t_circle	**stack_a;
	t_circle	**stack_b;
}	t_container;

int		parse_input(t_oop **stack, int argc, char **argv);
void	error_handling(t_oop **stack, int error_code);

#endif
