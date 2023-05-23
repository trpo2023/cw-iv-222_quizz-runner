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
    getchar();
    if (command == 1) {
        quizz* new_quizz;
        new_quizz = create_quizz();
        if (new_quizz != NULL)
            fill_data_with_quizz(new_quizz);
        free(new_quizz);
    } else if (command == 2) {
        struct user* user;
        user = run_quizz();
        if (user != NULL) {
            fill_data_with_user_data(user);
        }
        free(user);
    }
    return 0;
}
