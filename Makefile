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
SRCS=set_stack.c tab_is_valid.c ops.c ft_quicksort.c ft_intdllflatten.c
NAME_C=checker
NAME_PS=$(NAME)
SRCS_C=checker.c
SRCS_PS=push_swap.c
OBJS=$(SRCS:.c=.o)
OBJS_C=$(SRCS_C:.c=.o)
OBJS_PS=$(SRCS_PS:.c=.o)
HEADER=push_swap.h
LIBFT=./libft/libft.a
VPATH=/libft
FLAGS= -Wall -Wextra -Werror

all : $(NAME_C) $(NAME_PS) clean

$(NAME) : $(LIBFT)
	@gcc -o $(NAME_PS) $(SRCS) $(SRCS_PS) $(FLAGS) -I $(HEADER) $(LIBFT)

$(NAME_C) : $(LIBFT)
	@gcc -o $(NAME_C) $(SRCS) $(SRCS_C) $(FLAGS) -I $(HEADER) $(LIBFT)

$(LIBFT) :
	@make -C ./libft/

clean :
	@rm -f *~
	@rm -f \#*.c\#
	@make clean -C ./libft/

fclean : clean
	@rm -f $(NAME_C) $(NAME_PS)
	@rm -f *.o
	@make fclean -C ./libft/

re : fclean all
