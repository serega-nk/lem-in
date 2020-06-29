# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 20:00:06 by bconchit          #+#    #+#              #
#    Updated: 2020/06/29 03:27:10 by bconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= lem-in

INC_DIR		= ./includes
SRC_DIR		= ./srcs
OBJ_DIR		= ./objs

HEADERS		= lem_in.h hashtab.h
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
		app_calc.c \
		app_error.c \
		app_free.c \
		app_load.c \
		app_play.c \
	) \
	$(addprefix hashtab/, \
		hashtab_clean.c \
		hashtab_create.c \
		hashtab_destroy.c \
		hashtab_get.c \
		hashtab_hash.c \
		hashtab_insert.c \
		hashtab_item_create.c \
		hashtab_item_destroy.c \
		hashtab_remove.c \
		hashtab_resize.c \
	) \
	home.c \
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

.PHONY: all clean fclean re norm
