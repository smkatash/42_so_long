/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:58:04 by kanykei           #+#    #+#             */
/*   Updated: 2022/05/16 16:47:38 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_images(t_render *game)
{
	int	x;
	int	y;

	game->exit.image = mlx_xpm_file_to_image(game->mlx, \
	"../image/exit.xpm", &x, &y);
	game->exit.data = mlx_get_data_addr(game->exit.image, \
	&game->exit.bpp, &game->exit.size_line, &game->exit.endian);
	render_sky(game);
	render_coin(game);
	render_wall(game);
	render_player(game);
	render_enemy(game);
}

void	put_pixels(t_render *game, int x, int y)
{
	if (game->buffer_map[y * game->win_width + x] == '1')
		put_pxl_wall(game, x, y);
	else if (game->buffer_map[y * game->win_width + x] == 'C')
		put_pxl_coin(game, x, y);
	else if (game->buffer_map[y * game->win_width + x] == 'P')
		put_pxl_player(game, x, y);
	else if (game->buffer_map[y * game->win_width + x] == 'H')
		put_pxl_enemy(game, x, y);
	else if (game->buffer_map[y * game->win_width + x] == 'E')
		put_pxl_exit(game, x, y);
	else if (game->buffer_map[x * game->win_width + y] == 'E' && \
	game->coins == game->max_coins)
		end_of_game(game, 0);
	else
		put_pxl_sky(game, x, y);
}

void	put_images(t_render *game)
{
	int		height;
	int		width;
	char	*text;

	height = 0;
	while (height < game->win_height)
	{
		width = 0;
		while (width < game->win_width)
		{
			put_pixels(game, width, height);
			width++;
		}
		height++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->base.image, 0, 0);
	text = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->window, 64, 64, 0xffffffff, text);
	free(text);
}
