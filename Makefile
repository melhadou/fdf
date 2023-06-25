NAME = fdf 
CC = cc  -Wall -Wextra -Werror 
# CFLAGS = -g3 -fsanitize=address 
# CFLAGS =
LIBFT = libs/libft
GNL = libs/getnextline
FT_PRINTF = libs/ft_printf

INCLUDES = -Iincludes 
LIBS = $(addprefix $(GNL), /gnl.a) $(addprefix $(LIBFT), /libft.a) $(addprefix $(FT_PRINTF), /libftprintf.a)

SRC_DIR = src/
SRC_FILES = main.c

PARSING_DIR = $(SRC_DIR)parsing/
PARSING_FILES = read_map.c parse.c fdf_alloc.c

RENDRING_DIR = $(SRC_DIR)rendring/
RENDRING_FILES = draw.c resize.c events.c dda.c

UTILS_DIR = $(SRC_DIR)utils/
UTILS_FILES = utils.c check_map.c

CFILES = $(addprefix $(SRC_DIR), $(SRC_FILES))
CFILES += $(addprefix $(PARSING_DIR), $(PARSING_FILES))
CFILES += $(addprefix $(RENDRING_DIR), $(RENDRING_FILES))
CFILES += $(addprefix $(UTILS_DIR), $(UTILS_FILES))

RM = rm -rf 
OBJ = $(CFILES:%.c=%.o)

# color list
BRED=\033[1;31m
BCYAN=\033[1;36m
BYELLOW=\033[1;33m
NC=\033[0m

all :  libft ft_printf gnl $(NAME)
	@echo "${BCYAN}Successfully Completed ${NC}"

debug : $(NAME)

libft:
	@echo "${BYELLOW}Making Libft ${NC}"
	@cd $(LIBFT) && make
gnl: 
	@echo "${BYELLOW}Making getnextline ${NC}"
	@cd $(GNL) && make
ft_printf:
	@echo "${BYELLOW}Making Ft_printf ${NC}"
	@cd $(FT_PRINTF) && make

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -framework OpenGL -lmlx -framework AppKit -o $(NAME)

%.o: %.c
	$(CC)  $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	$(RM) $(OBJ)
	@cd $(LIBFT) && make clean
	@cd $(FT_PRINTF) && make clean
	@cd $(GNL) && make clean
	@echo "${BRED}Successfully Cleaned ${NC}"

fclean : clean
	$(RM) $(NAME)
	@cd $(LIBFT) && make fclean
	@cd $(FT_PRINTF) && make fclean
	@cd $(GNL) && make fclean
	@echo "${BRED}Successfully Cleaned using Fclean ${NC}"

re: fclean all

.PHONY: all libft gnl clean fclean re
