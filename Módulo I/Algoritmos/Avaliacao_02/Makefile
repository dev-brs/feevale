# Nome do executável
TARGET = programa

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -g
LDFLAGS = 

# Diretórios
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Busca por todos os arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Regra padrão: compilar tudo
all: $(BUILD_DIR) $(TARGET)

# Compilar o executável
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Compilar os arquivos .o a partir dos .c
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

# Criar diretório de build, se necessário
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Limpeza dos arquivos gerados
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Limpar e recompilar
rebuild: clean all

# Regra para executar o programa (opcional)
run: $(TARGET)
	./$(TARGET)

# Evitar que comandos comuns sejam tratados como arquivos
.PHONY: all clean rebuild 
