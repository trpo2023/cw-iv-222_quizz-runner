#include <stdio.h>
#include <stdlib.h>

#include <lib/quizz_create.h>
#include <lib/quizz_data.h>
#include <lib/quizz_run.h>

int main()
{
    printf("Доступные команды:\n1 - Создать новый тест\n2 - Пройти тест\n");
    int command;
    scanf("%d", &command);
    if (command == 1) {
        quizz* new_quizz = malloc(sizeof(*new_quizz));
        new_quizz = create_quizz();
        fill_data_with_quizz(new_quizz);
    } else if (command == 2) {
        struct user* user = malloc(sizeof(*user));
        get_username(user);
        quizz_select(user);
        quizz* new_quizz = malloc(sizeof(*new_quizz));
        new_quizz = get_quiz(user->quizzNum);
    }
    return 0;
}