NAME_SERV=server
NAME_CLIENT=client
CC=cc
CC_FLAGS=-Wall -Wextra -Werror

SRC_CLIENT=client.c
SRC_SERVER=server.c

LIB= libft/libft.a

DIR_OBJS=.objs
DIR_DEPS=.deps

OBJS_CLIENT=$(SRC_CLIENT:%.c=$(DIR_OBJS)/%.o)
OBJS_SERVER=$(SRC_SERVER:%.c=$(DIR_OBJS)/%.o)

DEPS_CLIENT=$(SRC_CLIENT:%.c=$(DIR_DEPS)/%.d)
DEPS_SERVER=$(SRC_SERVER:%.c=$(DIR_DEPS)/%.d)


all: compile_start libft $(NAME_SERV) $(NAME_CLIENT) compile_done

compile_start:
	echo "$(COLOUR_GREEN) Compile start ... $(COLOUR_END)"

compile_done:
	echo "$(COLOUR_GREEN) Compiling done $(COLOUR_END)"

libft:
	$(MAKE) --silent -C ./libft

$(NAME_SERV): $(OBJS_SERVER) $(DEPS)
	$(CC) $(CC_FLAGS) $(OBJS_SERVER) $(LIB) -o $@
	echo "$(COLOUR_BLUE) Server is ready $(COLOUR_END)"

$(NAME_CLIENT): $(OBJS_CLIENT) $(DEPS)
	$(CC) $(CC_FLAGS) $(OBJS_CLIENT) $(LIB) -o $@
	echo "$(COLOUR_BLUE) Client is ready $(COLOUR_END)"

$(DIR_OBJS)/%.o: %.c | $(DIR_OBJS) $(DIR_DEPS)
	$(CC) $(CC_FLAGS) -MMD -MP -MF $(DIR_DEPS)/$*.d -c -o $@ $<


$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

$(DIR_DEPS):
	mkdir -p $(DIR_DEPS)

clean:
	echo "$(COLOUR_RED)Removing files... $(COLOUR_END)"
	$(MAKE) --silent -C  ./libft fclean
	rm -rf $(DIR_OBJS)
	rm -rf $(DIR_DEPS)

fclean: clean
	echo "$(COLOUR_RED)Removing executable... $(COLOUR_END)"
	$(MAKE) --silent -C  ./libft fclean
	rm -rf $(NAME_SERV)
	rm -rf $(NAME_CLIENT)

re: fclean all

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

.PHONY: all clean fclean re libft
.SILENT: