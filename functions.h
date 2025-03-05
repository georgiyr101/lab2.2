#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

int check_word_length();

void fillFile(const char* filename);

void printFile(const char* filename);

void findLongestRepeatingSequence(const char* filename);

void replaceWordsWithSpaces(const char* filename, int word_length);


#endif
