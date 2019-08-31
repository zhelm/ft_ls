SRC_NAME=ft_argsort.c ft_argv_analize.c ft_assign_dir.c ft_dorec.c\
ft_erlst.c\
ft_intlen.c\
ft_isdir.c\
ft_isdir_rec.c\
ft_listrec.c\
ft_listsort.c\
ft_ls_check_dir.c\
ft_ls_check_file_type.c\
ft_ls_checkflags.c\
ft_ls_error.c\
ft_ls_free_tmplist.c\
ft_ls_l.c\
ft_ls_l_analize.c\
ft_ls_lstadd.c\
ft_ls_lstnew.c\
ft_ls_mkflags.c\
ft_ls_mklst.c\
ft_ls_mode.c\
ft_ls_print_l.c\
ft_ls_print_lsub.c\
ft_ls_seg_lstadd.c\
ft_merge_sort_list.c\
ft_print_err.c\
ft_print_l_time.c\
ft_printfiles.c\
ft_printlist.c\
ft_put_size_t.c\
ft_putspaces.c\
ft_size_t_len.c\
ft_sort_time.c\
ft_sortarg_time.c\
helo.c\
main.c
NAME=ft_ls
RED=\033[0;31m
LBLUE=\033[1;34m
LGREEN=\033[1;32m
FLAGS = -g
LIBFT_PATH = ./libft/
SRC_PATH = ./srcs/
OBJ = $(SRC:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
all:$(NAME)

$(NAME):$(OBJ)
	@make -C libft/	
	@gcc $(FLAGS) $(OBJ) -L $(LIBFT_PATH) -lft  -o $(NAME)

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@
	@echo "$(LGREEN)Done compiling $(NAME)"

clean:
	@make clean -C libft/
	@rm -f $(OBJ)
	@echo "$(LBLUE)Cleaned All .O Files"

fclean:clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@rm -f libftcomb.a
	@echo "$(LBLUE)Cleaned librarys and exec"

re:fclean all
