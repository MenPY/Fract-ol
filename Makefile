NAME		= fractol
CC			= gcc
SRCDIR		= ./src/
INCLDIR		= ./inc/
SRC			= $(addprefix $(SRCDIR), fractols.c\
									controls.c\
									main.c\
									colors.c\
									colormode.c\
									utils.c)
OBJDIR		= ./obj/
OBJ			= $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
FLAGS		= -O3

MLX			= -lmlx
ifeq ($(shell uname -s), Linux)
  MLXDIR	= ./minilibx/
  MLX		+= -lX11 -lXext -L$(MLXDIR)
  MLXLIB	= $(addprefix $(MLXDIR), libmlx.a)
else
MLXDIR	= ./minilibx_opengl_20191021/
MLX		= -L $(MLXDIR) -l mlx -framework OpenGL -framework AppKit
MLX_LIB	= $(addprefix $(MLX),mlx.a)
endif

LIBFT_DIR	= ./libft/
LIBFT		= $(addprefix $(LIBFT_DIR), libft.a)
LIBFT_FLAGS	= -lft -L$(LIBFT_DIR)
MATHLIB		= -lm
INCL		= $(addprefix $(INCLDIR), fractol.h)

.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCL)
	@printf "\tCompiling $<\n"
	@mkdir -p $(OBJDIR)
	@gcc $(FLAGS) -c $< -o $@ -I$(INCLDIR)

$(NAME): $(OBJ) $(LIBFT) $(MLXLIB)
	@gcc $(OBJ) -o $(NAME) $(MLX) $(MATHLIB) $(LIBFT_FLAGS)
	@printf "Done\n"
$(LIBFT):
	@printf "\tCompiling libft.a...\n"
	@make -sC $(LIBFT_DIR)
$(MLXLIB):
	@printf "\tCompiling libmlx.a\n"
	@make -sC $(MLXDIR)
clean:
	@rm -rf $(OBJDIR)
	@printf "\tObject files removed\n"
fclean: clean
	@rm -f $(NAME)
	@printf "\tExecutable '$(NAME)' removed\n"
	@make -sC $(LIBFT_DIR) fclean
re: fclean all
