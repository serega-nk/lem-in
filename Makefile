# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 20:00:06 by bconchit          #+#    #+#              #
#    Updated: 2020/07/18 23:06:00 by bconchit         ###   ########.fr        #
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
			calc_bellman_ford.c \
			calc_excess.c \
			calc_populate.c \
			calc_prepare.c \
			calc_suurballe.c \
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
		$(addprefix room/, \
			room_create.c \
			room_destroy.c \
			room_lock.c \
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
	./$(NAME) < _maps/map20k-m

test2: $(NAME)
	cd ../42_lem-in_tools-master/
	pwd
	./comparator.sh 10 big ../lem-in/lem-in

vv: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) < _maps/big-superposition

.PHONY: all clean fclean re norm test test2 vv
