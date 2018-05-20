CC	:= g++

RM	:= rm -rf

LDFLAGS	+= -L. -lmy

CFLAGS	+= -Iinclude

SRCS	:= $(wildcard *.cpp)

OBJS	:= $(SRCS:.cpp=.o)

NAME	:= caesar

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
