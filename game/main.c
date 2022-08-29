/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:08:50 by kanykei           #+#    #+#             */
/*   Updated: 2022/05/16 16:49:41 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *error)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

static void	init_game(t_render *game)
{
	game->mlx = mlx_init();
	game->win_width = 0;
	game->win_height = 0;
	game->steps = 1;
	game->coins = 0;
	game->max_coins = 0;
	game->player.frame = 0;
	game->wall.frame = 0;
	game->sky.frame = 0;
	game->enemy.frame = 0;
	game->buffer_map = NULL;
}

static void	get_map(char *map, t_render *game)
{
	map_read(map, game);
	parse_map(game);
}

static void	launch_window(t_render *game)
{
	game->window = mlx_new_window(game->mlx, game->win_width * 64, \
	game->win_height * 64, "so_long");
	if (!game->mlx)
		ft_error("Window generation failed.\n");
	game->base.image = mlx_new_image(game->mlx, game->win_width * 64, \
	game->win_height * 64);
	game->base.data = mlx_get_data_addr(game->base.image, &game->base.bpp, \
	&game->base.size_line, &game->base.endian);
}

int	main(int argc, char *argv[])
{
	t_render	game;

	if (argc != 2)
		ft_error("Not enough arguments!\n");
	if (ft_strncmp(".ber", &argv[1][ft_strlen(argv[1]) - 4], 4) != 0)
		ft_error("Map should be .ber format\n");
	init_game(&game);
	get_map(argv[1], &game);
	render_images(&game);
	launch_window(&game);
	put_images(&game);
	mlx_loop_hook(game.mlx, frame_loop, &game);
	mlx_key_hook(game.window, key_press, &game);
	mlx_hook(game.window, 17, (1L << 17), exit_game, "Exiting the game...");
	mlx_loop(game.mlx);
	return (0);
}
