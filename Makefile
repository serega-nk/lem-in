# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 20:00:06 by bconchit          #+#    #+#              #
#    Updated: 2020/06/29 18:34:22 by bconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= lem-in

INC_DIR		= ./includes
SRC_DIR		= ./srcs
OBJ_DIR		= ./objs

HEADERS		= heap.h lem_in.h
SOURCES		= \
	$(addprefix app/, \
		$(addprefix load/, \
			load_check.c \
			load_comment.c \
			load_link.c \
			load_number.c \
			load_room.c \
			load_signal.c \
			load_while.c \
		) \
		$(addprefix room/, \
			room_create.c \
			room_destroy.c \
		) \
		app_calc.c \
		app_error.c \
		app_free.c \
		app_load.c \
		app_play.c \
	) \
	$(addprefix heap/, \
		heap_create.c \
		heap_destroy.c \
		heap_resize.c \
		heap_sift_down.c \
		heap_sift_up.c \
	) \
	main.c \

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= gcc -g
WFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -I$(INC_DIR)/ -I$(LIBFT_DIR)/includes/
LFLAGS		= -L$(LIBFT_DIR)/ -lft

INCS		= $(addprefix $(INC_DIR)/, $(HEADERS))
SRCS		= $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(WFLAGS) $(IFLAGS) $(OBJS) $(LFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) Makefile
	@mkdir -p ${@D}
	$(CC) $(WFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME).dSYM
	rm -rf $(NAME)

re: fclean all

norm:
	@norminette $(INCS) $(SRCS)

test: $(NAME)
	./$(NAME) < _maps/1

vv: $(NAME)
	valgrind --leak-check=full ./$(NAME) < _maps/big-superposition

.PHONY: all clean fclean re norm test vv
