NAME = fdf 
CC = gcc 
LIBFT = libs/libft
GNL = libs/getnextline
INCLUDES = -Iincludes -I/usr/local/include 
LIBS = $(addprefix $(GNL), /gnl.a) $(addprefix $(LIBFT), /libft.a)
SRC_DIR = src/
SRC_FILES = main.c
PARSING_DIR = $(SRC_DIR)parsing/
PARSING_FILES = read_map.c parse.c check_overflow.c
RENDRING_DIR = $(SRC_DIR)rendring/
RENDRING_FILES = draw.c
CFILES = $(addprefix $(SRC_DIR), $(SRC_FILES))
CFILES += $(addprefix $(PARSING_DIR), $(PARSING_FILES))
CFILES += $(addprefix $(RENDRING_DIR), $(RENDRING_FILES))
RM = rm -rf 
OBJ = $(CFILES:%.c=%.o)


all : $(NAME)

CFLAGS = -g -fsanitize=address
debug : $(NAME)

libft:
	@echo "\033[92mMaking Libft\n\033[0m"
	@cd $(LIBFT) && make
gnl: 
	@echo "\033[92mMaking getnextline\n\033[0m"
	@cd $(GNL) && make

$(NAME): libft gnl $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -lmlx -framework OpenGL -framework AppKit -g3 -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -g3 -o $@

clean :
	$(RM) $(OBJ)
	@cd $(LIBFT) && make clean
	@cd $(GNL) && make clean

fclean : clean
	$(RM) $(NAME)
	@cd $(LIBFT) && make fclean
	@cd $(GNL) && make fclean

re: fclean all 
