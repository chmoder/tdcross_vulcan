/*File square.c*/
/*Thomas Cross Prog 2*/
/*
   Lots of functions today...
   read main function by function and it should
   make sence.  Dynamicly sized.  Think of the possibilities.
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


int getDim(char *);
char** make2D(int);
void free2D(char **, int);
void moveTemp(char **, char *, int);
void fillSquare(char **, int);
void printSquare(char **, int);
int find(int, int, int, int, int, char **, char *);
void add(int, int, int, int, int, char **, char **, char *);

int main()
{
    char *temp_arr = (char *)malloc(50 * sizeof(char));
    int r, c, rd, cd;
    int dim = getDim(temp_arr);
    char **square = make2D(dim);
    char **answer = make2D(dim);
    moveTemp(square, temp_arr, dim);
    fillSquare(square, dim);
    /*printSquare(square, dim);*/

    temp_arr = (char*)malloc(50 * sizeof(char));
    while((fgets(temp_arr, 50, stdin)) != NULL )
    {
        if(strlen(temp_arr) > 1)
        {
            temp_arr[strlen(temp_arr) - 1] = '\0';
            /*printf("searching for %s\n",temp_arr);*/

            for(r = 0; r < dim; r++)
                for(c = 0; c < dim; c++)
                    for(rd = -1; rd <= 1; rd++)
                        for(cd = -1; cd <= 1; cd++)
                        {
                            if(find(r, c, rd, cd, dim, square, temp_arr))
                            {
                                add(r, c, rd, cd, dim, square, answer, temp_arr);
                                cd = 2;
                                rd = 2;
                                c = dim + 1;
                                r = dim + 1;
                            }
                        }
        }
    }
    free(temp_arr);
    
    printSquare(answer, dim);

    free2D(square, dim);
    free2D(answer, dim);
    return 0;
}

/*
    Function reads the first line and counts the dimentions
    then returns the DIM of the square and keeps the first 
    word in TEMP_ARR for later use.
*/
int getDim(char * temp_arr)
{
    int dim = 0;
    char temp;
    while(scanf("%c", &temp) && temp != '\n')
    {
        if(temp != ' ' && isprint(temp))
        {
            temp_arr[dim++] = temp;
        }
    }
    return dim;
}

/*
   Make colls number of characters + 1 for \0! 
   Returns a pointer to a pointer to characters.
*/
char** make2D(int dim)
{
    int i, j;
    /*Alloc Rows*/
    char **square = (char **)malloc(dim * sizeof(char *));
    /*Alloc Colls*/
    for(i = 0; i < dim; ++i)
    {
        square[i]  = (char *)malloc(dim+1 * sizeof(char));
    }

    for(i = 0; i < dim; ++i)
        for(j = 0; j < dim; ++j)
            square[i][j] = ' ';

    return square;
}

void free2D(char **array, int dim)
{
    int i;
    for(i = 0; i < dim; ++i)
    {
        free(array[i]);
    }
    free(array);
}

/*
   Add null manaully to my strcpy function. 
 */
void moveTemp(char ** square, char * temp_arr, int dim)
{
    int i = 0;
    for(i = 0; i < dim; ++i)
    {
        square[0][i] = temp_arr[i];
    }
    square[0][i] = '\0';
    free(temp_arr);
}

/*
   Fill up the square.  Add nulls and copy words from stdin
   to our array 
*/
void fillSquare(char **square, int dim)
{
    char *temp_arr = (char *)malloc(dim+1 * sizeof(char));

    int i = 0;
    int e = 1;
    char temp;
        /*//while((temp = getchar()) != EOF && (char)temp != '\0')*/
    while(e < dim && scanf("%c", &temp))
    {
        /*//printf("%c ", temp);*/
        if(temp != ' ' && isprint(temp))
        {
            temp_arr[i++] = temp;
        }
        else if(temp == '\n')
        {
            temp_arr[i] = '\0';
            strcpy(square[e++], temp_arr);
            i = 0;
        }
        /*//temp = getchar();*/
    }
    free(temp_arr);
}
/*
   printSquare prints a 2d character array formated specificly
   for this assignment.
*/
void printSquare(char ** square, int dim)
{
    int i, j;
    for(j = 0; j < dim; ++j)
    {
        for(i = 0; i < dim; ++i)
        {
            printf(" %c ", square[j][i]);
        }
        printf("\n");
    }
}

/*
    Function find finds a WORD in SQUARE given its DIM and current location
    and collumn offset. 
*/
int find(int r, int c, int rd, int cd, int dim, char **square, char *word)
{
    int i = 0;
    int retval = 0;
    char *temp_word = (char *)malloc((dim + 51) * sizeof(char *));

    if((rd || cd ) && square[r][c] == word[i])
    {
        while(r < dim && c < dim && r >= 0 && c >= 0 && i < strlen(word))
        {
            /*printf("r= %d c= %d rd= %d cd= %d letter= %c\n", r, c, rd, cd, square[r][c]);*/
            if(square[r][c] == word[i])
            {
                temp_word[i++] = square[r][c];
            }
            else
            {
                 free(temp_word);
                return 0;
            }

            r += rd;
            c += cd;
        }


        temp_word[i] = '\0';
        if(!strcmp(temp_word, word))
        {
            retval = 1;
            /*printf("ding! %s  %s\n", temp_word, word);*/
        }
    }
    free(temp_word);
    return retval; 
}

/*
    VOID function add is just like find except it knows where its going.
    add will add a word to an answer array which will later be printed to
    the screen. 
*/
void add(int r, int c, int rd, int cd, int dim, char **square, char **answer, char *word)
{
    int i;
    for(i = 0; i < strlen(word); ++i)
    {
        answer[r][c] = square[r][c];
        r += rd;
        c += cd;
    }
}
