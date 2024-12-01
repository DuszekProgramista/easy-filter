# Nazwa programu wynikowego
TARGET = easy-filter

# Ścieżka do katalogu źródeł
SRC_DIR = src

# Ścieżka do katalogu obiektów
OBJ_DIR = obj

# Kompilator
CC = gcc

# Flagi kompilatora
CFLAGS = -Wall -g

# Pliki źródłowe
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Pliki obiektowe
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Reguła domyślna - budowanie programu
all: $(TARGET)

# Tworzenie katalogu obj, jeśli nie istnieje
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Kompilacja plików źródłowych do plików obiektowych
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Łączenie obiektów w finalny plik wykonywalny
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Czyszczenie plików obiektowych i wynikowego
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Instalacja (opcjonalnie)
install: $(TARGET)
	# Przykładowa instalacja do katalogu /usr/local/bin
	# cp $(TARGET) /usr/local/bin/
