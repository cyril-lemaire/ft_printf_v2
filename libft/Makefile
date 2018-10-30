#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clemaire <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 16:35:50 by clemaire          #+#    #+#              #
#    Updated: 2017/12/01 13:59:18 by clemaire         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIBNAME = ft

SRC = ft_atoi.c			\
	ft_bzero.c			\
	ft_isalnum.c		\
	ft_isalpha.c		\
	ft_isascii.c		\
	ft_isdigit.c		\
	ft_isprint.c		\
	ft_memccpy.c		\
	ft_memchr.c			\
	ft_memcmp.c			\
	ft_memcpy.c			\
	ft_memmove.c		\
	ft_memset.c			\
	ft_strcat.c			\
	ft_strchr.c			\
	ft_strcmp.c			\
	ft_strcpy.c			\
	ft_strdup.c			\
	ft_strlcat.c		\
	ft_strlen.c			\
	ft_strncat.c		\
	ft_strncmp.c		\
	ft_strncpy.c		\
	ft_strnstr.c		\
	ft_strrchr.c		\
	ft_strstr.c			\
	ft_tolower.c		\
	ft_toupper.c		\
	ft_memalloc.c		\
	ft_memdel.c			\
	ft_strnew.c			\
	ft_strdel.c			\
	ft_strclr.c			\
	ft_striter.c		\
	ft_striteri.c		\
	ft_strmap.c			\
	ft_strmapi.c		\
	ft_strequ.c			\
	ft_strnequ.c		\
	ft_strsub.c			\
	ft_strjoin.c		\
	ft_strtrim.c		\
	ft_itoa.c			\
	ft_strsplit.c		\
	ft_putchar.c		\
	ft_putstr.c			\
	ft_putendl.c		\
	ft_putnbr.c			\
	ft_putchar_fd.c		\
	ft_putstr_fd.c		\
	ft_putendl_fd.c		\
	ft_putnbr_fd.c		\
	ft_lstnew.c			\
	ft_lstnew_nocp.c	\
	ft_lstdelone.c		\
	ft_lstdel.c			\
	ft_lstadd.c			\
	ft_lstiter.c		\
	ft_lstmap.c			\
	ft_isspace.c		\
	ft_mod.c			\
	ft_abs.c			\
	ft_lstcpy.c			\
	ft_lstappend.c		\
	ft_lstdelnext.c		\
	ft_lstgetindex.c	\
	ft_lstdelindex.c	\
	ft_min.c			\
	ft_max.c			\
	ft_realloc.c		\
	ft_stracat.c		\
	ft_stradd.c			\
	ft_wcslen.c			\

OBJ = ${SRC:.c=.o}

SRC_FOLDER = .

CFLAGS = -Wall -Wextra -Werror # -O3

.PHONY: all a so clean fclean reclean re obj nobj soflags

all: lib${LIBNAME}.a

obj: ${OBJ}

%.o: %.c
	gcc -c -fPIC ${CFLAGS} -I${SRC_FOLDER} -o $@ $<

a: lib${LIBNAME}.a

so: lib${LIBNAME}.so

lib${LIBNAME}.a: ${OBJ}
	@echo '@ar rcs lib${LIBNAME}.a [OBJ FILES]'
	@ar rcs lib${LIBNAME}.a ${OBJ}

lib${LIBNAME}.so: ${OBJ}
	@echo '@gcc -shared -o lib${LIBNAME}.so [OBJ FILES]'
	@gcc -shared ${CFLAGS} -o lib${LIBNAME}.so ${OBJ}

clean:
	@echo "@rm -f [OBJ FILES]"
	@rm -f ${OBJ}

fclean: clean
	rm -f lib${LIBNAME}.a lib${LIBNAME}.so

reclean:
	@echo "@rm -f [OBJ FILES]"
	@rm -f ${OBJ}

re: fclean all
