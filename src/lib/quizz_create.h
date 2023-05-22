#pragma once

struct answerOptions {
    char optionLetter;
    char optionText[100];
    int isAnswerRight;
};
typedef struct answerOptions answerOptions;

struct question {
    int questionNumber;
    char questionText[100];
    answerOptions answerOptions[10];
};
typedef struct question question;

struct quizz {
    int quizzNumber;
    char quizzName[100];
    question question[100];
};
typedef struct quizz quizz;

void delete_new_string(char** string);

int get_quizz_name(quizz* new_quizz, char* string);

int get_question_text(quizz* new_quizz, int questionCount, char* string);

int get_option_text(
        quizz* new_quizz, int questionCount, int optionCount, char* string);

int get_is_option_right(
        quizz* new_quizz, int questionCount, int optionCount, int num);

quizz* create_quizz();