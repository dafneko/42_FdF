# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 01:06:15 by dkoca             #+#    #+#              #
#    Updated: 2024/03/19 00:15:09 by dkoca            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

SRCDIR := src
_SRC := fdf.c hooks.c map.c bresenham.c free.c draw.c transform.c errors.c menu.c camera.c mousehook.c parse.c
SRC := $(addprefix $(SRCDIR)/, $(_SRC))

OBJDIR := obj
_OBJ := $(_SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR)/, $(_OBJ))

LIBMLXDIR := minilibx-linux
LIBMLX := $(LIBMLXDIR)/libmlx_Linux.a 

LIBFTDIR := libft
LIBFT := $(LIBFTDIR)/libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror -g -I$(SRCDIR) -I$(LIBFTDIR) -I$(LIBMLXDIR)
LDFLAGS :=  -L$(LIBFTDIR) -lft -L$(LIBMLXDIR) -lmlx
LDLIBS := -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm
RM := /bin/rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIBFT):
	@make -C $(LIBFTDIR)

$(LIBMLX):
	$(MAKE) -C $(LIBMLXDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJ)
	$(RM) -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(LIBMLXDIR) clean
	

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY:
	all clean fclean re