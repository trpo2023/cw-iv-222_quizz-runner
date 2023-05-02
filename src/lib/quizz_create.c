#include <stdio.h>
#include <stdlib.h>

#include <lib/quizz_create.h>

int is_quit()
{
    printf("Заверишить ввод?\n");
    char c;
    scanf(" %c", &c);
    if (c == 'y')
        return 1;
    else
        return 0;
}

int get_quizz_name(quizz* new_quizz, int questionCount)
{
    printf("Введите название теста, который хотите создать:\n");
    if (scanf(" %s", new_quizz->quizzName) != 0)
        return 0;
    else
        return -1;
}

int get_question_text(quizz* new_quizz, int questionCount)
{
    printf("Введите вопрос:\n");
    if (scanf(" %s", new_quizz->question[questionCount].questionText) != 0)
        return 0;
    else
        return -1;
}

int get_option_letter(quizz* new_quizz, int questionCount, int optionCount)
{
    printf("Введите букву варианта ответа:\n");
    if (scanf(" %c",
              &new_quizz->question[questionCount]
                       .answerOptions[optionCount]
                       .optionLetter)
        != 0)
        return 0;
    else
        return -1;
}

int get_option_text(quizz* new_quizz, int questionCount, int optionCount)
{
    printf("Введите текст варианта:\n");
    if (scanf(" %s",
              new_quizz->question[questionCount]
                      .answerOptions[optionCount]
                      .optionText)
        != 0)
        return 0;
    else
        return -1;
}

int get_is_option_right(quizz* new_quizz, int questionCount, int optionCount)
{
    printf("1 или 0:\n");
    if (scanf(" %d",
              &new_quizz->question[questionCount]
                       .answerOptions[optionCount]
                       .isAnswerRight)
        != 0)
        return 0;
    else
        return -1;
}

quizz* create_quizz()
{
    quizz* new_quizz = malloc(sizeof(*new_quizz));
    int questionCount = 0;
    int optionCount = 0;
    get_quizz_name(new_quizz, questionCount);
    while (1) {
        get_question_text(new_quizz, questionCount);
        while (1) {
            get_option_letter(new_quizz, questionCount, optionCount);
            get_option_text(new_quizz, questionCount, optionCount);
            get_is_option_right(new_quizz, questionCount, optionCount);
            if (is_quit())
                return new_quizz;
        }
    }
    return new_quizz;
}
