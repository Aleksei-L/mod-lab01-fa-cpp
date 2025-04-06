// Copyright 2022 UNN-IASR
#include "fun.h"
#include <string.h>

unsigned int faStr1(const char* str) {
    int counter = 0;
    int size = strlen(str);
    bool isCurrentWord = false;
    bool hasDigit = false;

    for (int i = 0; i < size; i++) {
        if (str[i] == ' ') {
            if (isCurrentWord) {
                isCurrentWord = false;
                if (!hasDigit) {
                    counter++;
                }
                hasDigit = false;
            }
        } else if (static_cast<int>(str[i]) >= 48 && static_cast<int>(str[i]) <= 57) {
            hasDigit = true;
        } else {
            if (!isCurrentWord) {
                isCurrentWord = true;
            }
        }
    }

    return counter;
}

unsigned int faStr2(const char* str) {
    int counter = 0;
    int size = strlen(str);
    bool isCurrentWord = false;
    bool hasBigLetter = false;
    bool hasSmallLetter = false;
    bool correctWord = true;

    for (int i = 0; i < size; i++) {
        if (str[i] == ' ') {
            if (isCurrentWord && correctWord) {
                if (hasBigLetter && hasSmallLetter) {
                    counter++;
                }
                isCurrentWord = false;
                hasBigLetter = false;
                hasSmallLetter = false;
                correctWord = true;
            }
        } else if (!correctWord) {
            continue;
        } else if (static_cast<int>(str[i]) >= 65 && static_cast<int>(str[i]) <= 90) { //for big
            if (!isCurrentWord) {
                hasBigLetter = true;
                isCurrentWord = true;
            }
            else {
                correctWord = false;
            }
        } else if (static_cast<int>(str[i]) >= 97 && static_cast<int>(str[i]) <= 122) { //for small
            hasSmallLetter = true;
        } else {
            correctWord = false;
        }
    }

    return counter;
}

unsigned int faStr3(const char* str) {
    int counter = 0;
    int size = strlen(str);
    bool isCurrentWord = false;
    int letterCounter = 0;
    int wordCounter = 0;

    for (int i = 0; i < size; i++) {
        if (str[i] == ' ') {
            if (isCurrentWord) {
                wordCounter++;
            }
            isCurrentWord = false;
        } else if (i == size - 1) {
            letterCounter++;
            if (isCurrentWord) {
                wordCounter++;
            }
            isCurrentWord = false;
        } else {
            isCurrentWord = true;
            letterCounter++;
        }
    }

    return letterCounter / wordCounter;
}
