NAME = PmergeMe

CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
INCS		= -Iinc
SRC_DIR		= src
OBJ_DIR		= obj
SRCS		= main.cpp					\
				PmergeMe.cpp	

SRC_FILES	= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS		= $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(NAME)

$(NAME):	$(OBJS)
	@$(CXX) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
		@mkdir -p $(OBJ_DIR)
		@$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@

clean:
		@rm -rf $(OBJ_DIR)

fclean:		clean
		@rm -f $(NAME)

re:				fclean all
