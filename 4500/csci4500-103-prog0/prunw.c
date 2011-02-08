/*****************************************/
/* prunw                                 */
/* Create a new process to run a program */
/* and then wait for it to terminate and */
/* report its completion status.         */
/* Thomas Cross                          */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t cpid;			/* child's PID */
    pid_t status;		/* waitpid's return value */
    int child_status;		/* child's exit status */

    /*-----------------------------*/
    /* Check for too few arguments */
    /*-----------------------------*/
    if (argc < 2) { 
	fprintf(stderr,"Usage: prunw progname [arg] ...\n");
	exit(1);
    }

    if ((cpid = fork()) == 0) {
	/*---------------------------------------*/
	/* If fork returns 0 we're in the child. */
	/*---------------------------------------*/
	execvp(argv[1], argv+1);
	perror("execvp");
	exit(2);
    }

    if ((cpid = fork()) == 0) {
	/*---------------------------------------*/
	/* If fork returns 0 we're in the child. */
	/*---------------------------------------*/
	execvp(argv[1], argv+1);
	perror("execvp");
	exit(2);
    }

    if (cpid == -1) {
	/*----------------------------------------------*/
	/* If fork returns -1, it encountered an error. */
	/*----------------------------------------------*/
	perror("fork");
	exit(3);
    }

    /*------------------------------------------------------------*/
    /* Otherwise fork was successful. Wait for the child to exit. */
    /*------------------------------------------------------------*/
    status = waitpid(cpid, &child_status, 0);
    if (status == -1) {
	perror("waitpid");
	exit(4);
    }

    /*-------------------------------------------------------------*/
    /* If the child exited normally (with exit or return), display */
    /* a message stating that fact and the low-order 8 bits of its */
    /* exit status. Otherwise indicate that it did not terminate   */
    /* normally.                                                   */
    /*-------------------------------------------------------------*/
    if (WIFEXITED(child_status)) {
	printf("Child process exited with status %d\n",
	    WEXITSTATUS(child_status));
    } else {
	printf("Child process did not exit normally.\n");
    }
    
    exit(0);
}

/*****************************************************************/
/* Notes about this program                                      */
/*                                                               */
/* 1. Instead of using execve to execute the desired file (as in */
/*    prun), this program uses execvp which searches for the     */
/*    file in the directories specified in the PATH environment  */
/*    variable. Thus "./prunw echo Hello" will work correctly.   */
/*                                                               */
/* 2. The parent process also waits (using waitpid) for the      */
/*    child process to terminate normally or abnormally. It then */
/*    displays an appropriate message, and if termination was    */
/*    normal, also displays its exit or return status.           */
/*****************************************************************/
