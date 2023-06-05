/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:30:00 by makurz            #+#    #+#             */
/*   Updated: 2023/06/05 18:22:28 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

static int	check_num(char *nb)
{
	int		i;

	i = 0;
	while (ft_isspace(nb[i]) == TRUE)
		i++;
	if (nb[i] == '-' || nb[i] == '+')
		i++;
	while(nb[i] != '\0')
	{
		if (ft_isdigit(nb[i]) == FALSE)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static int	valid_input(char *nb)
{
	if (check_num(nb) == FALSE)
		return (FALSE);
	if (ft_atol(nb) > INT_MAX || ft_atol(nb) < INT_MIN)
		return (FALSE);
	return (TRUE);
}

int	parse_input(t_oop **stack, int argc, char **argv)
{
	int		i;
	char	**nbs;
	int		j;

	i = 0;
	while (++i <= argc)
	{
		nbs = ft_split(argv[i], ' ');
		j = -1;
		if  (NULL == nbs[0])
			error_handling(stack, PARSE);
		while (nbs[++j] != NULL)
		{
			if (valid_input(nbs[j]))
				(*stack)->append(*stack, new_node(ft_atoi(nbs[j])));
			else
				error_handling(stack, PARSE);

		}
		ft_arrfree(nbs);
	}
	return (TRUE);
}
