APPS = ./app
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src
PROGRAM = ex002
TESTE = ex002_Main

all: libed myapps

libed:
	gcc -c $(SRC)/$(PROGRAM).c -I $(INCLUDE) -o $(OBJ)/$(PROGRAM).o

myapps:
	gcc $(APPS)/$(TESTE).c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@