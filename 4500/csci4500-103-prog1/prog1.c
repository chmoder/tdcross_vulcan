/*File prog1.c*/
/*Thomas Cross*/
/*csci4500 shell*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


#define MAXLINELEN 100

extern char **environ;			/* pointer to array of pointers */
char line[MAXLINELEN+1];	/* 1 extra byte for the null terminator */

/*-------------------------------------------------------*/
/* Read an input line, or at most MAXLINELEN characters. */
/* Discard the end of line character.                    */
/* The input line is placed in the 'line' array, and has */
/* the appropriate null terminator added.                */
/* Return 0 at end of file, or non-zero otherwise.       */
/*-------------------------------------------------------*/
int
getline2(void)
{
    static char last = '\0';		/* saved 101st character, if non-zero */
    int len;				/* line length */
    int n;				/* return value from read */
    char c;				/* character just read */

    len = 0;

    /*--------------------------------------------------------------------*/
    /* If the last invocation of getline2 terminated because the line was  */
    /* longer than 100 characters, the 101st character was saved in last. */
    /* Otherwise (if the last invocation found a legitimate end of line), */
    /* then last is ;\0'. If last isn't '\0' here -- at the beginning of  */
    /* the next invocation -- we use it as the first character of the     */
    /* next part of the line. Observe that last is declared as a static   */
    /* variable, so its value is preserved across multiple invocations.   */
    /*--------------------------------------------------------------------*/
    if (last != '\0') 
    {
	    line[0] = last;
	    len = 1;
    }
    for(;;) 
    {
	    n = read(0,&c,1);
	    if (n == 0)			/* check for end of file */
	        return 0;
	    if (c == '\n') 
        {		/* check for end of line */
	        line[len] = '\0';		    /* add the null terminating byte */
	        last = '\0';		    /* we didn't save anything */
	        return 1;			    /* return a non-zero value */
	    }
	    if (len == MAXLINELEN) 	/* check for maximum line length */
        {
	        line[len] = '\0';		    /* add the null terminating byte */
	        last = c;			    /* save the 101st character */
	        return 1;			    /* return a non-zero value */
	    }
	    line[len] = c;			/* save the character */
	    len++;				/* increase the length */
    }					/* and repeat... */
}

int inPath(char * full_path, char * command)
{
    int retval = 0;
    char *the_path;			/* pointer to string with PATH env. var. */
    char *dir;			/* pointer to string with a single dir name */
    char *saveptr = calloc(0,sizeof(char));
    char * dir_and_cmd = calloc(1024 , sizeof(char));
    int status = 1;

    the_path = getenv("PATH");	/* get value of PATH environment variable */
    char *path = calloc(strlen(the_path), sizeof(char));
    strcpy(path, the_path);

    dir = strtok(path,":");	/* get first entry */
    while (dir != NULL && status != 0) 	/* if we found an entry... */
    {
        strcpy(dir_and_cmd, dir);                   /* new dir */
        strcat(dir_and_cmd, "/");                   /* dir + "/" */
        strcat(dir_and_cmd, command);               /* dir + "/" + cmd */
        status = access(dir_and_cmd, X_OK);         /* get status */
        if(status == 0)
        {
            retval = 1;
            strcpy(full_path, dir_and_cmd);     /*write the full path same as one in main*/
        }
	    dir = strtok(NULL,":");	    /* and get the next entry */
    }
    
    free(dir_and_cmd);
    free(path);
    return(retval);

}

int isFullPath(char * command)
{
    int retval = 0;

    int status = access(command, X_OK);
    
    if(status == 0)
    {
        retval = 1;
    }
    
    return retval;
}

int inCwd(char * full_path, char * command)
{
    size_t size = 1024;
    int retval = 0;
    int status = 1;

    getcwd(full_path, 1024);
    strcat(full_path, "/");
    strcat(full_path, command);
    status = access(full_path, X_OK);
    if(status == 0)
    {
        retval = 1;
    }
    return retval;
}

int
main(void)
{
    int do_prompt;		/* non-zero if we want to display a prompt */
    char *p;			/* pointer to a word in the input line */
    char args_orig[17][1024]; /* array of arguments for execution */
    char args[17][1024]; /* array of arguments for execution */
    int arg_numb = 0;   /* number of arguments for array */

    do_prompt = isatty(0);	/* is file descriptor 0 a terminal? */

    for(;;) 
    {
        arg_numb = 0;
	    if (do_prompt)			/* display a prompt on a terminal */
	        write(1, "$ ", 2);
	    if (getline2() == 0)		/* get a line (or part of one) */
	        exit(0);			/* and terminate at end of file */
	    if (!do_prompt)        /* if reading from a file... */
        {
	        write(1,line,strlen(line));	    /* display the line */
	        write(1,"\n",1);
	    }

	/*---------------------------------------------------------*/
	/* Now we'll extract words separated by whitespace (blanks */
	/* or tabs) and display each one indented four columns.    */
	/*---------------------------------------------------------*/
	    p = strtok(line," \t");		/* find the first word */
	    while (p != NULL) 
        {
            strcpy(args_orig[arg_numb++], p);
            //write(1,args[arg_numb], strlen(args[arg_numb]));
	        //write(1,"\n",1);		/* and the end of line */

	        //write(1,"    ",4);		/* indentation */
	        //write(1,p,strlen(p));	/* the word itself */
	        //write(1,"\n",1);		/* and the end of line */
	        p = strtok(NULL," \t");	/* find next word, if any */
	    }
            strcpy(args_orig[arg_numb++], "\n");


        int total_args = arg_numb;
        arg_numb = 0;
        int i;
        int my_exit_status = 0;
        for(i = 0; i < total_args; ++i)
        {
            strcpy(args[arg_numb++], args_orig[i]);

            if(*args_orig[i] == ';')
            {
                char * full_path = malloc(1024 * sizeof(char));
                char * temp_cmd = malloc(strlen(args[0])+1 * sizeof(char));

                strcpy(temp_cmd, args[0]);

                if(inCwd(full_path, temp_cmd))
                {
                    strcpy(args[0], full_path);
                }
                else if(isFullPath(temp_cmd))
                {
                    strcpy(args[0], temp_cmd);
                }
                else if(inPath(full_path, temp_cmd))
                {
                    pid_t cpid;			/* child's PID */
                    pid_t status;		/* waitpid's return value */
                    int child_status;		/* child's exit status */

                    strcpy(args[0], full_path);

    
                    int j;
                    //printf("arg_num= %d\n", arg_numb);
                    char *real_args[arg_numb - 2];
                    for(j = 0; j < arg_numb; ++j)
                    {
                        real_args[j] = args[j];
                    }
                    real_args[arg_numb - 1] = '\0';
                    for(j = 0; j < arg_numb; ++j)
                    {
                        //printf("arg[%d]= %s\n", j, real_args[j]);
                    }

                    //execve(args[0],args,environ);

                    if ((cpid = fork()) == 0) 
                    {
                        //execvp(real_args[0], real_args+1);
                        execve(real_args[0],real_args,environ);
                        perror("execvp");
                        exit(2);
                    }
                    if (cpid == -1) 
                    {
                        perror("fork");
                        exit(3);
                    }
                    status = waitpid(cpid, &child_status, 0);
                    if (status == -1) 
                    {
                        perror("waitpid");
                        exit(4);
                    }
                    if (WIFEXITED(child_status)) 
                    {
                        //printf("Child process exited with status %d\n",
                        //        WEXITSTATUS(child_status));
                    } else 
                    {
                        printf("Child process did not exit normally.\n");
                    }
                }


                free(full_path);
                free(temp_cmd);
                arg_numb = 0;
            }
            else if(!strcmp(args_orig[i], "||"))
            {
                char * full_path = malloc(1024 * sizeof(char));
                char * temp_cmd = malloc(strlen(args[0])+1 * sizeof(char));

                strcpy(temp_cmd, args[0]);

                if(inCwd(full_path, temp_cmd))
                {
                    strcpy(args[0], full_path);
                }
                else if(isFullPath(temp_cmd))
                {
                    strcpy(args[0], temp_cmd);
                }
                else if(inPath(full_path, temp_cmd))
                {

                    pid_t cpid;			/* child's PID */
                    pid_t status;		/* waitpid's return value */
                    int child_status;		/* child's exit status */

                    strcpy(args[0], full_path);

    
                    int j;
                    //printf("arg_num= %d\n", arg_numb);
                    char *real_args[arg_numb - 2];
                    for(j = 0; j < arg_numb; ++j)
                    {
                        real_args[j] = args[j];
                    }
                    real_args[arg_numb - 1] = '\0';
                    for(j = 0; j < arg_numb; ++j)
                    {
                        //printf("arg[%d]= %s\n", j, real_args[j]);
                    }

                    //execve(args[0],args,environ);

                    if ((cpid = fork()) == 0) 
                    {
                        //execvp(real_args[0], real_args+1);
                        execve(real_args[0],real_args,environ);
                        perror("execvp");
                        exit(2);
                    }
                    if (cpid == -1) 
                    {
                        perror("fork");
                        exit(3);
                    }
                    status = waitpid(cpid, &child_status, 0);
                    if (status == -1) 
                    {
                        perror("waitpid");
                        exit(4);
                    }
                    if (WIFEXITED(child_status)) 
                    {
                        //printf("Child process exited with status %d\n",
                        //        WEXITSTATUS(child_status));
                    } else 
                    {
                        printf("Child process did not exit normally.\n");
                    }


                    if(child_status == 0)
                    {
                        int goback = 0;
                        while((strcmp(args_orig[i],";") && strcmp(args_orig[i],"&&") && strcmp(args_orig[i],"\n")))
                        {
                            if(strcmp(args_orig[i],"||"))
                            {
                                goback = 0;
                            }
                            ++i;
                            ++goback;
                            //printf("kill_command= %s\n", args_orig[i]);
                        }

                        if(!(strcmp(args_orig[i],";") || strcmp(args_orig[i],"&&") || strcmp(args_orig[i],"\n")))
                        {
                            i -= goback;
                        }

                    }
                }


                free(full_path);
                free(temp_cmd);
                arg_numb = 0;
            }
            else if(!strcmp(args_orig[i], "&&"))
            {
                char * full_path = malloc(1024 * sizeof(char));
                char * temp_cmd = malloc(strlen(args[0])+1 * sizeof(char));

                strcpy(temp_cmd, args[0]);

                if(inCwd(full_path, temp_cmd))
                {
                    strcpy(args[0], full_path);
                }
                else if(isFullPath(temp_cmd))
                {
                    strcpy(args[0], temp_cmd);
                }
                else if(inPath(full_path, temp_cmd))
                {

                    pid_t cpid;			/* child's PID */
                    pid_t status;		/* waitpid's return value */
                    int child_status;		/* child's exit status */

                    strcpy(args[0], full_path);

    
                    int j;
                    //printf("arg_num= %d\n", arg_numb);
                    char *real_args[arg_numb - 2];
                    for(j = 0; j < arg_numb; ++j)
                    {
                        real_args[j] = args[j];
                    }
                    real_args[arg_numb - 1] = '\0';
                    for(j = 0; j < arg_numb; ++j)
                    {
                        //printf("arg[%d]= %s\n", j, real_args[j]);
                    }

                    //execve(args[0],args,environ);

                    if ((cpid = fork()) == 0) 
                    {
                        //execvp(real_args[0], real_args+1);
                        execve(real_args[0],real_args,environ);
                        perror("execvp");
                        exit(2);
                    }
                    if (cpid == -1) 
                    {
                        perror("fork");
                        exit(3);
                    }
                    status = waitpid(cpid, &child_status, 0);
                    if (status == -1) 
                    {
                        perror("waitpid");
                        exit(4);
                    }
                    if (WIFEXITED(child_status)) 
                    {
                        //printf("Child process exited with status %d\n",
                        //        WEXITSTATUS(child_status));
                    } else 
                    {
                        printf("Child process did not exit normally.\n");
                    }


                    if(child_status != 0)
                    {
                        while(!(strcmp(args_orig[i],";") && strcmp(args_orig[i],"||") && strcmp(args_orig[i],"&&") && strcmp(args_orig[i],"\n")))
                        {
                            //printf("kill_command= %s\n", args_orig[i]);
                            ++i;
                        }
                    }
                }


                free(full_path);
                free(temp_cmd);
                arg_numb = 0;
            }
            else if(*args_orig[i] == '\n')
            {
                char * full_path = malloc(1024 * sizeof(char));
                char * temp_cmd = malloc(strlen(args[0])+1 * sizeof(char));

                strcpy(temp_cmd, args[0]);

                if(inCwd(full_path, temp_cmd))
                {
                    strcpy(args[0], full_path);
                }
                else if(isFullPath(temp_cmd))
                {
                    strcpy(args[0], temp_cmd);
                }
                else if(inPath(full_path, temp_cmd))
                {

                    pid_t cpid;			/* child's PID */
                    pid_t status;		/* waitpid's return value */
                    int child_status;		/* child's exit status */

                    strcpy(args[0], full_path);

    
                    int j;
                    //printf("arg_num= %d\n", arg_numb);
                    char *real_args[arg_numb - 2];
                    for(j = 0; j < arg_numb; ++j)
                    {
                        real_args[j] = args[j];
                    }
                    real_args[arg_numb - 1] = '\0';
                    for(j = 0; j < arg_numb; ++j)
                    {
                        //printf("arg[%d]= %s\n", j, real_args[j]);
                    }

                    //execve(args[0],args,environ);

                    if ((cpid = fork()) == 0) 
                    {
                        //execvp(real_args[0], real_args+1);
                        execve(real_args[0],real_args,environ);
                        perror("execvp");
                        exit(2);
                    }
                    if (cpid == -1) 
                    {
                        perror("fork");
                        exit(3);
                    }
                    status = waitpid(cpid, &child_status, 0);
                    if (status == -1) 
                    {
                        perror("waitpid");
                        exit(4);
                    }
                    if (WIFEXITED(child_status)) 
                    {
                        //printf("Child process exited with status %d\n",
                        //        WEXITSTATUS(child_status));
                    } else 
                    {
                        printf("Child process did not exit normally.\n");
                    }
                    my_exit_status = child_status;

                }


                free(full_path);
                free(temp_cmd);
                arg_numb = 0;

            }
        }
    }
}
