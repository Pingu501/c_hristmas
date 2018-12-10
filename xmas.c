#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 8

int lastWasSpecial = 0;

int getNumberOfElements(int a) {
    return (a * 2) + 1;
}

char getSign() {
    int r = rand() % 100;
    if (lastWasSpecial) {
        lastWasSpecial = 0;
        return '^';
    } else {
        if (r <= 20) {
            lastWasSpecial = 1;
            return 'o';
        } else if (r <= 40) {
            lastWasSpecial = 1;
            return '*';
        } else {
            lastWasSpecial = 0;
            return '^';
        }
    }
}

void printNTimes(int amount, char sign) {
    for (int i = 0; i < amount; i++) {
        printf("%c", sign);
    }
}

void printTree() {
    char colors[6][10] = {
            "\x1b[31m"
            "\x1b[32m",
            "\x1b[33m",
            "\x1b[34m",
            "\x1b[35m",
            "\x1b[36m"
    };

    char sign;
    int maxNumberOfElements = getNumberOfElements(SIZE);

    for (int depth = 0; depth <= SIZE; depth++) {
        int numberOfSymbols = getNumberOfElements(depth);
        int numberOfWhiteSpaces = (maxNumberOfElements - numberOfSymbols) / 2;

        for (int i = 1; i <= maxNumberOfElements; i++) {
            if (i > numberOfWhiteSpaces && i <= numberOfWhiteSpaces + numberOfSymbols) {
                char sign = getSign();

                int colorIndex;
                if (sign == '^') {
                    colorIndex = 4;
                } else {
                    colorIndex = (rand() % 5) + 1;
                }

                printf("%s%c", colors[colorIndex], sign);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printNTimes((maxNumberOfElements / 2) - 1, ' ');
    printf("\x1b[32m| |");
    printNTimes((maxNumberOfElements / 2) - 1, ' ');
    printf("\n");
}

int main() {
    srand(time(NULL));
    printTree();
    usleep(10000);

    return 0;
}
