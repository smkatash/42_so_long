/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixels_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:36:06 by ktashbae          #+#    #+#             */
/*   Updated: 2022/05/16 12:45:32 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pxls(t_vertex *new_attr, int width, int height, unsigned int attr)
{
	char	*set;

	set = new_attr->data + height * new_attr->size_line + \
	width * (new_attr->bpp / 8);
	*(unsigned int *)set = attr;
}

unsigned int	get_attribute_data(t_vertex img, int x, int y)
{
	char	*data;

	data = img.data + y * img.size_line + x * (img.bpp / 8);
	return (*(unsigned int *)data);
}

void	put_pxl_exit(t_render *game, int width, int height)
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
			attributes = get_attribute_data(game->exit, x, y);
			if (attributes != 0xFF000000)
				put_pxls(&game->base, x + (width * 64), \
				y + (height * 64), attributes);
			x++;
		}
		y++;
	}
}
