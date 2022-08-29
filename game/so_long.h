/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:08:10 by ktashbae          #+#    #+#             */
/*   Updated: 2022/05/16 16:48:24 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../gnL/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef enum e_key {
	KEY_UP = 126,
	KEY_W = 13,
	KEY_DOWN = 125,
	KEY_S = 1,
	KEY_LEFT = 123,
	KEY_A = 0,
	KEY_RIGHT = 124,
	KEY_D = 2,
	KEY_ESC = 53,
}	t_key;

typedef struct s_vertex
{
	void	*image;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}			t_vertex;

typedef struct s_player
{
	int			x;
	int			y;
	int			frame;
	t_vertex	buffer;
	t_vertex	img1;
	t_vertex	img2;
}				t_player;

typedef struct s_wall
{
	int			x;
	int			y;
	int			frame;
	t_vertex	buffer;
	t_vertex	img1;
	t_vertex	img2;
}				t_wall;

typedef struct s_sky
{
	int			x;
	int			y;
	int			frame;
	t_vertex	buffer;
	t_vertex	img1;
	t_vertex	img2;
}				t_sky;

typedef struct s_hole
{
	int			x;
	int			y;
	int			frame;
	t_vertex	buffer;
	t_vertex	img1;
	t_vertex	img2;
}				t_hole;

typedef struct s_render
{
	void		*mlx;
	void		*window;
	int			win_height;
	int			win_width;
	char		*buffer_map;
	t_vertex	base;
	t_vertex	coin;
	t_vertex	exit;
	t_player	player;
	t_wall		wall;
	t_sky		sky;
	t_hole		enemy;
	int			coins;
	int			max_coins;
	int			steps;
}				t_render;
// Map 
void			map_read(char *file, t_render *game);
void			parse_map(t_render *game);
char			*ft_update_line(char *str);
char			*ft_join_lines(char *s1, char *s2);
void			check_input_type(char ch, char const *type, t_render *game);

// XPM to image and get pixel data
void			render_images(t_render *game);
void			render_enemy(t_render *game);
void			render_coin(t_render *game);
void			render_player(t_render *game);
void			render_wall(t_render *game);
void			render_sky(t_render *game);

// Allocate pxls accrding to images
void			put_images(t_render *game);
void			put_pxls(t_vertex *new_attr, int width, int height, \
				unsigned int attr);
unsigned int	get_attribute_data(t_vertex xpm, int x, int y);
void			put_pxl_sky(t_render *game, int width, int height);
void			put_pxl_wall(t_render *game, int width, int height);
void			put_pxl_player(t_render *game, int width, int height);
void			put_pxl_coin(t_render *game, int width, int height);
void			put_pxl_exit(t_render *game, int width, int height);
void			put_pxl_enemy(t_render *game, int width, int height);

// Loop the frame and loop images 
int				frame_loop(t_render *game);
// Player moves according t keycodes
int				key_press(int key, t_render *game);
int				find_player(t_render *game);
// Utils for ening the game and errors
void			close_game(t_render *game);
void			end_of_game(t_render *game, int result);
int				exit_game(char *message);
void			ft_perror(char *error, t_render *game);
void			ft_error(char *error);
// Enemy image rendering and movements
int				frame_update_enemy(t_render *game);
void			render_enemy(t_render *game);
int				find_enemy(t_render *game);
void			move_up_enemy(t_render *game);
void			move_down_enemy(t_render *game);
void			move_right_enemy(t_render *game);
void			move_left_enemy(t_render *game);

#endif
