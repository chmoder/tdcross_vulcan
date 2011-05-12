/*
    Thomas Cross
    Sorry everyone, I didn't know that strtok mutilates the string
    after using it.  So this is pretty ugly code now. 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printFormatted(int, char *, char *);
void printWordCount(char *, int, FILE *, char *);
void printWordArray(char **, int, char *);
int strCmp(const void *, const void *);
int getWordCount(char *);
char **makeWordList(char *, int, FILE *, int);

int main(int argc, char **argv)
{
    FILE *fp_infile;
    int file_size, cols = 0;
    char *fname, *ptr, *file_string;
    if(argc == 3)
    {
        cols = atoi(argv[1]);
        fname = argv[2];
    }
    else
    {
        fprintf(stderr, "Usage: %s colls inputfile.\n", argv[0]);
        exit(1);
    }
    if(cols < 25 || cols > 100)
    {
        fprintf(stderr, "Column width must be at least 25 and at most 100\n");
        exit(1);
    }

    fp_infile = fopen(fname, "r");
    fseek(fp_infile, 0, SEEK_END);
    file_size = ftell(fp_infile);
    file_string = (char *)calloc(file_size + 1, sizeof(char));
    /*fseek(fp_infile, 0, SEEK_SET);*/
    rewind(fp_infile);
    fread(file_string, sizeof(char), file_size, fp_infile);
    while((ptr = strchr(file_string, '\n')) != NULL)
    {
        *(ptr) = ' ';
    }
    
    printFormatted(cols, file_string, fname);
    
    rewind(fp_infile);
    fread(file_string, sizeof(char), file_size, fp_infile);
    printWordCount(file_string, file_size, fp_infile, fname);

    free(file_string);
    fclose(fp_infile);
    return 0;
}


/*
   compair two void pointers and return the difference
*/
int strCmp(const void *lhs, const void *rhs)
{ 
    const char **new_lhs = (const char **)lhs;
    const char **new_rhs = (const char **)rhs;
    return strcmp(*new_lhs, *new_rhs);
}

/*
    extra bytes for appending fname.words.
    Prints to the proper file the words in sorted order and the count per word
    Uses one sorted array and a little thought for counting occurrences.
*/
void printWordArray(char **word_array, int total_words, char *fname)
{
    int i, count = 0;
    char *fname_words = calloc(1, sizeof(fname)+5);
    FILE *fp_words;
    strcpy(fname_words, fname);
    strcat(fname_words, ".words");
    fp_words = fopen(fname_words, "w");

    for(i = 0; i < total_words - 1; ++i)
    {
        if(strcmp(word_array[i], word_array[i+1]) == 0)
        {
            ++count;
            while(strcmp(word_array[i], word_array[i+1]) == 0)
            {
                ++count;
                ++i;
            }
            fprintf(fp_words, "%s - %d\n", word_array[i], count);
            ++i;
            count = 0;
        }
        else
            fprintf(fp_words, "%s - %d\n", word_array[i], 1);
    }
    fclose(fp_words);
    free(fname_words);
}

/*
    Acutally calls getWordCount, makeWordList, then finally sends the sorted
    words to printWordArray.
*/
void printWordCount(char *file_string, int file_size, FILE *fp_infile, char *fname)
{
    char **word_array;
    int total_words = getWordCount(file_string);
    rewind(fp_infile);
    fread(file_string, sizeof(char), file_size, fp_infile);

    word_array = makeWordList(file_string, file_size, fp_infile, total_words);
    qsort(word_array, total_words, sizeof(char *), strCmp);
    printWordArray(word_array, total_words, fname);
    
    free(word_array);
}

/*
    Apparently strtok frees its own words somehow.  I should ask
    Dr. Mahoney about that...
    makeWordList uses realloc to dynamically grow an array to of words 
    from our word string generated in previous callers and passed here. 
*/
char **makeWordList(char *file_string, int file_size, FILE *fp_infile, int total_words)
{
    char *word;
    char **wordlist = NULL;
    int numwords = 0;
    word = strtok(file_string, " \n");
    while(word != NULL)
    {
        wordlist = realloc( wordlist, (numwords + 1) * sizeof( char * ) );
        wordlist[ numwords ] = word ;
        numwords++;
        word = strtok(NULL, " \n");
    }
    return wordlist;
}

/*
    Simply gets and returns the number of words in our file(string). 
*/
int getWordCount(char *file_string)
{
    char *word;
    int counter = 0;
    word = strtok(file_string, " ");
    while(word != NULL)
    {
        ++counter;
        word = strtok(NULL, " ");
    }
    return counter;
}

/*
    This function prints out our input to the proper file given a
    number of columns via command line argument.
*/
void printFormatted(int cols, char *file_string, char *fname)
{
    char *word;
    int counter = 0;
    char *fname_out = calloc(1, sizeof(fname)+4);
    FILE *fp_out;
    strcpy(fname_out, fname);
    strcat(fname_out, ".out");
    fp_out = fopen(fname_out, "w");
    word = strtok(file_string, " ");
    while(word != NULL)
    {
        if((counter += strlen(word) + 1) <= cols)
        {
            fprintf(fp_out, "%s ", word);
        }
        else
        {
            counter = 0;
            fprintf(fp_out, "\n%s ", word);
            counter += strlen(word) + 1;
        }
        word = strtok(NULL, " ");
    }
    fprintf(fp_out, "\n");
    fclose(fp_out);
    free(fname_out);
}
