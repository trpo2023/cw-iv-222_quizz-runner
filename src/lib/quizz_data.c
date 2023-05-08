#include <stdio.h>
#include <stdlib.h>

#include <lib/quizz_create.h>
#include <lib/quizz_data.h>

int amount_of_quizzes()
{
    char* file = "data/quizz_data.csv";
    FILE* fp = fopen(file, "r");
    if (!fp) {
        return -1;
    }
    int qNumber;
    int qMaxNumber = 0;
    char endSeeker;
    while (fscanf(fp, "%d,", &qNumber) == 1) {
        if (qNumber > qMaxNumber) {
            qMaxNumber = qNumber;
        }
        while (1) {
            fscanf(fp, "%c", &endSeeker);
            if (endSeeker == '\n') {
                break;
            }
        }
    }
    fclose(fp);
    return qMaxNumber;
}

