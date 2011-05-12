/*
    Thomas Cross
    Functions for quiz.c
*/

/*
    Prototypes for my 3 functions taking 
    const for optimization 
*/
int genQuestion(const int, const int);
int answerQuestion(const int);
int response(const int);

/*
    genQuestion:
        1)takes the difficutly and question number 
        prints the question and returns the answer
        in quiz.c this answer is passed to answerQuestion().
        2)based on difficulty picks 2 random operands
        3)a random operation number is picked and 
        the math is done and answer is returned to answerQuestion
*/
int genQuestion(const int difficulty, const int q_numb)
{
    int left, right, operation, retval;

    operation = rand() % 4 + 1;

    switch(difficulty)
    {
        case 1:
        {
            left = rand() % 10 + 1;
            right = rand() % 10 + 1;
            break;
        }
        case 2:
        {
            left = rand() % 50 + 1;
            right = rand() % 50 + 1;
            break;
        }
        case 3:
        {
            left = rand() % 100 + 1;
            right = rand() % 100 + 1;
            break;
        }
        case 4:
        {
            left = rand() % 100*2 - 100;
            right = rand() % 100*2 - 100;
            break;
        }
    }

    switch (operation)
    {
        case 1:
        {
            retval = (left + right);
            printf("Question %d: %d + %d = \n", q_numb, left, right);
            break;
        }
        case 2:
        {
            retval = (left - right);
            printf("Question %d: %d - %d = \n", q_numb, left, right);
            break;
        }
        case 3:
        {
            retval = (left * right);
            printf("Question %d: %d * %d = \n", q_numb, left, right);
            break;
        }
        case 4:
        {
            retval = (left / right); 
            printf("Question %d: %d / %d = \n", q_numb, left, right);
            break;
        }
    }

    return retval;
}

/*
    if(user_answer == answer) is (user_answer - answer)
    so check it out!  I hope this is not a stupid 
    thing to do.
    1)asks user for answer and takes it and if diff == 0 
    then return 1 or 0 to response
*/
int answerQuestion(const int answer)
{
    int user_answer, retval;
    
    printf("Enter Answer: ");
    scanf("%d", &user_answer);

    if(!(user_answer - answer)) 
        retval = 1;
    else
        retval = 0;

    return retval;
}

/*
    1)Meritorious means with merit.  Deserving reward or praise
    I am using it interrogitively if it deserves a response
    with merrit then randomly spit out a nice response. 
    2)else spit out a non good response.
    Naughty naughty coolaid.  Not cool man.
    3)Return meritorius becuase i have a ternery
    in quz.c that checks if it is true or false to count
    correct responces.
*/
int response(const int meritorious)
{
    int response_number = rand() % 3 + 1;
    if(meritorious)
    {
        switch(response_number)
        {
            case 1:
            {
                printf("You are soooo right!\n");
                break;
            }
            case 2:
            {
                printf("Good job.  Keep going!\n");
                break;
            }
            case 3:
            {
                printf("500 Gold Stars for you!\n");
                break;
            }
            case 4:
            {
                printf("Wrong.  Just kidding :)\n");
                break;
            }
        }
    }
    else
    {
        switch(response_number)
        {
            case 1:
            {
                printf("Incorrectomondo!\n");
                break;
            }
            case 2:
            {
                printf("Wrong number.\n");
                break;
            }
            case 3:
            {
                printf("Counterfactual.\n");
                break;
            }
            case 4:
            {
                printf("Way off.\n");
                break;
            }
        }
    }
    return meritorious;
}
