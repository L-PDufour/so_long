# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldufour <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 11:01:10 by ldufour           #+#    #+#              #
#    Updated: 2023/10/30 14:45:16 by ldufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CFLAGS	:= -Wunreachable-code -Ofast -g 
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -L"/Users/$(USER)/.brew/opt/glfw/lib/"
SRCS	:= $(shell find ./src -iname "*.c")
MAPS	:= $(shell find ./maps -iname "*.ber")
OBJS	= ${SRCS:.c=.o}
LIBFT	= libft/libft.a
VALGRIND = valgrind
all: libmlx $(NAME)
	
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

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

test: all
	@for file in $(MAPS); do \
		echo "Testing $$file"; \
		./$(NAME) $$file; \
	done
vg: all
	@for file in $(MAPS); do \
		echo "Testing $$file"; \
		$(VALGRIND) ./$(NAME) $$file; \
	done
re:		fclean all

.PHONY: all, clean, fclean, re, libmlx
