#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib/quizz_create.h>
#include <lib/quizz_data.h>
#include <lib/quizz_run.h>

void* input(void* argument, char mode)
{
    if (mode == 's') {
        if (fgets((char*)argument, 99, stdin) == NULL)
            return NULL;
        else
            delete_new_string(&argument);
    } else if (mode == 'd') {
        if (scanf("%d", (int*)argument) == 0)
            return NULL;
    } else if (mode == 'c') {
        if (scanf(" %c", (char*)argument) == 0)
            return NULL;
    }
    return argument;
}

void delete_new_string(char** string)
{
    for (int i = 0; (*string)[i] != '\0'; i++) {
        if ((*string)[i] == '\n')
            (*string)[i] = '\0';
    }
}

int get_quizz_name(quizz* new_quizz, char* string)
{
    if ((strcmp(string, "quit")) == 0 || (strcmp(string, "quit\n")) == 0)
        return 1;
    else if (string == NULL)
        return -1;
    else {
        strcpy(new_quizz->quizzName, string);
        return 0;
    }
}

int get_question_text(quizz* new_quizz, int questionCount, char* string)
{
    if ((strcmp(string, "quit")) == 0 || (strcmp(string, "quit\n")) == 0)
        return 1;
    else if (string == NULL)
        return -1;
    else {
        strcpy(new_quizz->question[questionCount].questionText, string);
        return 0;
    }
}

int get_option_text(
        quizz* new_quizz, int questionCount, int optionCount, char* string)
{
    if ((strcmp(string, "next")) == 0)
        return 1;
    else if (string == NULL)
        return -1;
    else {
        strcpy(new_quizz->question[questionCount]
                       .answerOptions[optionCount]
                       .optionText,
               string);
        return 0;
    }
}

int get_is_option_right(
        quizz* new_quizz, int questionCount, int optionCount, int num)
{
    if (num == 1 || num == 0) {
        new_quizz->question[questionCount]
                .answerOptions[optionCount]
                .isAnswerRight
                = num;
        return 0;
    } else
        return -1;
}

quizz* create_quizz()
{
    quizz* new_quizz = malloc(sizeof(*new_quizz));
    int questionCount = 0;
    int optionCount = 1;
    int result = 0;
    int num = 0;
    char* string = malloc(100);
    new_quizz->quizzNumber = amount_of_quizzes() + 1;
    printf("Введите название теста, который хотите создать: ");
    if (input(string, 's') == NULL)
        return NULL;
    result = get_quizz_name(new_quizz, string);
    if (result == -1)
        return NULL;
    else if (result == 1)
        return new_quizz;
    while (1) {
        optionCount = 1;
        printf("Введите вопрос: ");
        if (input(string, 's') == NULL)
            return NULL;
        result = get_question_text(new_quizz, ++questionCount, string);
        if (result == -1)
            return NULL;
        else if (result == 1)
            break;
        new_quizz->question[questionCount].questionNumber = questionCount;
        while (1) {
            printf("Введите текст варианта: ");
            if (input(string, 's') == NULL)
                return NULL;
            result = get_option_text(
                    new_quizz, questionCount, optionCount, string);
            if (result == -1)
                return NULL;
            else if (result == 1)
                break;
            printf("1 или 0: ");
            if (input(&num, 'd') == NULL)
                return NULL;
            result = get_is_option_right(
                    new_quizz, questionCount, optionCount, num);
            if (result == -1)
                return NULL;
            new_quizz->question[questionCount]
                    .answerOptions[optionCount]
                    .optionLetter
                    = optionCount + 64;
            optionCount++;
            getchar();
        }
    }
    free(string);
    return new_quizz;
}
