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

LIBNAME =	ft

CC = 		gcc
CFLAGS =	-Wall -Wextra -Werror # -O3

SRC_DIR =		srcs
BIN_DIR =		bin
STATIC_DIR =	${BIN_DIR}/static
SHARED_DIR =	${BIN_DIR}/shared
INCL_DIR =		.

SRC_NAMES = atoi			\
			bzero			\
			isalnum			\
			isalpha			\
			isascii			\
			isdigit			\
			isprint			\
			memccpy			\
			memchr			\
			memcmp			\
			memcpy			\
			memmove			\
			memset			\
			strcat			\
			strchr			\
			strcmp			\
			strcpy			\
			strdup			\
			strlcat			\
			strlen			\
			strncat			\
			strncmp			\
			strncpy			\
			strnstr			\
			strrchr			\
			strstr			\
			tolower			\
			toupper			\
			memalloc		\
			memdel			\
			strnew			\
			strdel			\
			strclr			\
			striter			\
			striteri		\
			strmap			\
			strmapi			\
			strequ			\
			strnequ			\
			strsub			\
			strjoin			\
			strtrim			\
			itoa			\
			strsplit		\
			putchar			\
			putstr			\
			putendl			\
			putnbr			\
			putchar_fd		\
			putstr_fd		\
			putendl_fd		\
			putnbr_fd		\
			lstnew			\
			lstnew_nocp		\
			lstdelone		\
			lstdel			\
			lstadd			\
			lstiter			\
			lstmap			\
			isspace			\
			mod				\
			abs				\
			lstcpy			\
			lstappend		\
			lstdelnext		\
			lstgetindex		\
			lstdelindex		\
			min				\
			max				\
			realloc			\
			stracat			\
			stradd			\
			wcslen			\
			wctomb			\

SRC = ${SRC_NAMES:%=${SRC_DIR}/ft_%.c}
STATIC_OBJ = ${SRC_NAMES:%=${STATIC_DIR}/ft_%.o}
SHARED_OBJ = ${SRC_NAMES:%=${SHARED_DIR}/ft_%.o}

# OBJ = ${SRC:.c=.o}

all: lib${LIBNAME}.a

${STATIC_DIR}:
	mkdir -p $@

${SHARED_DIR}:
	mkdir -p $@

${STATIC_DIR}/%.o: ${SRC_DIR}/%.c
	${CC} -c ${CFLAGS} -I${INCL_DIR} -o $@ $<

${SHARED_DIR}/%.o: ${SRC_DIR}/%.c
	${CC} -c -fPIC ${CFLAGS} -I${INCL_DIR} -o $@ $<

a: lib${LIBNAME}.a

so: lib${LIBNAME}.so

lib${LIBNAME}.a: ${STATIC_DIR} ${STATIC_OBJ}
	ar rcs $@ ${?:$<=}

lib${LIBNAME}.so: ${SHARED_DIR} ${SHARED_OBJ}
	${CC} -shared ${CFLAGS} -o lib${LIBNAME}.so ${?:$<=}

clean:
	@echo "@rm -f [STATIC OBJ]"
	@rm -f ${STATIC_OBJ}
	@echo "@rm -f [SHARED OBJ]"
	@rm -f ${SHARED_OBJ}

fclean: clean
	rm -f lib${LIBNAME}.a lib${LIBNAME}.so

re: fclean all

.PHONY: all a so clean fclean reclean re obj nobj
