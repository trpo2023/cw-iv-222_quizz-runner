#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quize_run.h"
#include "quizz_create.h"

#define MAX_CNT_ANSWERS 10

int get_username(struct user* users){
	printf("Введите ваше имя:\n");
	scanf(" %s",users->username);
	return 0;
}

int quizz_select(struct user* users){
	printf("Введите номер теста:\n");
	if(scanf("%d",&users->quizzNum)!=0)
		return users->quizzNum;
	return -1;
}

int print_answer_options(struct quizz* quiz,int questionCount){
	printf("Вопрос номер %d \n", quiz->question[questionCount].questionNumber+1);
	printf("%s \n",quiz->question[questionCount].questionText);
	for (answerOptions* i =quiz->question[questionCount].answerOptions; i->optionLetter!=0; i++){
		printf("%c) ",(*i).optionLetter);
		printf("%s\n",(*i).optionText);
	}
	return 0;
}

struct answers get_answer(struct answers* results,int optionCount){
	char answ;
	printf("Введите ответ:\n");
	scanf(" %c",&answ);
	results->answer[optionCount]=answ;
	return *results;
}

int check_answers(struct quizz* quiz,struct answers* results,int questionCount,int optionCount){
	for(int i=0;i<MAX_CNT_ANSWERS;i++){	
		if(results->answer[optionCount]==quiz->question[questionCount].answerOptions[i].optionLetter){
			results->isCorrect[optionCount]=quiz->question[questionCount].answerOptions[i].isAnswerRight;
			return 0;
		}
		else
			continue;
	}
	return -1;
}

int get_pass_percentage(struct answers* answer,struct user* users,int questionCount){
	int goodAnswers=0;
	int allQuestion=questionCount;
	for(int i=0; i<100; i++){
		goodAnswers+=answer->isCorrect[i];
	}
	users->passPercentage=goodAnswers*100/allQuestion;
	printf("Ваш результат:%d\n",users->passPercentage);
	return 0;
}
