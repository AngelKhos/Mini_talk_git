NAME_SERV=Server
NAME_CLIENT=Client
CC=cc
CC_FLAGS=-Wall -Wextra -Werror

SRCS=client.c

DIR_OBJS=.objs
DIR_DEPS=.deps
OBJS=$(SRCS:%.c=$(DIR_OBJS)/%.o)
DEPS=$(SRCS:%.c=$(DIR_DEPS)/%.d)

all: $(NAME)

$(NAME): $(OBJS)
	echo "Compiling ..."
	$(CC) $(CC_FLAGS) -o $@ $(OBJS)

	
-include $(DEPS)
$(DIR_OBJS)/%.o: %.c | $(DIR_OBJS) $(DIR_DEPS)
	$(CC) $(CC_FLAGS) -MMD -MP -MF $(DIR_DEPS)/$*.d -c -o $@ $<

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

$(DIR_DEPS):
	mkdir -p $(DIR_DEPS)

clean:
	echo "Removing files ..."
	rm -rf $(DIR_OBJS)
	rm -rf $(DIR_DEPS)

fclean: clean
	echo "Removing executable ..."
	rm -f $(NAME)
	

re: fclean all

.PHONY: all clean fclean re
.SILENT: