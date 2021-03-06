
NAME = server

FLAG = -Wall -Wextra -Werror

SRCS_C = client.c

SRCS_S = server.c

SRCS = srcs/$(SRCS_C) srcs/$(SRCS_S)

LIB = srcs/libft/

HEAD = -I./$(LIB) -I./include/

O_DIR = obj

OBJ_C = $(addprefix $(O_DIR)/,$(SRCS_C:.c=.o))

OBJ_S = $(addprefix $(O_DIR)/,$(SRCS_S:.c=.o))

all: lib $(O_DIR) $(NAME) client

$(O_DIR):
	@mkdir -p obj

lib: 
	@make -C $(LIB)

$(NAME): $(OBJ_S)
	@gcc $<  $(HEAD) -o $@ $(LIB)libft.a
	@echo "SERVER compiled"

client: $(OBJ_C)
	@gcc $< $(HEAD) -o $@ $(LIB)libft.a
	@echo "CLIENT compiled"

$(O_DIR)/%.o: srcs/%.c
	@gcc $(FLAG) $(HEAD) -o $@ -c $< 

norm:
	norminette srcs/. include/.

clean:
	@make -C $(LIB) clean
	@rm -rf $(O_DIR)
	@rm -f $(OBJ_C) $(OBJ_S)

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(NAME) client

re: fclean all

.PHONY:  all clean fclean norm re