/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 09:44:09 by ktashbae          #+#    #+#             */
/*   Updated: 2022/05/16 16:49:34 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_perror(char *error, t_render *game)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	if (game->buffer_map != NULL)
		free(game->buffer_map);
	exit(EXIT_FAILURE);
}

int	exit_game(char *message)
{
	ft_putstr_fd(message, 1);
	exit(EXIT_SUCCESS);
}

void	close_game(t_render *game)
{
	if (game->mlx != NULL)
		mlx_destroy_window(game->mlx, game->window);
	ft_putstr_fd("Exiting the game...\n", 1);
	if (game->buffer_map)
		free(game->buffer_map);
	exit(EXIT_SUCCESS);
}

void	end_of_game(t_render *game, int result)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->buffer_map))
	{
		if (game->buffer_map[i] == 'P')
			break ;
		i++;
	}
	game->buffer_map[i] = '0';
	if (result == 0)
	{
		game->steps++;
		write(1, "Congratulations! You won in ", 28);
		ft_putnbr_fd(game->steps, 1);
		write(1, " steps!\n", 8);
	}
	else
		ft_putstr_fd("Oh my..oh my..! You lost the game!\n", 1);
	close_game(game);
}

int	find_player(t_render *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->buffer_map))
	{
		if (game->buffer_map[i] == 'P')
			break ;
		i++;
	}
	return (i);
}
