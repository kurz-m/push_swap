/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:25:31 by makurz            #+#    #+#             */
/*   Updated: 2023/06/06 20:45:55 by work             ###   ########.fr       */
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
	else if (error_code == MOVEMENT)
		write(2, "There was a problem with a stack movement.\n", 43);
	else if (error_code == ALLOC_FAIL)
		write(2, "There was a problem with a memory allocation.\n", 46);
	container_cleanup(box);
	exit(EXIT_FAILURE);
}

void	parse_error(t_box *box, char **nbs)
{
	ft_arrfree(nbs);
	error_handling(box, PARSE);
}
