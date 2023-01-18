NAME = philosophers


SRCS = philosophers.c check.c mutex.c routine.c monitor.c ft_atoi.c ft_isdigit.c ft_putstr_fd.c ft_putchar_fd.c


CC		= cc


RM		= rm -f


CFLAGS = -Wall -Wextra -Werror


$(NAME): ${OBJS}
		${CC} ${CFLAGS} $(SRCS) -o $(NAME)


all:	${NAME}


clean:
		${RM} ${OBJS}


fclean:	clean
		${RM} ${NAME}


re:		fclean all


.PHONY: all clean fclean re