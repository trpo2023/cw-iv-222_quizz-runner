#pragma once

#include "quizz_create.h"

struct user{
	char username[100];
	int quizzNum;
	int passPercentage;
};


struct answers{
	char answer[100];
	int isCorrect[100];	
};


int get_username(struct user* users);
int quizz_select(struct user* users);
int get_pass_percentage(struct answers* answer,struct user* users,int questionCount);
int print_answer_options(struct quizz* quiz,int questionCount);
struct answers get_answer(struct answers* results,int optionCount);
int check_answers(struct quizz* quiz,struct answers* results,int questionCount,int optionCount);
