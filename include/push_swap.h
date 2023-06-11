/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:28:54 by makurz            #+#    #+#             */
/*   Updated: 2023/06/12 01:38:41 by makurz           ###   ########.fr       */
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
# define TRUE 1
# define FALSE 0
# define UPDATE_A 21
# define UPDATE_B 42
# define SORT_SMALL 1
# define SORT_BIG 2

enum e_errors
{
	PARSE,
	ALLOC_FAIL,
	PUSH,
	SWAP,
	ROTATE,
	REVROTATE,
};

// enum e_movements
// {
// 	SWAP_A,
// 	SWAP_B,
// 	SWAP_ALL,
// 	ROT_A,
// 	ROT_B,
// 	ROT_ALL,
// 	RROT_A,
// 	RROT_B,
// 	RROT_ALL,
// 	PUSH_A,
// 	PUSH_B,
// };

int		parse_input(t_box *box, int argc, char **argv);
void	error_handling(t_box *box, int error_code);
void	parse_error(t_box *box, char **nbs);
int		check_sorted(t_oop *stack);
void	box_cleanup(t_box *box);
void	movements_main(t_box *box, int move);
void	update_elements(t_box *box, int update);
void	sort_main(t_box *box);
void	sort(t_box *box);

#endif
