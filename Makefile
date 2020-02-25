#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fmiceli <fmiceli@student.codam.nl...>        +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/13 18:25:56 by fmiceli       #+#    #+#                  #
#    Updated: 2019/06/13 18:25:57 by fmiceli       ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME=push_swap
NAME_C=checker

SRCS= \
	ft_quicksort.c \
	math.c \
	set_tab.c \
	tab_is_valid.c \
	stack_management.c \
	stack_ops.c \
	stack_pointer_ops.c \
	stack_wrapper_functions.c
SRCS_C:= \
	checker.c
SRCS_PS:= \
	push_swap.c \
	node.c \
	merge_new_nodes.c \
	node_del.c \
	node_evaluate.c \
	node_queue_init.c \
	do_pushes.c \
	do_revrots.c \
	do_rotations.c \
	do_swaps.c \
	moves.c \
	heuristic_search.c \
	heuristic_search_prep.c

OBJ:= $(SRCS:.c=.o)
OBJ_C:= $(SRCS_C:.c=.o)
OBJ_PS:= $(SRCS_PS:.c=.o)

INCLS:= \
	./ \
	./libft/ \
	./heuristic_search/

LIBFT:=./libft/libft.a

VPATH:= \
	./stack/ \
	./heuristic_search/ \
	./heuristic_search/node/ \
	./heuristic_search/do_moves/ \

UNAME:= $(shell uname)

ifeq ($(UNAME), Linux)
	FLAGS:= -O3
else
	FLAGS:= -Wall -Wextra -Werror
endif

all : $(NAME_C) $(NAME)

%.o : %.c
	@gcc -c $< -I $(INCLS) $(FLAGS)

$(NAME) : $(OBJ) $(OBJ_PS) $(LIBFT)
	@gcc -o $(NAME) $(OBJ) $(OBJ_PS) $(LIBFT) $(FLAGS)

$(NAME_C) : $(OBJ) $(OBJ_C) $(LIBFT)
	@gcc -o $(NAME_C) $(OBJ) $(OBJ_C) $(LIBFT) $(FLAGS)

$(LIBFT) :
	@make -C ./libft/

clean :
	@find . -type f -name "*~" -delete
	@find . -type f -name "*.gch" -delete
	@find . -type f -name "\#*.c\#" -delete
	@find . -type f -name "*.o" -delete
	@make fclean -C ./libft/

fclean : clean
	@rm -f $(NAME) $(NAME_PS)
	@make fclean -C ./libft/

re : fclean all
