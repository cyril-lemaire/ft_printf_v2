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
LIBFT_NAME :=	libft.a
PRINTF_NAME :=	libprintf.a
NAME :=			libftprintf.a

FLAGS := -Wall -Wextra -Werror

CC := gcc

SRC := ./
INCLUDES := ./

SRC :=	ft_printf_family.c			\
		ft_printf_family_2.c		\
		ft_print.c					\
		ft_format.c					\
		ft_write_format.c			\
		ft_tools_atoi.c				\
		ft_tools_imaxabs.c			\
		ft_tools_write_uimax.c		\
		ft_writers_int.c			\
		ft_writers_int_2.c			\
		ft_writers_str.c			\
		ft_writers_other.c			\
		t_printer.c					\
		t_vdprinter.c				\
		t_vdprinter_2.c				\

TEST_NAME :=	printf_tester
TEST_FILES :=	tester.c

OBJ := ${SRC:.c=.o}

.PHONY: all clean fclean re obj nobj ${LIBFT_FOLDER}/${LIBFT_NAME}

all: ${NAME}

%.o: ${SRC_FOLDER}/%.c
	${CC} -c -I${INCLUDES} ${FLAGS} -c -o $@ $<

${NAME}_alt: ${LIBFT_FOLDER}/${LIBFT_NAME} ${PRINTF_NAME}
	libtool --mode=link cc -static -o ${NAME} ${LIBFT_FOLDER}/${LIBFT_NAME} \
		${PRINTF_NAME}

${NAME}: ${LIBFT_FOLDER}/${LIBFT_NAME} ${PRINTF_NAME}
	rm -f ${NAME}
	ar -rcT ${NAME} ${LIBFT_FOLDER}/${LIBFT_NAME} ${PRINTF_NAME}

${PRINTF_NAME}: ${OBJ}
	@echo '@ar crs ${PRINTF_NAME} [OBJ FILES]'
	@ar rcs ${PRINTF_NAME} ${OBJ}

${LIBFT_FOLDER}/${LIBFT_NAME}:
	make -C ${LIBFT_FOLDER}

clean:
	@echo "@rm -f [OBJ FILES]"
	@rm -f ${OBJ}
	make -C ${LIBFT_FOLDER} clean

fclean: clean
	rm -f ${LIBFT_FOLDER}/${LIBFT_NAME} ${PRINTF_NAME} ${NAME}

re: fclean all

test: ${NAME}
	${CC} -I${INCLUDES} ${TEST_FILES} ${NAME} -o ${TEST_NAME} && ./${TEST_NAME} | less

obj: ${OBJ}

nobj: all clean
