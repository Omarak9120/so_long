#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include <string.h>

# define WALL "./pictures/wall.xpm"
# define EMPTY "./pictures/empty.xpm"
# define PLAYER "./pictures/player.xpm"
# define EXIT "./pictures/exit.xpm"
# define COLLECT "./pictures/collect.xpm"
# define TILE_SIZE 50
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_map
{
	int	**tab;
	int	collector;
	int	size_x;
	int	exit_count;
	int	size_y;
	int	player_pos[2];
	int	walls;
	int	error;
	int	exit_pos[2];
	int	map_size;
	int	**visited;
	int	steps;
	int	player_count;
}	t_map;

typedef struct s_data
{
	void	*ptr;
	void	*win;
	void	*player_img;
	void	*exit_img;
	void	*collect_img;
	void	*wall_img;
	void	*empty_img;
	t_map	*map;
	int		flag;
}	t_data;

void	exit_error(t_map *map, char *msg);
void	malloc_tab_visited(t_map *map);
void	read_map(const char *filename, t_map *map);
int		is_valid_c(char c);
int		check_map_size(t_map *map);
int		check_map_collector(t_map *map);
int		check_map_walls_out(t_map *map);
void	floodfill(t_map *map, int x, int y);
int		check_valid_path(t_map *map);
int		check_map_validation(t_map *map);
void	get_map_size(t_map *map, const char *filename);
int		ft_strcmp(char *s1, char *s2);
int		fstrlen(const char *s);
int		check_map_file(char **av, t_map *map);
void	initialize_map(t_map *map);
void	keypress(int keycode, t_data *data, int *new_x, int *new_y);
int		handle_keypress(int keycode, t_data *data);
void	cleanup_and_exit(t_data *data);
void	parse_map(t_data *data);
void	parse_tile(t_data *data, void *img, int x, int y);
int		create_window(t_data *data);
int		main(int ac, char **av);
void	redraw_map(t_data *data);
void	initialize_and_check_map(char **av, t_map *map, t_data *data);
void	load_images(t_data *data, int *img_width, int *img_height);
void	cleanup_images(t_data *data);
void	read_helper(t_map *map, char *c, int *i, int *j);
void	read_helper_extra(t_map *map, char *c, int *i, int *j);
void	handle_error(t_map *map, int fd, int i);
void	loop_read(t_map *map, char *line, int i, int j);
void	free_map(t_map *map);
int		on_destroy(t_data *data);

#endif
