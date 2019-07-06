#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clemaire <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/23 15:35:06 by clemaire          #+#    #+#              #
#    Updated: 2017/12/23 5:37:00 by clemaire         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME :=			libftprintf.a

LIBFT_DIR :=		libft
LIBFT_NAME :=		libft.a
LIBFT_INCL_DIR :=	includes
LIBFT_SRC_DIR :=	srcs
LIBFT_OBJ_DIR :=	bin/static

CC :=			gcc
CFLAGS :=		-Wall -Wextra -Werror

SRC_DIR :=		srcs
OBJ_DIR :=		bin
INCL_DIR :=		includes

SRC_NAMES :=	ft_printf_family		\
				ft_convert				\
				ft_write_conversion		\
				ft_printf_family_2		\
				ft_print				\
				ft_format				\
				ft_write_format			\
				ft_tools_atoi			\
				ft_tools_imaxabs		\
				ft_tools_write_uimax	\
				ft_writers_int			\
				ft_writers_int_2		\
				ft_writers_str			\
				ft_writers_other		\
				t_printer				\
				t_vdprinter				\
				t_vdprinter_2			\

LIBFT_SRC_NAMES :=	ft_atoi				\
					ft_bzero			\
					ft_isalnum			\
					ft_isalpha			\
					ft_isascii			\
					ft_isdigit			\
					ft_isprint			\
					ft_memccpy			\
					ft_memchr			\
					ft_memcmp			\
					ft_memcpy			\
					ft_memmove			\
					ft_memset			\
					ft_strcat			\
					ft_strchr			\
					ft_strcmp			\
					ft_strcpy			\
					ft_strdup			\
					ft_strlcat			\
					ft_strlen			\
					ft_strncat			\
					ft_strncmp			\
					ft_strncpy			\
					ft_strnstr			\
					ft_strrchr			\
					ft_strstr			\
					ft_tolower			\
					ft_toupper			\
					ft_memalloc			\
					ft_memdel			\
					ft_strnew			\
					ft_strdel			\
					ft_strclr			\
					ft_striter			\
					ft_striteri			\
					ft_strmap			\
					ft_strmapi			\
					ft_strequ			\
					ft_strnequ			\
					ft_strsub			\
					ft_strjoin			\
					ft_strtrim			\
					ft_itoa				\
					ft_strsplit			\
					ft_putchar			\
					ft_putstr			\
					ft_putendl			\
					ft_putnbr			\
					ft_putchar_fd		\
					ft_putstr_fd		\
					ft_putendl_fd		\
					ft_putnbr_fd		\
					ft_lstnew			\
					ft_lstnew_nocp		\
					ft_lstdelone		\
					ft_lstdel			\
					ft_lstadd			\
					ft_lstiter			\
					ft_lstmap			\
					ft_isspace			\
					ft_mod				\
					ft_abs				\
					ft_lstcpy			\
					ft_lstappend		\
					ft_lstdelnext		\
					ft_lstgetindex		\
					ft_lstdelindex		\
					ft_min				\
					ft_max				\
					ft_realloc			\
					ft_stracat			\
					ft_stradd			\
					ft_wcslen			\
					ft_wctomb			\

SRC :=	${SRC_NAMES:%=${SRC_DIR}/%.c}	\
		${LIBFT_SRC:%=${LIBFT_DIR}/%.c}

OBJ :=	${SRC_NAMES:%=${OBJ_DIR}/%.o}	\
		${LIBFT_SRC:%=${LIBFT_DIR}/${LIBFT_OBJ_DIR}/%.o}

TEST_NAME :=	printf_tester
TEST_FILES :=	tester.c

all: ${NAME}

${LIBFT_DIR}/${LIBFT_OBJ_DIR}/%.o: ${LIBFT_DIR}/${LIBFT_SRC_DIR}/%.c
	make -C ${LIBFT_DIR} ${LIBFT_OBJ_DIR}/%.o

${OBJ_DIR}:
	mkdir -p $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	${CC} ${CFLAGS} -I${INCL_DIR} -c -o $@ $<

${NAME}: ${OBJ_DIR} ${OBJ}
	ar rcs $@ ${?:$<=}

${NAME}_alt: ${LIBFT_DIR}/${LIBFT_NAME} ${PRINTF_NAME}
	libtool --mode=link cc -static -o $@ $^

${NAME}_alt2: ${LIBFT_DIR}/${LIBFT_NAME} ${PRINTF_NAME}
	ar -rcT $@ $^

${PRINTF_NAME}: ${OBJ_DIR} ${OBJ}
	ar rcs $@ ${?:$<=}

${LIBFT_DIR}/${LIBFT_NAME}:
	make -C ${LIBFT_DIR} ${LIBFT_NAME}

clean:
	@echo "@rm -f [OBJ FILES]"
	@rm -f ${OBJ}
	make -C ${LIBFT_DIR} clean

fclean: clean
	make -C ${LIBFT_DIR} fclean
	rm -f ${NAME}

re: fclean all

test: ${TEST_NAME}

${TEST_NAME}: ${NAME} ${TEST_FILES}
	${CC} -I${INCL_DIR} -o $@ $^ && ./$@ | less

obj: ${OBJ}

.PHONY: all clean fclean re obj test
