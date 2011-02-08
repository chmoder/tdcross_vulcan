/*----------------------------------------------------------------------*/
/* Thomas Cross                                                         */
/* Use execve to execute the program /bin/echo to display Hello, world! */
/*----------------------------------------------------------------------*/
#include <unistd.h>
#include <stdlib.h>

extern char **environ;			/* pointer to array of pointers */
					/* to strings with environment vars */

int main(int argc, char *argv[])
{
    char *args[4];

    args[0] = "/bin/echo";		/* complete path of file to execute */
					/* it becomes argv[0] of echo's main */
    args[1] = "Hello, ";		/* becomes argv[1] of echo's main */
    args[2] = "world!";			/* becomes argv[2] of echo's main */
    args[3] = 0;			/* marks end of the array */

    execve(args[0],args,environ);	/* replace the code and data for the */
					/* current process (which is running */
					/* echome) with the code and data for */					/* /bin/echo, with the given args.   */

    write(1,"execve failed.\n",15);	/* we only get here is execve failed */
    exit(1);				/* non-zero exit status == error */
}
