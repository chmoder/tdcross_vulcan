
// Spell Checker
// John W. Clark
// CSCI 1620
// spring 2009

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<cctype>

using namespace std;

// user defined header files
// you may change these to work with your file names
#include "word.h"
#include "list.h"
#include "tree.h"


// defines used
//#define DEFAULT_DICT	"/usr/dict/words"	    // old standard locatation
//#define DEFAULT_DICT  "/usr/share/dict/words" // standard locatation
#define DEFAULT_DICT    "/home/jclark/bin/words"    // phoenix locatation

#define BAK_EXT			".bak"
#define BUF_LEN			4096

// function prototypes

int make_backup( char ifname[] );
int read_dictionary( char dict_name[], Tree & dtree );
int read_input( char ifname[], Tree & dtree );
char * parse_buf( char * & begin, bool & flag );

// this is stuff for debugging
int debug = 1;      // warning this is global
#define TRACEF(x)		if ( debug >= (x) )
/*
   if you want to make TRACEF work in your module add this to your
   cpp file ( or in a header, then include it in the your module. )
extern int debug;
#define TRACEF(x)		if ( debug >= (x) )

    Then you can put in debug output like this :
TRACEF( 5 ) cout << "whatever you want" << endl;

    this line will only output if debug if 5 or greater.
 */

int main( int argc, char * argv[] )
{
    char ifname[BUF_LEN] = "";
    char dict_name[BUF_LEN] = "";
    Tree dtree;

    if ( argc < 3 )
    {
        cerr << " usage : " << argv[0] << " -f file.txt " << endl
            << "    optional arguments" << endl
            << "    -d dictionary.file" << endl
            << "    -v debugging_level" << endl;
        exit(1);
    }

    // handle the arguments
    for( int i = 0 ; i < argc ; i++ )
    {
        if ( !strncmp("-d", argv[i], 2 ) )
        {
            strcpy( dict_name, argv[++i] );
        }
        else if ( !strncmp("-f", argv[i], 2 ) )
        {
            strcpy( ifname, argv[++i] );
        }
        else if ( !strncmp("-v", argv[i], 2 ) )
        {
            debug = atoi( argv[++i] );
            if ( debug < 1 ) debug = 1;
        }
    }

    // check for input file name
    if ( !ifname[0] )
    {
        cerr << "no input file given" << endl;
        exit(1);
    }

    // set dictionary name
    if ( !dict_name[0] )
    {
        strcpy( dict_name, DEFAULT_DICT );
    }

    TRACEF(1) cout << " infile : " << ifname << endl;
    if ( ! make_backup( ifname ) )
    {
        cerr << "input file does not exist" << endl;
        exit(1);
    }
    TRACEF(1) cout << " dictionary : " << dict_name << endl;
    if ( ! read_dictionary( dict_name, dtree ) )
    {
        cerr << "dictionary file does not exist" << endl;
        exit(1);
    }
    TRACEF(1) cout << " checking spelling" << endl;
    if ( ! read_input( ifname, dtree ) )
    {
        cerr << "input file error" << endl;
        exit(1);
    }
    return 0;
}


// ifname must be initialized, it will fix the names
// a ".bak" will be made and it will be 
// if return is 0 it failed

// int make_backup( char ifname[] )
//
// input:	filename
// ouput:	none
// return:	1 if backup is successful, 0 otherwise
//
int make_backup( char ifname[] )
{
    int rval;
    char ofname[BUF_LEN] = "";

    strcpy( ofname, ifname );	// ofname = the input filename
    strcat( ofname, BAK_EXT );  // ofname = input file name + extenstion

    ifstream infile( ifname );
    ofstream outfile( ofname );
    if (( !infile ) || ( !outfile ))
    {
        rval = 0;
    }
    else
    {
        rval = 1;
        // make the backup of the input file
        outfile << infile.rdbuf();
        infile.close();
        outfile.close();
    }
    TRACEF(5) cout << " backup returned " << rval << endl;
    return rval;
}


// int read_dictionary( char dict_name[], Tree & dtree )
//
// input:	dictionary filename, tree
// ouput:	the tree will be populated with the words list
// return:	1 if read is successful, 0 otherwise
//
int read_dictionary( char dict_name[], Tree & dtree )
{
    int rval;
    ifstream dict( dict_name );
    if ( !dict )
    {
        rval = 0;
    }
    else
    {
        rval = 1;
        char buf[BUF_LEN];

        // these are a word per line
        while( dict.getline( buf, sizeof( buf ) ) )
        {
            Word word = buf;
            TRACEF(8) cout << "-" << word.Soundex() << "-" << word << endl;
            // insert words in your dictionary here
            dtree.InsertWord( word );
        }
        dict.close();
    }
    TRACEF(5) cout << " read dictionary returned " << rval << endl;
    return rval;
}

// int read_input( char ifname[], Tree & dtree )
//
// input:	input filename, tree
// ouput:	if a word is not in the tree
//			the list of possible word is listed
// return:	1 if read is successful, 0 otherwise
//
int read_input( char ifname[], Tree & dtree )
{
    int rval;
    char ofname[BUF_LEN] = "";

    strcpy( ofname, ifname );	// ofname = the input filename
    strcat( ofname, BAK_EXT );  // ofname = input file name + extenstion

    ifstream infile( ofname );
    ofstream outfile( ifname );

    if (( !infile ) || ( !outfile ))
    {
        rval = 0;
    }
    else
    {
        rval = 1;
        char buf[BUF_LEN];
        char * begin;
        char * ptr;
        bool flag;

        while( infile.getline( buf, sizeof( buf ) ) )
        {
            // parse buf for tokens, and punctuation
            begin = buf;
            while( begin[0] !=  0 )
            {
                ptr = parse_buf( begin, flag );
                TRACEF(4) cout << ptr << " is "
                    << ( flag ? " " : "not " ) << "a word" << endl;
                if ( !flag )
                {
                    outfile << ptr;
                }
                else
                {
                    // it is a word, check it against the dictionary
                    Word word = ptr;
                    // get the List of matching words
                    List * l = dtree[ word ];
                    if ( l->find( word ) )
                    {
                        // it was in the dictionary, so use it
                        outfile << word;
                    }
                    else
                    {
                        // it was not in the dictionary
                        // show the context
                        cout << buf << endl;
                        // show the word
                        cout << "word to replace : " << word << endl;
                        // item 0 is the misspelled word
                        cout << "0 : " << word << endl;
                        // show the List of matching words and prompt
                        cout << *l << " input choice : " << flush;

                        // read the input choice
                        char inbuf[BUF_LEN];
                        cin.getline( inbuf, sizeof( inbuf ) );
                        int num = atoi( inbuf );
                        if ( num <= 0 )
                        {
                            outfile << word; // accept the word
                        }
                        else    // num > 0
                        {
                            // replace it with the selection
                            Word replace = (*l)[num];
                            if ( replace != "" )
                            {
                                // match capitalization of the first letter
                                if ( isupper( word[0] ) )
                                {
                                    replace[0] = word[0];
                                }
                                // the new word, put it in the stream
                                outfile << replace;
                            }
                            else    // we got a blank word
                            {
                                outfile << word; // accept the word
                            }
                        }
                    }
                }	// end of else
            }	// while characters still in buf
            outfile << endl;
        }	// while input lines to parse

        infile.close();
        outfile.close();
    }
    TRACEF(5) cout << " read input returned " << rval << endl;
    return rval;
}



/* ===================================================================

   char * parse_buf( char * & begin, bool & flag )

inputs:		a pointer to a buffer, and a boolean reference
outputs:	the pointer advanced past the next token,
and the bool set to
true if the token is a word
false if is something other than a word
returns:	a pointer to the parsed token

description:
This function is like an enhanced non-mangling strtok.  It does
not harm the input buffer, and it parses tokens based on words not
white space.   It returns the word, punctuation, or white space,
and the flag will be true if it is a word.  This allows the user 
to call this function and not worry about preserving punctuation
or whitespace, since it is returned in its original form.

=================================================================== */

char * parse_buf( char * & begin, bool & flag )
{
    int i;					// loop counter
    static char buf[256];	// this buffer is what is returned

    memset( buf, 0x00, sizeof( buf ) );	// set the entire buffer to NULL

    if( isalpha(begin[0]) )
    {
        // it is a word
        flag = true;
        // advance until NULL, or a non-alpha, except a hyphen or apostraphe
        for( i = 0 ; (begin[i] != 0) &&
                ( ( isalpha(begin[i]) ) ||
                  ( begin[i] == '-' ) || ( begin[i] == '\'' ) ); i++ )
        {
            ;	// do nothing
        }
    }
    else
    {
        // it is not a word
        flag = false;
        // advance until NULL, or an alpha
        for( i = 0 ; (begin[i] != 0) && (!isalpha(begin[i])) ; i++ )
        {
            ;	// do nothing
        }
    }
    strncpy( buf, begin, i );	// copy it into the buffer
    begin += i;					// advance the begin pointer
    buf[i] = 0;					// null terminate the buffer
    return buf;
}
