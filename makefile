# Nome do compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -Wextra -std=c99

# Nome do executável
TARGET = medalhas

# Arquivos fonte
SRC = main.c medalha.c

# Arquivos de cabeçalho
HEADERS = medalha.h

# Regra padrão para compilar o executável
$(TARGET): $(SRC) $(HEADERS)
    $(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Regra para rodar o programa
run: $(TARGET)
    ./$(TARGET)

# Regra para limpar os arquivos gerados
clean:
    rm -f $(TARGET)

# Regra para recompilar e rodar
rebuild: clean $(TARGET)
    ./$(TARGET)
