##
## Makefile for m in /home/simomb_s/MyGithub/Malloc
##
## Made by stephanedarcy simomba
## Login   <simomb_s@epitech.net>
##
## Started on  Thu Apr 14 12:59:23 2016 stephanedarcy simomba
## Last update Thu Apr 14 12:59:24 2016 stephanedarcy simomba
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
