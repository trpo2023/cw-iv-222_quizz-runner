#pragma once

int amount_of_quizzes();

struct quizz* get_quizz(int qNumber);

int fill_data_with_quizz(struct quizz* q);

struct user* get_user_data(char *userName, int quizzNum);

int fill_data_with_user_data(struct user *user);

char replace_with_spaces(char* str);

char replace_with_underline(char* str);
