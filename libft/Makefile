# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 01:21:24 by bconchit          #+#    #+#              #
#    Updated: 2020/06/26 07:05:30 by bconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

INC_DIR		= ./includes
SRC_DIR		= ./srcs
OBJ_DIR		= ./objs

HEADERS		= libft.h \
			  ft_printf.h \
			  ft_printf_private.h \
			  ft_xexit.h \
			  ft_xexit_private.h \

SOURCES		= \
	$(addprefix part1/, \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
	) \
	$(addprefix part2/, \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
	) \
	$(addprefix bonus/, \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
	) \
	$(addprefix extra/, \
		ft_isspace.c \
		ft_memdup.c \
		ft_strnlen.c \
		ft_strndup.c \
		ft_lstlen.c \
		ft_lstrev.c \
		ft_index.c \
		ft_max.c \
		ft_min.c \
		ft_swap.c \
		ft_quicksort.c \
	) \
	$(addprefix ft_printf/, \
		ft_printf_fd.c \
		ft_printf.c \
		ft_sprintf.c \
		ft_printf_strnew.c \
		\
		$(addprefix output/, \
			ft_pf_output_flush.c \
			ft_pf_output_putchar.c \
			ft_pf_output_putnstr.c \
			ft_pf_output_putstr.c \
			ft_pf_output_repeat.c \
		) \
		$(addprefix parse/, \
			ft_pf_parse_color.c \
			ft_pf_parse_flags.c	\
			ft_pf_parse_format.c \
			ft_pf_parse_length.c \
			ft_pf_parse_next.c \
			ft_pf_parse_number.c \
			ft_pf_parse_precision.c \
			ft_pf_parse_print.c \
			ft_pf_parse_type.c \
			ft_pf_parse_while.c \
			ft_pf_parse_width.c \
		) \
		$(addprefix print/, \
			ft_pf_print_binary.c \
			ft_pf_print_char.c \
			ft_pf_print_date.c \
			ft_pf_print_double.c \
			ft_pf_print_escape.c \
			ft_pf_print_hex.c \
			ft_pf_print_octal.c \
			ft_pf_print_signed.c \
			ft_pf_print_string.c \
			ft_pf_print_unsigned.c \
		) \
	) \
	$(addprefix ft_xexit/, \
		ft_on_xexit.c \
		ft_xcheck.c \
		ft_xexit_global.c \
		ft_xexit.c \
		ft_xmalloc.c \
		ft_xmemalloc.c \
		ft_xstrdup.c \
	) \


CC			= gcc
WFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -I$(INC_DIR)

INCS		= $(addprefix $(INC_DIR)/, $(HEADERS))
SRCS		= $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) Makefile
	@mkdir -p ${@D}
	$(CC) $(WFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norm:
	@norminette $(INCS) $(SRCS)

test: test.c all
	$(CC) $(IFLAGS) $< libft.a -o $@

.PHONY: all clean fclean re
