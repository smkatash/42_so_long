/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_to_pxls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:22:01 by ktashbae          #+#    #+#             */
/*   Updated: 2022/05/15 16:48:57 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_sky(t_render *game)
{
	int	x;
	int	y;

	game->sky.img1.image = mlx_xpm_file_to_image(game->mlx, \
	"../image/desert.xpm", &x, &y);
	game->sky.img2.image = mlx_xpm_file_to_image(game->mlx, \
	"../image/desert1.xpm", &x, &y);
	game->sky.img1.data = mlx_get_data_addr(game->sky.img1.image, \
	&game->sky.img1.bpp, &game->sky.img1.size_line, &game->sky.img1.endian);
	game->sky.img2.data = mlx_get_data_addr(game->sky.img2.image, \
	&game->sky.img2.bpp, &game->sky.img2.size_line, &game->sky.img2.endian);
	game->sky.buffer = game->sky.img1;
}

void	render_wall(t_render *game)
{
	int	x;
	int	y;

	game->wall.img1.image = mlx_xpm_file_to_image(game->mlx, \
	"../image/stones.xpm", &x, &y);
	game->wall.img2.image = mlx_xpm_file_to_image(game->mlx, \
	"../image/stones1.xpm", &x, &y);
	game->wall.img1.data = mlx_get_data_addr(game->wall.img1.image, \
	&game->wall.img1.bpp, &game->wall.img1.size_line, &game->wall.img1.endian);
	game->wall.img2.data = mlx_get_data_addr(game->wall.img2.image, \
	&game->wall.img2.bpp, &game->wall.img2.size_line, &game->wall.img2.endian);
	game->wall.buffer = game->wall.img1;
}

void	render_player(t_render *game)
{
	int	x;
	int	y;

	game->player.img1.image = mlx_xpm_file_to_image(game->mlx, \
	"../image/player_run.xpm", &x, &y);
	game->player.img2.image = mlx_xpm_file_to_image(game->mlx, \
	"../image/player_run1.xpm", &x, &y);
	game->player.img1.data = mlx_get_data_addr(game->player.img1.image, \
	&game->player.img1.bpp, &game->player.img1.size_line, \
	&game->player.img1.endian);
	game->player.img2.data = mlx_get_data_addr(game->player.img2.image, \
	&game->player.img2.bpp, &game->player.img2.size_line, \
	&game->player.img2.endian);
	game->player.buffer = game->player.img1;
}

void	render_coin(t_render *game)
{
	int	x;
	int	y;

	game->coin.image = mlx_xpm_file_to_image(game->mlx, \
	"../image/points.xpm", &x, &y);
	game->coin.data = mlx_get_data_addr(game->coin.image, \
	&game->coin.bpp, &game->coin.size_line, &game->coin.endian);
}
