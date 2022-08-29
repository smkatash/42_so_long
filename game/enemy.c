/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:10:34 by kanykei           #+#    #+#             */
/*   Updated: 2022/05/15 13:11:13 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left_enemy(t_render *game)
{
	int	i;

	i = find_enemy(game);
	if (game->buffer_map[i - 1] != '1' && game->buffer_map[i - 1] != 'E' && \
	game->buffer_map[i - 1] != 'C')
	{
		if (game->buffer_map[i - 1] == 'P')
		{
			game->buffer_map[i] = '0';
			end_of_game(game, 1);
		}
		else
		{
			game->buffer_map[i] = '0';
			game->buffer_map[i - 1] = 'H';
		}
	}
}

void	move_right_enemy(t_render *game)
{
	int	i;

	i = find_enemy(game);
	if (game->buffer_map[i + 1] != '1' && game->buffer_map[i + 1] != 'E' \
	&& game->buffer_map[i + 1] != 'C')
	{
		if (game->buffer_map[i + 1] == 'P')
		{
			game->buffer_map[i] = '0';
			end_of_game(game, 1);
		}
		else
		{
			game->buffer_map[i] = '0';
			game->buffer_map[i + 1] = 'H';
		}
	}
	else
		game->buffer_map[i] = 'H';
}

void	move_down_enemy(t_render *game)
{
	int	i;

	i = find_enemy(game);
	if (game->buffer_map[i + game->win_width] != '1' && \
	game->buffer_map[i + game->win_width] != 'E' && \
	game->buffer_map[i + game->win_width] != 'C')
	{
		if (game->buffer_map[i + game->win_width] == 'P')
		{
			game->buffer_map[i] = '0';
			end_of_game(game, 1);
		}
		else
		{
			game->buffer_map[i] = '0';
			game->buffer_map[i + game->win_width] = 'H';
		}
	}
	else
		game->buffer_map[i] = 'H';
}

void	move_up_enemy(t_render *game)
{
	int	i;

	i = find_enemy(game);
	if (game->buffer_map[i - game->win_width] != '1' && \
	game->buffer_map[i - game->win_width] != 'E' && \
	game->buffer_map[i - game->win_width] != 'C')
	{
		if (game->buffer_map[i - game->win_width] == 'P')
		{
			game->buffer_map[i] = '0';
			end_of_game(game, 1);
		}
		else
		{
			game->buffer_map[i] = '0';
			game->buffer_map[i - game->win_width] = 'H';
		}
	}
	else
		game->buffer_map[i] = 'H';
}
