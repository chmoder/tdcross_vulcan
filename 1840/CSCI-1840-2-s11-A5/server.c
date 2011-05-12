/**********************************************************************/
/* A simple program to create a socket, listen, read messages, etc.   */
/*                                                                    */
/* For: CSCI 1840                                                     */
/* By:  Bill Mahoney                                                  */
/*                                                                    */
/* Usage: ./server                                                    */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "portdefine.h"
#include "linked_list.h"


struct DB {
    struct Node *lname_db;
    struct Node *fname_db;
    struct Node *sid_db;
    struct Node *gpa_db;
};

struct DB *openDb(char *);
void closeDb(struct DB *, char *);
struct DB *newDB(void);
void initDb(struct DB *);
void freeDB(struct DB *);
void printDB(struct Node *, char *, int);
void getRecord(struct DB *, char *, char *, int);
void putRecord(struct DB *, char *);
void deleteRecord(struct DB *, char *);


int main(void)
{
    char               *db_name = "srecDB.fql";
    struct DB          *db;
    char               print_buf[BUFSIZ];
    /*struct Node        db[4];*/
    int                quitter = 1;
    int                recieved = 0;
    char               buf[ BUFSIZ ];
    int                sd, sd_current/*, cc, fromlen, tolen*/;
    socklen_t          addrlen;
    struct sockaddr_in sin;
    struct sockaddr_in pin;
 

    /* Get an internet domain socket */
    if ( ( sd = socket( AF_INET, SOCK_STREAM, 0) ) == -1 )
    {
        perror( "socket");
        exit( 1 );
    }

    /* Complete the socket structure */
    memset( &sin, 0, sizeof(sin) );
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons( PORT );

    /* Bind the socket to the port number */
    if ( bind( sd, ( struct sockaddr *) &sin, sizeof( sin ) ) == -1) 
    {
        perror( "bind" );
        exit( 1 );
    }

    /* Listen for clients that want to connect.         */
    /* In a real "server" we would get a connection and */
    /* then "fork" or create a thread for that one, but */
    /* here we only handle one connection.              */
    if ( listen( sd, 5 ) == -1 ) 
    {
        perror( "listen" );
        exit( 1 );
    }

    /* Wait for a client connection, then accept it. */
    addrlen = sizeof(pin); 
    if ( ( sd_current = accept( sd, ( struct sockaddr *)&pin, &addrlen ) ) == -1 )
    {
        perror( "accept");
        exit( 1 );
    }

    /* Let's show the incoming stuff just for fun. */
    /*printf( "Coming from port %d\n", ntohs( pin.sin_port ) );*/

    /* If this is a server that needs to keep taking messages */
    /* from the client, then put a "while" loop here to keep  */
    /* reading data. The easy way to do this is to have the   */
    /* client send "exit" or some special string to terminate */
    /* the "while" loop. Otherwise you tend to get SIGPIPE or */
    /* other errors from the "recv" and "send" calls.         */

    /* Open database file*/
    db = openDb(db_name);

    /* get a message from the client */
    while((recieved = recv(sd_current, buf, sizeof(buf), 0)) > 0 && quitter)
    {
        char delims[] = " ";
        char *request = NULL;
        char *data = NULL; 

        request = strtok(buf, delims);
        data = strtok(NULL, delims);

        if(!strcmp(request, "stop"))
        {
            closeDb(db, db_name);
            quitter = 0;
        }
        else if(!strcmp(request, "get"))
        {
            getRecord(db, data, print_buf, sd_current);
        }
        else if(!strcmp(request, "put"))
        {
            putRecord(db, data);
        }
        else if(!strcmp(request, "delete"))
        {
            deleteRecord(db, data);
        }
    }

    /* close up both sockets */
    close( sd_current ); 
    close( sd );

    return( 0 );
}

struct DB *openDb(char *name)
{
    int i;
    FILE *file;
    struct DB *db = newDB();
    struct Srec *srec;
    unsigned long file_len;

    file = fopen(name, "rb");
    if(!file)
    {
        fprintf(stderr, "Unable to open file %s\n", name);
        fprintf(stderr, "Making new DB called: %s\n", name);
        file = fopen(name, "wb");
        if(!file)
        {
            fprintf(stderr, "Failed to make a new DB.  Please check the directory permissions.\n");
            exit(1);
        }
    }

    fseek(file, 0, SEEK_END);
    file_len=ftell(file);
    fseek(file, 0, SEEK_SET);

    printf("file_len= %lu\n", file_len);
    if(file_len)
    {
        for(i = 0; i < file_len/sizeof(struct Srec); ++i)
        {
            srec = newSrec();
            fread(srec, sizeof(struct Srec), 1, file);
            insertNode(&(db->lname_db), srec, lname_cmp);
            insertNode(&(db->fname_db), srec, fname_cmp);
            insertNode(&(db->sid_db), srec, sid_cmp);
            insertNode(&(db->gpa_db), srec, gpa_cmp);
        }
        printList(db->fname_db);
    }
    fclose(file);
    return db;
}

void closeDb(struct DB *db, char *name)
{
    FILE *file;
    struct Node *curr = db->lname_db;
    file = fopen(name, "wb+");

    while(curr != NULL)
    {
    if(curr->data != NULL)
    {
        printf("writing srec:\n");
        printSrec(curr->data);
        fwrite(curr->data, sizeof(struct Srec), 1, file);
        curr = curr->next;
    }
    }
    printf("test\n");


    if(db->lname_db->data != NULL)
    {
        freeList(db->lname_db);
    /*All lists hold the same pointers.  So free one, frees all.*/
    unLink(db->fname_db);
    unLink(db->sid_db);
    unLink(db->gpa_db);
    }
    /*
    freeList(db->fname_db);
    freeList(db->sid_db);
    freeList(db->gpa_db);
    free(db->fname_db);
    free(db->sid_db);
    free(db->gpa_db);
    */
    freeDB(db);
    fclose(file);
}

struct DB *newDB(void)
{
    struct DB *db = (struct DB *)malloc(1 * sizeof(struct DB));
    initDb(db);
    return db;
}

void freeDB(struct DB *db)
{
    free(db);
}

void initDb(struct DB *db)
{
    db->lname_db = NULL;
    db->fname_db = NULL;
    db->sid_db = NULL;
    db->gpa_db = NULL;
}

void getRecord(struct DB *db, char *buf, char *print_buf, int sd_current)
{
    if(!strcmp(buf, "lname"))
    {
        printDB(db->lname_db, print_buf, sd_current);
    }
    else if(!strcmp(buf, "fname"))
    {
        printDB(db->fname_db, print_buf, sd_current);
    }
    else if(!strcmp(buf, "SID"))
    {
        printDB(db->sid_db, print_buf, sd_current);
    }
    else if(!strcmp(buf, "GPA"))
    {
        printDB(db->gpa_db, print_buf, sd_current);
    }
}

void printDB(struct Node *head, char *print_buf, int sd_current)
{
    char temp_str[BUFSIZ];
    sprintf(print_buf, "| SID   | Lname     | Fname     | M | GPA  |\n");
    
    sprintf(temp_str, "+-------+-----------+-----------+---+------+\n");
    strcat(print_buf, temp_str);
    
    stringList(head, print_buf);
    
    sprintf(temp_str, "+-------+-----------+-----------+---+------+\n\n");
    strcat(print_buf, temp_str);

    /*printf("%s", print_buf);*/
    if ( send( sd_current, print_buf, strlen(print_buf) + 1, 0) == -1)
    {
        perror( "send" );
        exit( 1 );
    }
    /*
    printf("| SID   | Lname     | Fname     | M | GPA  |\n");
    printf("+-------+-----------+-----------+---+------+\n");
    printList(head);
    printf("+-------+-----------+-----------+---+------+\n\n");
    */
}

void putRecord(struct DB *db, char *buf)
{

    struct Srec *srec = newSrec();

    char delims[] = ",";
    char *lname = NULL;
    char *initial = NULL;
    char *fname = NULL;
    char *sid = NULL;
    char *gpa = NULL;

    printf("Add to database %s\n", buf);
    lname = strtok(buf, delims);
    fname = strtok(NULL, delims);
    initial = strtok(NULL, delims);
    sid = strtok(NULL, delims);
    gpa = strtok(NULL, delims);


    setSrec(srec, lname, initial[0], fname, strtoul(sid, NULL, 10), atof(gpa));
    printSrec(srec);

    insertNode(&(db->lname_db), srec, lname_cmp);
    insertNode(&(db->fname_db), srec, fname_cmp);
    insertNode(&(db->sid_db), srec, sid_cmp);
    insertNode(&(db->gpa_db), srec, gpa_cmp);

    printf("Printing List:\n");
    printList(db->lname_db);
}

void deleteRecord(struct DB *db, char *buf)
{
    unsigned long sid = strtoul(buf,NULL,10);
    printf("Delete %lu\n", sid);
    
    
    unlinkNode(db->lname_db, sid);
    unlinkNode(db->fname_db, sid);
    unlinkNode(db->sid_db, sid);
    deleteNode(db->gpa_db, sid);
}
