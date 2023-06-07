/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:25:31 by makurz            #+#    #+#             */
/*   Updated: 2023/06/07 14:09:45 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	error_handling(t_box *box, int error_code)
{
	if (DEBUGGING == 0)
		write(2, "Error\n", 6);
	else if (error_code == PARSE)
		write(2, "There was a problem with input parsing.\n", 40);
	else if (error_code == ALLOC_FAIL)
		write(2, "There was a problem with a memory allocation.\n", 46);
	else if (error_code == PUSH)
		write(2, "There was a problem with a stack push.\n", 39);
	else if (error_code == SWAP)
		write(2, "There was a problem with a stack swap.\n", 39);
	else if (error_code == ROTATE)
		write(2, "There was a problem with a stack rotation.\n", 43);
	else if (error_code == REVROTATE)
		write(2, "There was a problem with a stack revrotation.\n", 46);
	box_cleanup(box);
	exit(EXIT_FAILURE);
}

void	parse_error(t_box *box, char **nbs)
{
	ft_arrfree(nbs);
	error_handling(box, PARSE);
}
