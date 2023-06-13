/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:19:41 by makurz            #+#    #+#             */
/*   Updated: 2023/06/13 13:31:50 by makurz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "utils.h"

# define FINISH_COMMANDS 1

enum e_bonus
{
	SWAP_A,
	SWAP_B,
	SWAP_ALL,
	ROT_A,
	ROT_B,
	ROT_ALL,
	RROT_A,
	RROT_B,
	RROT_ALL,
	PUSH_A,
	PUSH_B,
	EOF,
	NO_COMMAND,
};

int	movements_bonus(t_box *box, int move);

#endif
