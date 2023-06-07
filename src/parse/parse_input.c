/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:30:00 by makurz            #+#    #+#             */
/*   Updated: 2023/06/07 18:02:37 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "utils.h"

static int	check_num(const char *nb)
{
	int		i;

	i = 0;
	while (ft_isspace(nb[i]) == TRUE)
		i++;
	if (nb[i] == '-' || nb[i] == '+')
		i++;
	while (nb[i] != '\0')
	{
		if (ft_isdigit(nb[i]) == FALSE)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static int	check_duplicate(t_oop **stack, int nb)
{
	t_circle	*current;

	current = (*stack)->top;
	if (current == NULL)
		return (FALSE);
	while (1)
	{
		if (current->data == nb)
			return (TRUE);
		current = current->next;
		if (current == (*stack)->top)
			break ;
	}
	return (FALSE);
}

static int	valid_input(t_oop **stack, const char *nb)
{
	if (check_num(nb) == FALSE)
		return (FALSE);
	if (ft_atol(nb) > INT_MAX || ft_atol(nb) < INT_MIN)
		return (FALSE);
	if (check_duplicate(stack, ft_atoi(nb)) == TRUE)
		return (FALSE);
	return (TRUE);
}

int	parse_input(t_box *box, int argc, char **argv)
{
	int		i;
	char	**nbs;
	int		j;

	i = 0;
	while (++i <= argc)
	{
		nbs = ft_split(argv[i], ' ');
		j = -1;
		if (NULL == nbs[0])
			parse_error(box, nbs);
		while (nbs[++j] != NULL)
		{
			box->a->elements++;
			if (valid_input(&box->a, nbs[j]))
				box->a->append(box->a, new_node(ft_atoi(nbs[j])));
			else
				parse_error(box, nbs);
		}
		ft_arrfree(nbs);
	}
	box->max = box->a->elements++;
	box->a->indexing(box->a);
	return (TRUE);
}
