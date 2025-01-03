NAME = WrongForm

SRCS = ./srcs/

INCLUDES = -Iincludes

CPPFILES = 	$(SRCS)main.cpp $(SRCS)Bureaucrat.cpp $(SRCS)AForm.cpp \
			$(SRCS)ShrubberyCreationForm.cpp $(SRCS)RobotomyRequestForm.cpp \
			$(SRCS)PresidentialPardonForm.cpp
OFILES = $(CPPFILES:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OFILES)
	$(CXX) -g -o $(NAME) $(OFILES)

$(SRCS)%.o: $(SRCS)%.cpp
	$(CXX) $(CXXFLAGS) -g -c -o $@ $< $(INCLUDES)

clean:
	rm -f $(OFILES) *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re