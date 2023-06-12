/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:28:45 by makurz            #+#    #+#             */
/*   Updated: 2023/06/12 17:03:54 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_box		box;

	if (argc < 2)
		return (EXIT_FAILURE);
	box.a = ft_calloc(1, sizeof(t_oop));
	box.b = ft_calloc(1, sizeof(t_oop));
	if (NULL == box.a || NULL == box.b)
		error_handling(&box, ALLOC_FAIL);
	construct_box(&box);
	parse_input(&box, argc - 1, argv);
	if (check_sorted(box.a) == FALSE)
		sort_main(&box);
	print_cmd("");
	box_cleanup(&box);
	return (EXIT_SUCCESS);
}
