/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:09:03 by ktashbae          #+#    #+#             */
/*   Updated: 2022/05/15 16:49:14 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_enemy(t_render *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->buffer_map))
	{
		if (game->buffer_map[i] == 'H')
			break ;
		i++;
	}
	return (i);
}

void	put_pxl_enemy(t_render *game, int width, int height)
{
	int				x;
	int				y;
	unsigned int	attributes;

	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			attributes = get_attribute_data(game->enemy.buffer, x, y);
			if (attributes != 0xFF000000)
				put_pxls(&game->base, x + (width * 64), \
				y + (height * 64), attributes);
			x++;
		}
		y++;
	}
}

int	frame_update_enemy(t_render *game)
{
	static int	frame;

	if (frame == 0)
		game->enemy.buffer = game->enemy.img1;
	if (frame == 50)
		game->enemy.buffer = game->enemy.img2;
	frame++;
	if (frame == 100)
		frame = 0;
	put_images(game);
	return (0);
}

void	render_enemy(t_render *game)
{
	int	x;
	int	y;

	game->enemy.img1.image = mlx_xpm_file_to_image(game->mlx, \
	"../image/hole.xpm", &x, &y);
	game->enemy.img1.data = mlx_get_data_addr(game->enemy.img1.image, \
	&game->enemy.img1.bpp, &game->enemy.img1.size_line, \
	&game->enemy.img1.endian);
	game->enemy.img2.image = mlx_xpm_file_to_image(game->mlx, \
	"../image/hole1.xpm", &x, &y);
	game->enemy.img2.data = mlx_get_data_addr(game->enemy.img2.image, \
	&game->enemy.img2.bpp, &game->enemy.img2.size_line, \
	&game->enemy.img2.endian);
	game->enemy.buffer = game->enemy.img1;
}
