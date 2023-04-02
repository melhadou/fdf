NAME = fdf 
CC = cc 

LIBFT = libs/libft
MLX = libs/minilibx_macos
GNL = libs/getnextline

INCLUDES = -Iincludes 
LIBS = $(addprefix $(GNL), /gnl.a) $(addprefix $(LIBFT), /libft.a) $(addprefix $(MLX), /libmlx.a)

SRC_DIR = src/
SRC_FILES = main.c

PARSING_DIR = $(SRC_DIR)parsing/
PARSING_FILES = read_map.c parse.c check_overflow.c

RENDRING_DIR = $(SRC_DIR)rendring/
RENDRING_FILES = draw.c resize.c

CFILES = $(addprefix $(SRC_DIR), $(SRC_FILES))
CFILES += $(addprefix $(PARSING_DIR), $(PARSING_FILES))
CFILES += $(addprefix $(RENDRING_DIR), $(RENDRING_FILES))
RM = rm -rf 
OBJ = $(CFILES:%.c=%.o)

# color list
BRed=\033[1;31m
BCyan=\033[1;36m
BYellow=\033[1;33m

all : $(NAME)
	@echo "${BCyan}Successfully Completed"

CFLAGS = -g -fsanitize=address
debug : $(NAME)

libft:
	@echo "${BYellow}Making Libft"
	@cd $(LIBFT) && make
mlx: 
	@echo "${BYellow}Making MiniLibx"
	@cd $(MLX) && make
gnl: 
	@echo "${BYellow}Making getnextline"
	@cd $(GNL) && make

$(NAME): libft gnl mlx $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -framework OpenGL -framework AppKit -g3 -o $(NAME)

%.o: %.c
	$(CC) $(INCLUDES) -c $< -g3 -o $@

clean :
	$(RM) $(OBJ)
	@cd $(LIBFT) && make clean
	@cd $(GNL) && make clean
	@cd $(MLX) && make fclean
	@clear
	@echo "\033[92mSuccessfully Cleaned\n\033[0m"

fclean : clean
	$(RM) $(NAME)
	@cd $(LIBFT) && make fclean
	@cd $(GNL) && make fclean
	@cd $(MLX) && make fclean
	@clear
	@echo "\033[92mSuccessfully Cleaned using Fclean\n\033[0m"

re: fclean all
