# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 08:48:15 by jlima             #+#    #+#              #
#    Updated: 2022/07/26 12:00:15 by jlima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

NAME 		= philo

INCLUDES	= -I includes

THREAD		= -pthread

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MAKE		= make

DIR_SRCS	= srcs/
DIR_OBJS	= objs/

SRCS_FILES	= main actions utils args

OBJS		= $(addprefix $(DIR_OBJS), $(addsuffix .o, $(SRCS_FILES)))

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
			@echo "$(MAGENTA)$(BOLD)Executable created!$(RESET)"

$(DIR_OBJS)%.o :	$(DIR_SRCS)%.c
			@mkdir -p $(DIR_OBJS)
			@$(CC) $(CFLAGS) $(INCLUDES) $(THREAD) -c  $< -o $@ 

clean:
			rm -rf $(DIR_OBJS)

fclean:		clean
			rm -f $(NAME)	

re:			fclean all

.PHONY: 	all clean fclean re
