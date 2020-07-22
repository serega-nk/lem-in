# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 20:00:06 by bconchit          #+#    #+#              #
#    Updated: 2020/07/22 00:25:40 by bconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= lem-in

INC_DIR		= ./includes
SRC_DIR		= ./srcs
OBJ_DIR		= ./objs

HEADERS		= lem_in.h
SOURCES		= \
	$(addprefix app/, \
		$(addprefix calc/, \
			calc_disjoint.c \
			calc_option.c \
			calc_populate.c \
			calc_shortest.c \
		) \
		$(addprefix load/, \
			load_check.c \
			load_comment.c \
			load_link.c \
			load_number.c \
			load_room.c \
			load_signal.c \
			load_while.c \
		) \
		app_calc.c \
		app_error.c \
		app_free.c \
		app_load.c \
		app_output.c \
	) \
	$(addprefix classes/, \
		$(addprefix ant/, \
			ant_create.c \
			ant_destroy.c \
			ant_finish.c \
			ant_move.c \
			ant_print.c \
		) \
		$(addprefix link/, \
			link_create.c \
			link_destroy.c \
		) \
		$(addprefix option/, \
			option_create.c \
			option_destroy.c \
		) \
		$(addprefix room/, \
			room_create.c \
			room_destroy.c \
			room_lock.c \
			room_reset.c \
			room_unlock.c \
		) \
	) \
	main.c \

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= gcc
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
	./$(NAME) < 3.txt | grep "#"

vv: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) < 1.txt

.PHONY: all clean fclean re norm test vv
