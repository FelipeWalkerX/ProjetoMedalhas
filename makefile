SRC=./Classes/*.c		#Pasta aonde fica todos os arquivos .c
INCLUDE=-I./Libs/		#Pasta aonde fica todos os arquivos .h (biblioteca)
BIN=./main				#Minha main

all:
	gcc $(SRC) -g -lm $(INCLUDE) -o $(BIN)
	
run:
	$(BIN)			

clean:
	rm $(BIN)