NAME	= so_long
# CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

LIBS	= libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= main.c 
OBJS	= ${SRCS:.c=.o}
LIBFT	= libft/libft.a


$(NAME): $(OBJS)
		cd libft && make
		$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(LIBS) -o $(NAME)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)"
clean:	
		cd libft && make clean
		rm -f $(OBJ) $(OBJB)

fclean:	clean
		cd libft && make fclean
		rm -f $(NAME) $(NAMEB)

re:		fclean all

.PHONY: all, clean, fclean, re, libmlx
