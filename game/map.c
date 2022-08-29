/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:54:45 by ktashbae          #+#    #+#             */
/*   Updated: 2022/05/16 16:19:24 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	parse_walls(t_render *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(game->buffer_map))
	{
		if (i < game->win_width)
		{
			if (game->buffer_map[i] != '1')
				ft_perror("Map: Wall was not built well!\n", game);
		}
		else if (i % game->win_width == 0 || \
		i % game->win_width == game->win_width - 1)
		{
			if (game->buffer_map[i] != '1')
				ft_perror("Map: Wall was not built well!\n", game);
		}
		else if (i > ft_strlen(game->buffer_map) - game->win_width)
		{
			if (game->buffer_map[i] != '1')
				ft_perror("Map: Wall was not built well!\n", game);
		}
		i++;
	}
}

static void	check_input(int input, int type, t_render *game)
{
	if (input == 0 && type == 1)
		ft_perror("Map: Define at least one exit!\n", game);
	if (input < 1 && type == 3)
		ft_perror("Map: Define at least one collectible!\n", game);
	if (input != 1 && type == 4)
		ft_perror("Map: Define at least player position!\n", game);
}

static void	parse_positions(t_render *game)
{
	int	i;
	int	exit;
	int	player;
	int	enemy;

	i = 0;
	exit = 0;
	player = 0;
	enemy = 0;
	while (i < ft_strlen(game->buffer_map))
	{
		if (game->buffer_map[i] == 'E')
			exit++;
		else if (game->buffer_map[i] == 'P')
			player++;
		else if (game->buffer_map[i] == 'C')
			game->max_coins++;
		check_input_type(game->buffer_map[i], "E10HCP", game);
		i++;
	}
	check_input(exit, 1, game);
	check_input(game->max_coins, 3, game);
	check_input(player, 4, game);
}

void	parse_map(t_render *game)
{
	if (game->win_height == game->win_width)
		ft_perror("Map is not rectangular!\n", game);
	else if (game->win_height * game->win_width != ft_strlen(game->buffer_map))
		ft_perror("Map is not rectangular!\n", game);
	else if (game->win_height > 127 || game->win_width > 128)
		ft_perror("Map size is too big!\n", game);
	parse_walls(game);
	parse_positions(game);
}

void	map_read(char *file, t_render *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 1)
		ft_error("Map: Failed to open a file!\n");
	line = get_next_line(fd);
	game->win_width = ft_strlen(line) - 1;
	game->buffer_map = ft_update_line(line);
	game->win_height = 0;
	game->steps = 0;
	free(line);
	while (line)
	{
		game->win_height++;
		line = get_next_line(fd);
		if (line != NULL)
			game->buffer_map = ft_join_lines(game->buffer_map, line);
	}
	free(line);
	close(fd);
}
