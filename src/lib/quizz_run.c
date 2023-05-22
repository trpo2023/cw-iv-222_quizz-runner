#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib/quizz_create.h>
#include <lib/quizz_data.h>
#include <lib/quizz_run.h>

#define MAX_CNT_ANSWERS 10

int get_username(struct user* users, char* argument)
{
    if (argument == NULL)
        return -1;
    strcpy(users->username, argument);
    return 0;
}

int quizz_select(struct user* users, int* argument)
{
    if (argument == NULL)
        return 0;
    users->quizzNum = *argument;
    return -1;
}

void print_answer_options(struct quizz* quiz, int questionCount)
{
    for (answerOptions* i = quiz->question[questionCount].answerOptions;
         i->optionLetter != 0;
         i++) {
        printf("%c) ", (*i).optionLetter);
        printf("%s\n", (*i).optionText);
    }
}

int get_answer(struct answers* results, int optionCount, char* ch)
{
    if (ch == NULL)
        return -1;
    results->answer[optionCount] = *ch;
    return 0;
}

int check_answers(
        struct quizz* quiz,
        struct answers* results,
        int questionCount,
        int optionCount)
{
    if (results->answer[optionCount] == 'q')
        return 1;
    for (int i = 0; i < MAX_CNT_ANSWERS; i++) {
        if (results->answer[optionCount]
            == quiz->question[questionCount].answerOptions[i].optionLetter) {
            results->isCorrect[optionCount] = quiz->question[questionCount]
                                                      .answerOptions[i]
                                                      .isAnswerRight;
            return 0;
        } else
            continue;
    }
    return -1;
}

int get_pass_percentage(
        struct answers* answer, struct user* users, int questionCount)
{
    int goodAnswers = 0;
    int allQuestion = questionCount;
    for (int i = 0; i < 100; i++) {
        goodAnswers += answer->isCorrect[i];
    }
    users->passPercentage = goodAnswers * 100 / allQuestion;
    if (users->passPercentage >= 0 || users->passPercentage <= 100)
        return 0;
    return -1;
}

struct user* run_quizz()
{
    struct user* users = malloc(sizeof(*users));
    struct answers* answer = malloc(sizeof(*answer));
    quizz* quiz;
    int num = 0;
    char ch;
    char* string = malloc(100);
    int questionCount = 0;
    int optionCount = 0;
    printf("Введите ваше имя:\n");
    if (input(string, 's') == NULL) {
        printf("Не коректный ввод имени пользователя");
        return NULL;
    }
    get_username(users, string);
    printf("Введите номер теста:\n");
    if (input(&num, 'd') == NULL) {
        printf("Не коректный ввод номера текста");
        return NULL;
        ;
    }
    quizz_select(users, &num);
    quiz = get_quizz(users->quizzNum);
    for (question* i = quiz->question; i->questionText[0] != 0; i++) {
        printf("Вопрос номер %d \n",
               quiz->question[questionCount].questionNumber);
        printf("%s \n", quiz->question[questionCount].questionText);
        print_answer_options(quiz, questionCount);
        printf("Введите вариант ответа(Ответ должен быть введён с большой "
               "буквы английского алфавита. Если вы хотите завершить тест "
               "досрочно напишите q):\n");
        if (input(&ch, 'c') == NULL) {
            printf("Не коректный ввод варианта ответа");
            return NULL;
        }
        get_answer(answer, optionCount, &ch);
        if (check_answers(quiz, answer, questionCount, optionCount) == -1) {
            printf("В базе данных нет такого варианта ответа\n");
            return NULL;
        } else if (
                check_answers(quiz, answer, questionCount, optionCount) == 1) {
            printf("Завершение теста\n");
            return NULL;
        }
        optionCount++;
        questionCount++;
    }
    if (get_pass_percentage(answer, users, questionCount) == 0)
        printf("Ваш результат: %d из 100\n", users->passPercentage);
    else
        printf("Ошибка при подсчёте результата");
    free(string);
    free(answer);
    free(quiz);
    return users;
}
