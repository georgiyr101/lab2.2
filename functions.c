#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <ctype.h>

int check_word_length()
{
    int n;
    while (1) {
        printf("Введите длину слова: ");
        if (scanf_s("%d", &n) != 0) {
            if ((getchar()) != '\n' || n > 100 || n <= 0) {
                printf("Ошибка: введите натуральное число!\n");
                while ((getchar()) != '\n')
                    continue;
            }
            else {
                break;
            }
        }
        else {
            printf("Ошибка: введите натуральное число!\n");
            while ((getchar()) != '\n')
                continue;
        }
    }
    return n;
}

void fillFile(const char* filename) {
	FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    puts("Введите символы:");
    char ch;
    while ((ch = getchar()) != '\n') {
        fputc(ch, file);
    }

    fclose(file);
}

void printFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    puts("Содержимое файла:");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void findLongestRepeatingSequence(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        exit(1);
    }

    char prev_char = EOF;
    char current_char;
    int max_length = 1, current_length = 1;
    char max_char = '\0';

    while ((current_char = fgetc(file)) != EOF) {
        if (current_char == prev_char) {
            current_length++;
            if (current_length > max_length) {
                max_length = current_length;
                max_char = current_char;
            }
        }
        else {
            current_length = 1;
        }
        prev_char = current_char;
    }

    fclose(file);
    puts("");
    if (max_char != '\0') {
        printf("Наиболее длинная последовательность: символ '%c', длина %d\n", max_char, max_length);
    }
    else {
        printf("Файл пуст или нет повторяющихся символов.\n");
    }
}

void replaceWordsWithSpaces(const char* filename, int word_length) {
    FILE* file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char ch;
    int word_start = -1;
    int current_length = 0;
    long pos;

    while ((ch = fgetc(file)) != EOF) {
        pos = ftell(file);

        if (isalpha(ch)) {
            if (current_length == 0) {
                word_start = pos - 1;
            }
            current_length++;
        }
        else {
            if (current_length == word_length) {
                fseek(file, word_start, SEEK_SET);
                for (int i = 0; i < word_length; i++) {
                    fputc(' ', file);
                }
                fseek(file, pos, SEEK_SET);
            }
            current_length = 0;
        }
    }

    if (current_length == word_length) {
        fseek(file, word_start, SEEK_SET);
        for (int i = 0; i < word_length; i++) {
            fputc(' ', file);
        }
    }

    fclose(file);
}
