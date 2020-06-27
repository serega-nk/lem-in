# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 20:00:06 by bconchit          #+#    #+#              #
#    Updated: 2020/06/27 04:33:18 by bconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= lem-in

INC_DIR		= ./includes
SRC_DIR		= ./srcs
OBJ_DIR		= ./objs

HEADERS		= deque.h gnl.h lem_in.h parse.h queue.h 
SOURCES		= \
	$(addprefix deque/, \
		deque_clean.c \
		deque_create.c \
		deque_destroy.c \
		deque_item_create.c \
		deque_item_destroy.c \
		deque_pop_back.c \
		deque_pop_front.c \
		deque_push_back.c \
		deque_push_front.c \
	) \
	$(addprefix gnl/, \
		gnl_create.c \
		gnl_destroy.c \
		gnl_readline.c \
	) \
	$(addprefix queue/, \
		queue_clean.c \
		queue_create.c \
		queue_destroy.c \
		queue_item_create.c \
		queue_item_destroy.c \
		queue_pop_front.c \
		queue_push_back.c \
	) \
	$(addprefix app/, \
		$(addprefix load/, \
			load_check.c \
			load_while.c \
		) \
		app_calc.c \
		app_error.c \
		app_free.c \
		app_load.c \
		app_play.c \
	) \
	main.c

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
	./$(NAME) < _maps/1

.PHONY: all clean fclean re norm
