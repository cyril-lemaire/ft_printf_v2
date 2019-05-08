#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clemaire <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/23 15:35:06 by clemaire          #+#    #+#              #
#    Updated: 2017/12/23 15:37:00 by clemaire         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIBFT_FOLDER :=	libft
NAME :=			libftprintf.a

FLAGS := -Wall -Wextra -Werror

CC := gcc

SRC := ./
INCLUDES := ./

SRC :=	ft_printf_family.c			\
		ft_printf_family_2.c		\
		ft_print.c					\
		ft_convert.c				\
		ft_write_conversion.c		\
		ft_tools_atoi.c				\
		ft_tools_imaxabs.c			\
		ft_tools_write_uimax.c		\
		ft_tools_write_str.c		\
		ft_writers_int.c			\
		ft_writers_int_2.c			\
		ft_writers_str.c			\
		ft_writers_other.c			\
		t_printer.c					\
		t_vdprinter.c				\
		t_vdprinter_2.c				\
		t_vasprinter.c				\
		t_vasprinter_2.c			\

LIBFT_SRC :=	ft_atoi.c	\
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
		ft_strnlen.c		\
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
		ft_wctomb.c			\
		ft_wclen.c			\

SRC += ${foreach src,${LIBFT_SRC},${LIBFT_FOLDER}/${src}}
TEST_NAME :=	printf_tester
TEST_FILES :=	tester.c

OBJ := ${SRC:.c=.o}

.PHONY: all clean fclean re obj nobj ${LIBFT_FOLDER}/${LIBFT_NAME}

all: ${NAME}

%.o: ${SRC_FOLDER}/%.c
	${CC} -c -I${INCLUDES} ${FLAGS} -o $@ $<

${NAME}_alt: ${LIBFT_FOLDER}/${LIBFT_NAME} ${PRINTF_NAME}
	libtool --mode=link cc -static -o ${NAME} ${LIBFT_FOLDER}/${LIBFT_NAME} \
		${PRINTF_NAME}

${NAME}_alt2: ${LIBFT_FOLDER}/${LIBFT_NAME} ${PRINTF_NAME}
	rm -f ${NAME}
	ar -rcT $@ $^

${NAME}: ${OBJ}
	@echo '@ar rcs ${PRINTF_NAME} [OBJ FILES]'
	@ar rcs $@ $^

${PRINTF_NAME}: ${OBJ}
	@echo '@ar rcs ${PRINTF_NAME} [OBJ FILES]'
	@ar rcs ${PRINTF_NAME} $^

${LIBFT_FOLDER}/${LIBFT_NAME}:
	make -C ${LIBFT_FOLDER}

clean:
	@echo "@rm -f [OBJ FILES]"
	@rm -f ${OBJ}
	make -C ${LIBFT_FOLDER} clean

fclean: clean
	rm -f ${NAME}

re: fclean all

test: ${NAME}
	${CC} -I${INCLUDES} ${TEST_FILES} ${NAME} -o ${TEST_NAME} && ./${TEST_NAME} | less

obj: ${OBJ}

nobj: all clean
