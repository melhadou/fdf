NAME = fdf 
CC = gcc 
LIBFT = libs/libft
GNL = libs/getnextline
INCLUDES = -Iincludes -I/usr/local/include $(addprefix $(LIBFT), /libft.a) $(addprefix $(GNL), /gnl.a)
SRC_DIR = src/
SRC_FILES = main.c
PARSING_DIR = $(SRC_DIR)parsing/
PARSING_FILES = read_map.c
CFILES = $(addprefix $(SRC_DIR), $(SRC_FILES))
CFILES += $(addprefix $(PARSING_DIR), $(PARSING_FILES))
RM = rm -rf 
OBJ = $(CFILES:%.c=%.o)


all : $(NAME)

CFLAGS = -g3 -fsanitize=address
debug : $(NAME)

libft:
	@cd $(LIBFT) && make
gnl: 
	@cd $(GNL) && make

$(NAME): libft gnl $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	$(RM) $(OBJ)
	@cd $(LIBFT) && make clean
	@cd $(GNL) && make clean

fclean : clean
	$(RM) $(NAME)
	@cd $(LIBFT) && make fclean
	@cd $(GNL) && make fclean
