NAME	= so_long
# CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast 

LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -L"/Users/$(USER)/.brew/opt/glfw/lib/"
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	= ${SRCS:.c=.o}
LIBFT	= libft/libft.a

all: libmlx $(NAME)
	
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
		cd libft && make
		$(CC) $(OBJS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)

clean:	
		@cd libft && make clean
		@rm -rf $(OBJS)
		@rm -rf $(LIBMLX)/build 

fclean:	clean
		@cd libft && make fclean
		rm -f $(NAME) 

re:		fclean all

.PHONY: all, clean, fclean, re, libmlx
