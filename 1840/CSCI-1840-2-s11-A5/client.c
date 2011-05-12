/**********************************************************************/
/* A simple program to open up a socket and send something over, then */
/* read back a reply.                                                 */
/*                                                                    */
/* For: CSCI 1840                                                     */
/* By:  Bill Mahoney                                                  */
/*                                                                    */
/* Usage: ./client 'message here' hostname                            */
/*        hostname is optional and goes to the define below.          */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h> /* exit() */
#include "portdefine.h"

#define HOST        "vulcan"  /* Replace with your server machine name*/

int main( int argc, char **argv )
{
    int                quitter = 1;
    char               request[BUFSIZ];
    char               data[BUFSIZ];
    char               hostname[100];
    char               buf[BUFSIZ];
    int                sd;
    /*struct sockaddr_in sin;*/
    struct sockaddr_in pin;
    struct hostent     *hp;

    /* Usage: ./client message host */

    strcpy( hostname, HOST );
    /*
    if(argc < 2 || argc > 3)
    {
        fprintf(stderr, "Usage : %s <REQUEST>\nREQUEST:\n\tget lname\n\tget fname\n\tget SID\n\tget GPA\n\tput last name,first name,middle initial,student id,gpa\n\tdelete sid\n\tstop\n", argv[0]);
    }
    */

    /* go find out about the desired host machine */
    if ( ( hp = gethostbyname( hostname ) ) == 0 )
    {
        perror( "gethostbyname" );
        exit( 1 );
    }

    /* Fill in the socket structure with host information */
    memset( &pin, 0, sizeof( pin ) );
    pin.sin_family = AF_INET;
    pin.sin_addr.s_addr = ( ( struct in_addr * )( hp->h_addr ) )->s_addr;
    pin.sin_port = htons( PORT );

    /* Grab an Internet socket */
    if ( ( sd = socket( AF_INET, SOCK_STREAM, 0 ) ) == -1 )
    {
        perror( "socket" );
        exit( 1 );
    }

    /* Connect to that port on the indicated host */
    if ( connect( sd,( struct sockaddr * ) &pin, sizeof( pin ) ) == -1 )
    {
        perror( "connect" );
        exit( 1 );
    }

    while(quitter)
    {
        printf("Request: ");
        scanf("%s", request);

        if(!strcmp(request, "stop"))
        {
            printf("sending stop...\n");
            if(send( sd, request, strlen(request) + 1, 0 ) == -1 )
            {
                perror( "send" );
                exit( 1 );
            }
            buf[0] = '\0';
            request[0] = '\0';
            data[0] = '\0';
            sleep(1);
            quitter = 0;
        }
        else if(!strcmp(request, "get"))
        {
            scanf("%s", data);
            strcat(buf, request);
            strcat(buf, " ");
            strcat(buf, data);
            /* Send the message over to them. */
            send( sd, buf, strlen(buf) + 1, 0 );
            recv(sd, buf, BUFSIZ, 0);
            printf("%s", buf);

            buf[0] = '\0';
            request[0] = '\0';
            data[0] = '\0';
        }
        else
        {
            scanf("%s", data);
            strcat(buf, request);
            strcat(buf, " ");
            strcat(buf, data);
            /* Send the message over to them. */
            if ( send( sd, buf, strlen(buf) + 1, 0 ) == -1 )
            {
                perror( "send" );
                exit( 1 );
            }
            buf[0] = '\0';
            request[0] = '\0';
            data[0] = '\0';
        }
    }

    /* Clean up after yourself. Be a good citizen. */
    close( sd );
    return( 0 );
}
