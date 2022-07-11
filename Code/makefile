NAME_PROGRAM = edcare.out
CC = gcc
FLAGS = -lm -pedantic -Wall 
C_FILES = $(wildcard *.c)
O_FILES = $(patsubst %.c, %.o, $(C_FILES))

all: $(O_FILES) create_executable

edcare.o: edcare.c
	@ echo "\033[1;36m"
	@ echo "Compilando edcare.c ..."
	@ $(CC) -c $< $(FLAGS)
	@ echo "\033[0m"

%.o: %.c %.h
	@ echo "\033[1;36m"
	@ echo "Compilando $< ..."
	@ $(CC) -c $< $(FLAGS)
	@ echo "\033[0m"

create_executable: 
	@ echo "\033[1;36m"
	@ echo "Criando executavel..."
	@ $(CC) -o $(NAME_PROGRAM) $(O_FILES) $(FLAGS)
	@ echo "\033[0m"

run : 
	@ echo "\033[1;36m"
	@ echo "Rodando programa ..."
	@ echo "\033[0m"
	@ ./$(NAME_PROGRAM) 

test: clean all run

valgrind: 
	@ echo "\033[1;36m"
	@ echo "Rodando valgrind ..."
	@ echo "\033[0m"
	@ valgrind ./$(NAME_PROGRAM)

clean: 
	@ echo "\033[1;35m"
	@ echo "Removing arquivos temporarios ..."
	@ rm -rf $(NAME_PROGRAM) $(O_FILES)
	@ echo "\033[0m"

clean_test:
	@ echo "\033[1;31m"
	@ echo "Removendo arquivos gerais ..."
	@ rm -rf $(NAME_PROGRAM) $(O_FILES) *saida.txt
	@ echo "\033[0m"
clean_all:
	@ echo "\033[1;31m"
	@ echo "Removendo arquivos gerais ..."
	@ rm -rf $(NAME_PROGRAM) $(O_FILES) *.txt
	@ echo "\033[0m"


