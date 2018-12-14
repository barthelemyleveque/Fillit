# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 16:40:26 by thzimmer          #+#    #+#              #
#    Updated: 2018/12/09 16:25:00 by thzimmer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re 

NAME = fillit

SRC_NAME = checkfile.c solver.c main.c \

SRCS_PATH = srcs/
OBJS_PATH = objs/
OBJ_NAME = $(SRC_NAME:.c=.o)
SRCS = $(addprefix $(SRCS_PATH),$(SRC_NAME))
OBJS = $(addprefix $(OBJS_PATH),$(OBJ_NAME))

CC = clang
CFLAGS = -Wall -Wextra -Werror
I_FLAG = -Iincludes
LIB_PATH = -Llibft
LIB_NAME = -lft

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(I_FLAG) -o $@ -c $<

all : $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(LIB_PATH) $(LIB_NAME) $^ -o $@

clean :
	@/bin/rm -f $(OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true
	@make clean -C libft

fclean : clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft

re : fclean all
