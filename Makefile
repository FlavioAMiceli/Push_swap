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

NAME_C=checker
NAME_PS=push_swap
SRCS_C=checker.c
SRCS_PS=push_swap.c
OBJS_C=$(SRCS_C:.c=.o)
OBJS_PS=$(SRCS_PS:.c=.o)
HEADER=push_swap.h
LIBFT=./libft/libft.a
VPATH=/libft
FLAGS= -Wall -Wextra -Werror

all : $(LIBFT) $(NAME_C) clean

$(NAME_C) :
	@gcc -o $(NAME_C) $(SRCS_C) $(FLAGS) -I $(HEADER) $(LIBFT)

$(NAME_PS) :
	@gcc -o $(NAME_PS) $(SRCS_PS) $(FLAGS) -I $(HEADER) $(LIBFT)

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
