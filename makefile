PUSHSWAP	 	= push_swap.c

OBJSPUSHSWAP = $(PUSHSWAP:.c=.o)

CC			= gcc
CFLAGS		= 			#FAlta Voltar a por Flags
RM 			= rm -f

NAME		= push_swap

$(NAME):	push_swap

all:		$(NAME)

server: 	push_swap.o
			$(CC) $(CFLAGS) push_swap.o -o push_swap



clean:
		$(RM) $(OBJSPUSHSWAP)
		
fclean:		clean
			$(RM) push_swap

re:			fclean all

.PHONY:		all clean fclean re 