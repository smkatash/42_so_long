/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:09:10 by kanykei           #+#    #+#             */
/*   Updated: 2022/05/15 17:08:33 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_render *game)
{
	int	i;

	i = find_player(game);
	if (game->buffer_map[i - game->win_width] == 'C')
		game->coins++;
	if (game->buffer_map[i - game->win_width] == 'E' && \
	game->coins == game->max_coins)
		end_of_game(game, 0);
	else if (game->buffer_map[i - game->win_width] != '1' && \
	game->buffer_map[i - game->win_width] != 'E')
	{
		if (game->buffer_map[i - game->win_width] == 'H')
		{
			game->buffer_map[i] = '0';
			end_of_game(game, 1);
		}
		else
		{
			game->buffer_map[i] = '0';
			game->buffer_map[i - game->win_width] = 'P';
			game->steps++;
		}
	}
	move_up_enemy(game);
}

static void	move_down(t_render *game)
{
	int	i;

	i = find_player(game);
	if (game->buffer_map[i + game->win_width] == 'C')
		game->coins++;
	if (game->buffer_map[i + game->win_width] == 'E' && \
	game->coins == game->max_coins)
		end_of_game(game, 0);
	else if (game->buffer_map[i + game->win_width] != '1' && \
	game->buffer_map[i + game->win_width] != 'E')
	{
		if (game->buffer_map[i + game->win_width] == 'H')
		{
			game->buffer_map[i] = '0';
			end_of_game(game, 1);
		}
		else
		{
			game->buffer_map[i] = '0';
			game->buffer_map[i + game->win_width] = 'P';
			game->steps++;
		}
	}
	move_up_enemy(game);
}

static void	move_left(t_render *game)
{
	int	i;

	i = find_player(game);
	if (game->buffer_map[i - 1] == 'C')
		game->coins++;
	if (game->buffer_map[i - 1] == 'E' && game->coins == game->max_coins)
		end_of_game(game, 0);
	else if (game->buffer_map[i - 1] != '1' && game->buffer_map[i - 1] != 'E')
	{
		if (game->buffer_map[i - 1] == 'H')
		{
			game->buffer_map[i] = '0';
			end_of_game(game, 1);
		}
		else
		{
			game->buffer_map[i] = '0';
			game->buffer_map[i - 1] = 'P';
			game->steps++;
		}
	}
	move_right_enemy(game);
}

static void	move_right(t_render *game)
{
	int		i;

	i = find_player(game);
	if (game->buffer_map[i + 1] == 'C')
		game->coins++;
	if (game->buffer_map[i + 1] == 'E' && game->coins == game->max_coins)
		end_of_game(game, 0);
	else if (game->buffer_map[i + 1] != '1' && game->buffer_map[i + 1] != 'E')
	{
		if (game->buffer_map[i + 1] == 'H')
		{
			game->buffer_map[i] = '0';
			end_of_game(game, 1);
		}
		else
		{
			game->buffer_map[i] = '0';
			game->buffer_map[i + 1] = 'P';
			game->steps++;
		}
	}
	move_left_enemy(game);
}

int	key_press(int key, t_render *game)
{
	if (key == KEY_ESC)
		close_game(game);
	if (key == KEY_UP || key == KEY_W)
		move_up(game);
	if (key == KEY_DOWN || key == KEY_S)
		move_down(game);
	if (key == KEY_LEFT || key == KEY_A)
		move_left(game);
	if (key == KEY_RIGHT || key == KEY_D)
		move_right(game);
	write(1, "Moves: ", 8);
	ft_putnbr_fd(game->steps, 1);
	write(1, "\n", 2);
	put_images(game);
	return (0);
}
