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
SRCS_C= \
	checker.c
SRCS_PS= \
	push_swap.c \
	./heuristic_search/node/node.c \
	./heuristic_search/do_moves/do_pushes.c \
	./heuristic_search/do_moves/do_revrots.c \
	./heuristic_search/do_moves/do_rotations.c \
	./heuristic_search/do_moves/do_swaps.c \
	./heuristic_search/do_moves/moves.c \
	./heuristic_search/heuristic_search.c \
	./heuristic_search/heuristic_search_prep.c

HEADERS= \
	./push_swap.h \
	./heuristic_search.h
LIBFT=./libft/libft.a
VPATH=/libft
FLAGS= -Wall -Wextra -Werror

all : $(NAME_C) $(NAME) clean

$(NAME) : $(LIBFT)
	@gcc -o $(NAME_C) $(SRCS) $(SRCS_C) $(FLAGS) -I $(HEADERS) $(LIBFT)
	@gcc -o $(NAME) $(SRCS) $(SRCS_PS) $(FLAGS) -I $(HEADERS) $(LIBFT)

$(LIBFT) :
	@make -C ./libft/

clean :
	@find . -type f -name "*~" -delete
	@find . -type f -name "\#*.c\#" -delete
	@make clean -C ./libft/

fclean : clean
	@rm -f $(NAME) $(NAME_PS)
	@find . -type f -name "*.o" -delete
	@make fclean -C ./libft/

re : fclean all
