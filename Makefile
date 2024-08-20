# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhehdir <mkhehdir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 19:04:58 by mkhehdir          #+#    #+#              #
#    Updated: 2024/08/20 21:02:53 by mkhehdir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -Iinclude -Isrc -O3
RM					=	rm -rf
CHECKER				=	checker
PUSH_SWAP			=	push_swap
NAME				=	$(PUSH_SWAP) $(CHECKER)

# Libraries
LIBFT_DIR			=	lib/libft
FT_PRINTF_DIR		=	lib/ft_printf

LIBFT				=	$(LIBFT_DIR)/libft.a
FT_PRINTF			=	$(FT_PRINTF_DIR)/ft_printf.a

CFLAGS				+=	-I $(LIBFT_DIR)/include -I $(FT_PRINTF_DIR)/include

MAKE_LIB			=	make --no-print-directory -C

# Source and Object Files
VPATH				=	src:src/stack:src/push_swap:src/checker_bonus:include
STACK_INC			=	stack.h
STACK_SRC			=	data_mngt.c stack_init.c stack_utils.c op_push.c \
						op_reverse_rotate.c op_rotate.c op_swap.c op_utils.c
PUSH_SWAP_INC		=	$(STACK_INC) push_swap.h
PUSH_SWAP_SRC		=	$(STACK_SRC) push_swap.c sort.c move.c chunk_sort.c  \
						chunk_split.c chunk_utils.c opti_easy_sort.c \
						opti_sort_asap.c opti_sort_three.c opti_to_the_top.c \
						opti_post_sort.c opti_post_sort_utils.c
CHECKER_INC			=	$(STACK_INC) checker_bonus.h
CHECKER_SRC			=	$(STACK_SRC) checker_bonus.c checker_utils_bonus.c

# Rules
all:				$(PUSH_SWAP)

bonus:				$(CHECKER)

obj:
					mkdir -p obj

PUSH_SWAP_OBJ		=	$(PUSH_SWAP_SRC:%.c=obj/push_swap/%.o)
CHECKER_OBJ			= 	$(CHECKER_SRC:%.c=obj/checker/%.o)

$(PUSH_SWAP_OBJ):	obj/push_swap/%.o: %.c $(PUSH_SWAP_INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(CHECKER_OBJ):		obj/checker/%.o: %.c $(CHECKER_INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
					$(MAKE_LIB) $(LIBFT_DIR)
$(FT_PRINTF):
					$(MAKE_LIB) $(FT_PRINTF_DIR)

$(PUSH_SWAP):		$(PUSH_SWAP_OBJ) $(LIBFT) $(FT_PRINTF)
					$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LIBFT) $(FT_PRINTF) -o $@

$(CHECKER):			$(CHECKER_OBJ) $(LIBFT) $(FT_PRINTF)
					$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LIBFT) $(FT_PRINTF) -o $@

lib_clean:
					$(MAKE_LIB) $(LIBFT_DIR) clean
					$(MAKE_LIB) $(FT_PRINTF_DIR) clean

lib_fclean:
					$(MAKE_LIB) $(LIBFT_DIR) fclean
					$(MAKE_LIB) $(FT_PRINTF_DIR) fclean

clean:				lib_clean
					$(RM) obj

fclean:				clean lib_fclean
					$(RM) $(NAME)

re:					fclean all

.SILENT:

.PHONY:				all bonus lib_clean lib_fclean clean fclean re
