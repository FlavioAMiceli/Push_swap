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
	./stack/stack_management.c \
	./stack/stack_ops.c \
	./stack/stack_pointer_ops.c \
	./stack/stack_wrapper_functions.c
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

OBJ = $(SRCS:.c=.o)
OBJ_C= $(SRCS_C:.c=.o)
OBJ_PS= $(SRCS_PS:.c=.o)

HEADERS= \
	./push_swap.h \
	./libft/libft.h \
	./heuristic_search/heuristic_search.h

LIBFT=./libft/libft.a
FLAGS= -Wall -Wextra -Werror

all : $(LIBFT) $(NAME_C) $(NAME) clean

%.o: %.c $(HEADERS)
	@gcc -o $@ -c $< $(FLAGS) -I $(HEADERS)

$(NAME) : $(OBJ) $(OBJ_C) $(OBJ_PS) $(LIBFT)
	@gcc -o $(NAME_C) $(SRCS) $(SRCS_C) -I $(HEADERS) $(LIBFT) $(FLAGS)
	@gcc -o $(NAME) $(SRCS) $(SRCS_PS) -I $(HEADERS) $(LIBFT) $(FLAGS)

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
