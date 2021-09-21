# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 19:44:39 by pantigon          #+#    #+#              #
#    Updated: 2021/09/21 20:54:25 by pantigon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

FLAG = -Wall -Wextra -Werror

SRCS_C = srcs/client.c

SRCS_S = srcs/server.c

# SRCS = $(SRCS_C), $(SRCS_S)

LIB = srcs/libft

O_DIR = obj

OBJ_C = $(addprefix $(O_DIR)/,$(SRCS_C:.c=.o))

OBJ_S = $(addprefix $(O_DIR)/,$(SRCS_S:.c=.o))

all: $(NAME)

$(NAME): $(O_DIR) $(OBJ_S) $(OBJ_C)
	@make -C $(LIB)
	gcc $< -o 

$(O_DIR): 
	mkdir -p obj

$(O_DIR)/%.o: %.c 
	gcc $(FLAG) $(HEAD) -o $@ -c $< 

# HEAD = -I.

# OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):  
	@make -C $(LIB)
	gcc $(FLAG) -o client

clean:
	rm -f $(OBJ)
	rm -rf $(O_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re