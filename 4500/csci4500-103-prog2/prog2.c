/* File prog2.c */
/*Thomas Cross */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

    int validFile(char*);
    char* readFile(void);
    void down(int*);
    void up(int*);
    void reader(int*, int*);
    void writer(int*, int*);

    void reader(int* mutex, int* file_sem)
    {
        struct timespec ts;
        srand(time(NULL));
        char* data;
        int i = 0;

        int count = 0;
        while(count < 100)
        {
            int rc = 0;

            down(mutex);
            rc = rc + 1;
            if(rc == 1) 
            {
                down(file_sem);
            }
            up(mutex);

            int nsec = (100 + rand() % 400);
            ts.tv_sec = 0 + rand() % 2;
            ts.tv_nsec = nsec;
	        nanosleep(&ts,NULL);
            data = readFile();
            //printf("reading... %d %d\n",count+1, nsec);

            down(mutex);
            rc = rc - 1;
            if(rc == 0) 
            {
                up(file_sem);
            }
            up(mutex);
            if(!validFile(data))
            {
                fprintf(stderr,"Validation Error:  Your data is not intact.\n");
                free(data);
                exit(1);
            }
            free(data);
            if(++count == 99)
                exit(0);
        }
    }
    void down(int* mutex)
    {
        char c;
        read(mutex[1], &c, 1);
        //printf("in down: %c\n", c);
    }
    void up(int* mutex)
    {
        char c = '1';
        write(mutex[0], &c, 1);
        //printf("in up:\n");
    }
    void writer(int* mutex, int* file_sem)
    {
        int i;
        struct timespec writer_time;
        srand(time(NULL));
        
        int count = 0;
        while(count < 50)
        {
            
            writer_time.tv_sec = 0 + rand() % 2;
            writer_time.tv_nsec = (100 + rand() % 400);
	        nanosleep(&writer_time,NULL);

            unsigned int orig = time(NULL);
            char seconds = orig;

            down(file_sem);
            int fd = open("my.disk.file", O_RDWR | O_CREAT, 0644);
            //printf("writing... %d\n",count+1);
            for (i = 0; i < 100; ++i) 
            {
                write(fd,&seconds,1);
            }
            close( fd );
            up(file_sem);
            if(++count == 49)
                exit(0);
        }
    }
    char* readFile(void)
    {
        int i = 0;
        char* data = malloc(100 * sizeof(char));
        int fd = open("my.disk.file", O_RDWR | O_CREAT, 0644);
        for(i = 0; i < 100; ++i)
            read(fd, &data[i], 1);
        close( fd );
        return data;
    }
    int validFile(char * data)
    {
        int retval = 1;
        int i;
        for(i = 0; i < 100; ++i)
        {
            //printf("%c ",data[i]);
            if(data[0] != data[i])
            {
                retval = 0;
            }
        }
        return retval;
    }


int main(int argc, char *argv[])
{
    int i,j;			/* iteration counter */
    int status;			/* system call status */
    char c;			/* a one-byte variable */
    pid_t child;
    int mutex[2];   /* mutex semaphore */
    int file_sem[2];   /* mutex semaphore */
    int fd;
    int readers, writers;

    status = pipe(mutex);
    if (status == -1)   /* check for error */
    {		
        perror("pipe");
        exit(1);
    }
    write(mutex[0], "1", 1);

    status = pipe(file_sem);
    if (status == -1)   /* check for error */
    {		
        perror("pipe");
        exit(1);
    }
    write(file_sem[0], "1", 1);

    /*---------------------------------------------------------------*/
    /* Validate user input and assign number of readers to variables */
    /*---------------------------------------------------------------*/
    if (argc != 3)
    {
        fprintf(stderr,"Usage: prog2 READERS WRITERS\n");
        fprintf(stderr,"        READERS is the numbers of readers.\n");
        fprintf(stderr,"        WRITERS is the numbers of writers.\n");
        exit(0);
    }
    else
    {
        readers = atoi(argv[1]);
        writers = atoi(argv[2]);
    }
    if(readers > 5 || writers > 2 || readers < 1 || writers < 1)
    {
        fprintf(stderr, "You may have between 1 and 5 readers and 1 or 2 writers.\n");
        printf("You input %d reader(s) and %d writer(s)\n", readers, writers);
        exit(0);
    }

    /*---------------------------------------------------------------*/
    /* Open, creating if necessary, a disk file named "my.disk.file" */
    /*---------------------------------------------------------------*/
    fd = open("my.disk.file", O_RDWR | O_CREAT, 0644);
    if (fd == -1) 
    {
        perror("open");
        exit(1);
    }

    /*----------------------------------------------------*/
    /* Write 100 bytes, each containing 0x00, to the file */
    /*----------------------------------------------------*/
    c = 0x00;
    for (i=0;i<100;i++) 
    {
        status = write(fd, &c, 1);
        if (status == -1) 
        {
            perror("write");
            exit(1);
        }
        if (status != 1)
        {
            printf("parent write - failed to write one byte.\n");
            exit(1);
        }
    }
    close( fd );

/*
        read(fd,&c,100);
        for(i=0; i < 100; ++i)
            printf("%c ", c);
*/

    for(i = 0; i < readers; ++i)
    {
        child = fork();
        if(child == -1)
        {
            perror("reader fork");
            exit(1);
        }
        if(child == 0)
        {
                reader(mutex, file_sem);
        }
    }
    for(j = 0; j < writers; ++j)
    {
        child = fork();
        if(child == -1)
        {
            perror("writer fork");
            exit(1);
        }
        if(child == 0)
        {
            int writer_count = 0;
            for(writer_count = 0; writer_count < 100; ++writer_count)
                writer(mutex, file_sem);
        }
    }

        if(child != 0)
        {
            //printf("in parent\n");
            int wait_count = 0;
            for(wait_count = 0; wait_count <= (readers + writers); ++wait_count)
                wait(NULL);
            exit(0);
        }
        
}
