##
## EPITECH PROJECT, 2021
## InfinAdd
## File description:
## Makefile
##

CC			= 	gcc
CFLAGS		= 	-c -I./include/

SRC 		=	bistromatic.c handle_errors.c handle_errors_utilities.c \
				syntax_checker.c eval_expr.c infin_add.c \
				infin_add_calculation.c infin_sub.c infin_mul.c \
				infin_factors_calculation.c \
				infin_div.c add_functions.c infin_mod.c \

OBJ 		= 	bistromatic.o handle_errors.o handle_errors_utilities.o \
				syntax_checker.o eval_expr.o \
				infin_add.o infin_add_calculation.o infin_sub.o infin_mul.o \
				infin_factors_calculation.o \
				infin_div.o add_functions.o infin_mod.o \

TARGET		= 	calc \

all: $(TARGET)

$(TARGET): $(OBJ)
	cd lib/my && make && cd ../..
	make -C ./lib/my
	$(CC) -o $(TARGET) $(OBJ) -L./lib/ -lmy -g3

clean:
	rm -rf $(OBJ)
	make clean -C ./lib/my

fclean:clean
	rm -rf $(TARGET)

re:fclean all