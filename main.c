#include <stdio.h>
#include "functions.h"
#include <locale.h>
#include <conio.h>


int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    const char* filename = argv[1];
    setlocale(LC_ALL, "russian");
    fillFile(filename);
    printFile(filename);
    puts("Введите номер задания:");
    puts("1 - Найти наиболее длинную последовательность повторяющихся символов.");
    puts("2 - Заменить все слова заданной длины пробелами.");
    puts("0 - Выход");
    while (1)
    {
        char task = _getch();
        if (task == '1') findLongestRepeatingSequence(filename);
        else if (task == '2') {
            int word_length = check_word_length();
            replaceWordsWithSpaces(filename, word_length);
            printFile(filename);
        }
        else if (task == '0') return 0;
        puts(" ");
    }

    return 0;
}

