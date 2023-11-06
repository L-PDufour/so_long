# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldufour <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 11:01:10 by ldufour           #+#    #+#              #
#    Updated: 2023/11/06 12:29:34 by ldufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
NAME_B = so_long_bonus
CFLAGS	:= -Wunreachable-code -Ofast -g 
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

SRCS_B	:= src/errors.c \
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
	   maps/invalid_name.bre \
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
OBJS_B	= ${SRCS_B:.c=.o}
LIBFT	= libft/libft.a
VALGRIND = valgrind
all: libmlx $(NAME)
bonus: libmlx $(NAME_B)
	
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS)
		cd libft && make
		$(CC) $(OBJS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)
$(NAME_B): $(OBJS_B)
		cd libft && make
		$(CC) $(OBJS_B) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME_B)
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
