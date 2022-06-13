# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 13:37:32 by esmirnov          #+#    #+#              #
#    Updated: 2022/06/08 11:13:42 by esmirnov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

SRCS		=	$(addprefix src/,\
				main.c\
				pipex.c\
				ft_init_data.c\
				ft_msg.c\
				ft_path_tab.c\
				ft_free_close.c\
				command_path.c\
				ft_split_pipex.c)

OBJS		=	$(SRCS:src/%.c=objects/%.o)

DEP			=	$(SRCS:src/%.c=objects/%.d)

CFLAGS		=	-Wall -Werror -Wextra -MMD -g3 -O3

CC			=	gcc

INC			=	-Iinclude -Ilibft

LIBFT		=	libft/libft.a

RM			=	rm -rf

# -p if directory exists very is no warning etc
objects/%.o:	src/%.c
	mkdir -p objects
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(INC) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	@make -C libft/
	
#delete .o files
clean: libft_clean
	$(RM) $(DEP) $(OBJS) objects

libft_clean:
	make clean -C libft/
	
fclean:	clean
	$(RM) $(NAME)

# delete all and recompile all
re:	fclean
	make all

-include $(DEP)

.PHONY:	all clean libft_clean fclean re
