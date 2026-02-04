NAME = span

FILES = main.cpp 	\
		Span.cpp	\

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -std=c++98

OFILES = ${FILES:%.cpp=%.o}
DFILES = ${OFILES:%.o=%.d}

all: $(NAME)

$(NAME): $(OFILES)
	$(CXX) $^ -o $@

clean:
	rm -rf $(OFILES) $(DFILES) $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DFILES)