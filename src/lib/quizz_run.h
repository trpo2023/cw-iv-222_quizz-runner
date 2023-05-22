#pragma once

#include <lib/quizz_create.h>

struct user {
    char username[100];
    int quizzNum;
    int passPercentage;
};

struct answers {
    char answer[100];
    int isCorrect[100];
};

int get_username(struct user* users,char* argument);
int quizz_select(struct user* users,int* argument);
int get_pass_percentage(
        struct answers* answer, struct user* users, int questionCount);
void print_answer_options(struct quizz* quiz, int questionCount);
int get_answer(struct answers* results, int optionCount,char* ch);
int check_answers(
        struct quizz* quiz,
        struct answers* results,
        int questionCount,
        int optionCount);
struct user*
run_quizz();
