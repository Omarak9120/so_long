CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Ilibft -Iminilibx-linux -Iprintf
LDFLAGS = -Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11 -Llibft -lft

SRC = map_validation.c utils.c check_map_path.c get_next_line.c get_next_line_utils.c initialize_map.c read_map.c main.c playermove.c create_map.c read_help.c printf/ft_printf.c printf/ft_printf_d.c printf/ft_printf_p.c printf/ft_printf_u.c printf/ft_printf_x.c printf/ft_printf_c.c printf/ft_printf_s.c
OBJ = $(SRC:.c=.o)
TARGET = so_long

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a

all: $(TARGET)

$(TARGET): $(OBJ) $(LIBFT_LIB) $(MINILIBX_LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(MINILIBX_LIB):
	make -C $(MINILIBX_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(TARGET)
	make -C $(LIBFT_DIR) fclean
	make -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
