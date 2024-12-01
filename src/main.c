#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Funkcja sprawdzająca, czy linia zawiera zakazane słowo
bool contains_bad_word(const char *line, const char *bad_words[], int num_bad_words) {
    for (int i = 0; i < num_bad_words; i++) {
        if (strstr(line, bad_words[i]) != NULL) {
            return true; // Znaleziono zakazane słowo
        }
    }
    return false; // Brak zakazanych słów
}

int main(int argc, char *argv[]) {
    if (argc != 3 || strcmp(argv[1], "--scan") != 0) {
        printf("Użycie: easy-filter --scan <nazwa_pliku>\n");
        return 1;
    }

    // Lista zakazanych słów (można dodać więcej)
    const char *bad_words[] = {
        "pornografia",
        "seks",
        "nagość"
    };
    
    int num_bad_words = sizeof(bad_words) / sizeof(bad_words[0]);

    // Otwieranie pliku
    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Nie udało się otworzyć pliku: %s\n", argv[2]);
        return 1;
    }

    char line[256]; // Bufor do przechowywania linii z pliku
    int line_num = 1; // Numer linii w pliku

    // Odczytujemy plik linia po linii
    while (fgets(line, sizeof(line), file)) {
        // Sprawdzamy, czy linia zawiera zakazane słowa
        if (contains_bad_word(line, bad_words, num_bad_words)) {
            printf("Ostrzeżenie: Zawiera nieodpowiednie słowo w linii %d: %s", line_num, line);
        }
        line_num++;
    }

    fclose(file);
    return 0;
}
