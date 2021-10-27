# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elman <elman@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 10:09:36 by elman             #+#    #+#              #
#    Updated: 2021/10/27 11:13:21 by elman            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server

NAME2 = client

SRC1 = server.c utils.c

SRC2 = client.c utils.c

FLAGS = -Wall -Wextra -Werror

all: ${NAME1} ${NAME2}

${NAME1}:	
			@gcc ${FLAGS} ${SRC1} -o ${NAME1}

${NAME2}:	
			@gcc ${FLAGS} ${SRC2} -o ${NAME2}

clean:
		
fclean:		clean
			@rm -rf ${NAME1} ${NAME2}

norme:
			@norminette *.c
			@norminette *.h
re:		fclean all

.PHONY: all clean fclean norm re

