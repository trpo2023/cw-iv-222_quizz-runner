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

quizz* create_quizz();

int is_quit();

int get_quizz_name(quizz* new_quizz, int questionCount);

int get_question_text(quizz* new_quizz, int questionCount);

int get_option_letter(quizz* new_quizz, int questionCount, int optionCount);

int get_option_text(quizz* new_quizz, int questionCount, int optionCount);

int get_is_option_right(quizz* new_quizz, int questionCount, int optionCount);