#include <stdlib.h>

#include <ctest.h>
#include <lib/quizz_create.h>

CTEST(get_quizz_name, quizz_name)
{
    quizz* new_quizz = malloc(sizeof(*new_quizz));
    char* quit = "quit";
    char* access = "name";
    int return1 = get_quizz_name(new_quizz, quit);
    int return2 = get_quizz_name(new_quizz, access);
    ASSERT_EQUAL(1, return1);
    ASSERT_EQUAL(0, return2);
    free(new_quizz);
}

CTEST(get_question_text, question_text)
{
    quizz* new_quizz = malloc(sizeof(*new_quizz));
    char* quit = "quit";
    char* access = "name";
    int return1 = get_question_text(new_quizz, 1, quit);
    int return2 = get_question_text(new_quizz, 1, access);
    ASSERT_EQUAL(1, return1);
    ASSERT_EQUAL(0, return2);
    free(new_quizz);
}

CTEST(get_option_text, option_text)
{
    quizz* new_quizz = malloc(sizeof(*new_quizz));
    char* quit = "next";
    char* access = "name";
    int return1 = get_option_text(new_quizz, 1, 1, quit);
    int return2 = get_option_text(new_quizz, 1, 1, access);
    ASSERT_EQUAL(1, return1);
    ASSERT_EQUAL(0, return2);
    free(new_quizz);
}

CTEST(get_is_option_right, is_option_right)
{
    quizz* new_quizz = malloc(sizeof(*new_quizz));
    int access1 = 1;
    int access2 = 0;
    int error = 2;
    int return1 = get_is_option_right(new_quizz, 1, 1, access1);
    int return2 = get_is_option_right(new_quizz, 1, 1, access2);
    int return3 = get_is_option_right(new_quizz, 1, 1, error);
    ASSERT_EQUAL(0, return1);
    ASSERT_EQUAL(0, return2);
    ASSERT_EQUAL(-1, return3);
    free(new_quizz);
}
