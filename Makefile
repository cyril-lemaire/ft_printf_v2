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

SRC_FOLDER := .

SRC :=	ft_printf_family.c			\
		ft_vdprintf.c				\
		ft_vasprintf.c				\
		ft_print.c					\
		ft_tools_format.c			\
		ft_tools_write_format.c		\
		ft_tools_atoi.c				\
		ft_tools_imaxabs.c			\
		ft_tools_write_uimax.c		\
		ft_tools_write_types_1.c	\
		ft_tools_write_types_2.c	\
		ft_tools_write_types_3.c	\
		ft_tools_write_types_4.c	\
		t_printer.c					\
		t_vdprinter.c				\
		t_vasprinter.c				\
		t_vasprinter_mem.c			\

TEST_NAME :=	printf_tester
TEST_FILES :=	tester.c

OBJ := ${SRC:.c=.o}

.PHONY: all clean fclean re obj nobj ${LIBFT_FOLDER}/${LIBFT_NAME}

all: ${NAME}

%.o: ${SRC_FOLDER}/%.c
	${CC} -c -I${SRC_FOLDER} ${FLAGS} -c -o $@ $<

${NAME}: ${LIBFT_FOLDER}/${LIBFT_NAME} ${PRINTF_NAME}
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
	${CC} -I${SRC_FOLDER} ${TEST_FILES} ${NAME} -o ${TEST_NAME}

obj: ${OBJ}

nobj: all clean
