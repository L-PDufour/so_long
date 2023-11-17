# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldufour <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 11:01:10 by ldufour           #+#    #+#              #
#    Updated: 2023/11/17 07:55:26 by ldufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CFLAGS	:= -Wall -Wextra -Werror -Wunreachable-code -Ofast 
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -L"/Users/$(USER)/.brew/opt/glfw/lib/"
SRCS	:= src/errors.c \
	   src/flood_fill.c \
	   src/images.c \
	   src/main.c \
	   src/map_display.c \
	   src/map_parsing.c \
	   src/maps.c \
	   src/textures.c 

MAPS	:= maps/.bigmap.ber \
	   maps/empty.ber \
	   maps/invalid_char.ber \
	   maps/invalid_char2.ber \
	   maps/invalid_name..ber \
	   maps/invalid_path.ber \
	   maps/invalid_path2.ber \
	   maps/invalid_path3.ber \
	   maps/invalid_wall.ber \
	   maps/invalid_wall2.ber \
	   maps/invalid_wall_rectangle.ber \
	   maps/invalid_wall_rectangle2.ber \
	   maps/valid.ber \
	   maps/valid2.ber 
	
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
