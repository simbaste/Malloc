##
## Makefile for makefile in /home/khenki_n/Rendu/PSU_2015_malloc/tmp
##
## Made by khenki_n
## Login   <khenki_n@epitech.net>
##
## Started on Mon Feb  1 18:38:14 2016 khenki_n
## Last update Wed Feb 10 21:03:22 2016 stephanedarcy simomba
##

CC	= gcc -g3

NAME	= libmy_malloc.so

CFLAGS	= -Wall -Werror -Wextra
CFLAGS	+= --shared -fPIC

SRCS	= malloc.c \
	func_list.c \
	tree_free.c \
	show_alloc_mem.c \
	function.c \
	hashage.c \
	alloc_mem.c \
	mutex.c \
	search_tree.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

all	: $(NAME)

$(NAME)	:
	$(CC) -o $(NAME) $(CFLAGS) $(SRCS)

clean	:
	$(RM) $(OBJS)

fclean	:
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all fclean re
