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
	@gcc $(OBJ) -o $(NAME) $(MLX) $(MATHLIB) $(MULTHREAD) $(LIBFT_FLAGS)
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




# ifeq ($(shell uname -s), Linux)
# MLX		= ./miniLibX_X11/
# MLX_LNK	= -L $(MLX) -l mlx -lXext -lX11
# else
# MLX		= ./minilibx_opengl_20191021/
# MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
# endif

# MLX_INC	= -I $(MLX)
# MLX_LIB	= $(addprefix $(MLX),mlx.a)

# # ft library
# FT		= ./libft/
# FT_LIB	= $(addprefix $(FT),libft.a)
# FT_INC	= -I ./libft
# FT_LNK	= -L ./libft -l ft -l pthread

# all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

# obj:
# 	mkdir -p $(OBJDIR)

# $(OBJDIR)/%.o:$(SRCDIR)/%.c
# 	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCLDIR) -o $@ -c $<

# $(FT_LIB):
# 	@make -C $(FT)

# $(MLX_LIB):
# 	@make -C $(MLX)

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

# clean:
# 	rm -rf $(OBJDIR)
# 	make -C $(FT) clean
# 	make -C $(MLX) clean

# fclean: clean
# 	rm -rf $(NAME)
# 	make -C $(FT) fclean

# re: fclean all

