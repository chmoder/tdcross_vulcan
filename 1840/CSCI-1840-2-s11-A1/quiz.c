/*
    Thomas Cross
    Quiz program is a little math quiz program using random numbers.
    Please use make to make my program.  I have ~150 lines of functions
    Please see functions.h for more comments
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"functions.h"

/*
    Main
        1)seeds rand
        2)repeatedly asks for numb questions and difficulty till 
        they meet the criteria.
        3)asks the questions and in one line does all the work
        4)finally prints your score totaled using a ternary, Chicka Chicka Yea.
*/
int main()
{
    int i, numb_questions, difficulty;
    int total_correct = 0;
    srand(time(NULL));

    while(numb_questions > 21 || numb_questions < 1 || difficulty > 21 || difficulty < 1)
    {
        printf("How many questions for this test(1 - 20)? ");
        scanf("%d", &numb_questions);
        printf("Select difficulty (1 - 4): ");
        scanf("%d", &difficulty);
    }
    
    for(i = 0; i < numb_questions; ++i)
    {
        (response(answerQuestion(genQuestion(difficulty, i+1))) ? ++total_correct:1);
    }
    printf("Your score was %d/%d\n", total_correct, numb_questions);

    return 0;
}
