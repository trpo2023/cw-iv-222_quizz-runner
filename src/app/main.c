#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        new_quizz->quizzNumber = amount_of_quizzes() + 1;
        fill_data_with_quizz(new_quizz);
    } else if (command == 2) {
        struct user* user = malloc(sizeof(*user));
        struct answers* answ = malloc(sizeof(*answ));
        quizz* new_quizz = malloc(sizeof(*new_quizz));
        run_quizz(answ, user, new_quizz);
    }
    return 0;
}
