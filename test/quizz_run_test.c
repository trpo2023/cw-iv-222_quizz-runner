#include <stdlib.h>

#include <lib/quizz_run.h>

#include <ctest.h>

CTEST(get_pass_percentage, сorrect_result)
{
    struct user* users_good = malloc(sizeof(*users_good));
    struct answers* answer_good = malloc(sizeof(*answer_good));
    struct user* users_bad = malloc(sizeof(*users_bad));
    struct answers* answer_bad = malloc(sizeof(*answer_bad));
    answer_good->isCorrect[0] = 1;
    answer_bad->isCorrect[0] = (-100);
    int resultgood = get_pass_percentage(answer_good, users_good, 1);
    int resultbad = get_pass_percentage(answer_bad, users_bad, 1);
    ASSERT_EQUAL(-1, resultbad);
    ASSERT_EQUAL(0, resultgood);
    free(answer_good);
    free(users_good);
    free(answer_bad);
    free(users_bad);
}
CTEST(get_username, correct_name)
{
    struct user* users_good = malloc(sizeof(*users_good));
    struct user* users_bad = malloc(sizeof(*users_bad));
    char* good = "Pavel";
    char* bad = NULL;
    int resultgood = get_username(users_good, good);
    int resultbad = get_username(users_bad, bad);
    ASSERT_EQUAL(-1, resultbad);
    ASSERT_EQUAL(0, resultgood);
    free(users_good);
    free(users_bad);
}
CTEST(quizz_select, сorrect_quizz_num)
{
    struct user* users_good = malloc(sizeof(*users_good));
    struct user* users_bad = malloc(sizeof(*users_bad));
    int good = 10;
    int* bad = NULL;
    int resultgood = quizz_select(users_good, &good);
    int resultbad = quizz_select(users_bad, bad);
    ASSERT_EQUAL(-1, resultbad);
    ASSERT_EQUAL(0, resultgood);
    free(users_good);
    free(users_bad);
}
CTEST(get_answer, not_empty_answer)
{
    struct answers* answer_good = malloc(sizeof(*answer_good));
    struct answers* answer_bad = malloc(sizeof(*answer_bad));
    char* bad = NULL;
    char good = 'A';
    int resultgood = get_answer(answer_good, 0, &good);
    int resultbad = get_answer(answer_bad, 0, bad);
    ASSERT_EQUAL(-1, resultbad);
    ASSERT_EQUAL(0, resultgood);
    free(answer_good);
    free(answer_bad);
}
CTEST(check_answers, correct_answer)
{
    quizz* quiz = malloc(sizeof(*quiz));
    struct answers* answer_good = malloc(sizeof(*answer_good));
    struct answers* answer_bad = malloc(sizeof(*answer_bad));
    struct answers* answer_exit = malloc(sizeof(*answer_exit));
    answer_good->answer[0] = 'A';
    answer_exit->answer[0] = 'q';
    answer_bad->answer[0] = 'P';
    quiz->question[0].answerOptions[0].optionLetter = 'A';
    int resultgood = check_answers(quiz, answer_good, 0, 0);
    int resultexit = check_answers(quiz, answer_exit, 0, 0);
    int resultbad = check_answers(quiz, answer_bad, 0, 0);
    ASSERT_EQUAL(-1, resultbad);
    ASSERT_EQUAL(0, resultgood);
    ASSERT_EQUAL(1, resultexit);
    free(answer_good);
    free(answer_bad);
    free(answer_exit);
}
