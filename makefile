NAME	:= Game
# CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

LIBS	:= libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= main.c 
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
