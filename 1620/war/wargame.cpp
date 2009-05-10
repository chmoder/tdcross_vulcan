/* File wargame.cpp */

#include<iostream>
using namespace std;
#include "card.h"
#include "queue.h"
#include <iomanip>


int main ()
{
    //Seeds random variable
    srand ( time(0) );

    // the first variable is the deck variable
    // this variable is used for creating an
    // array for shuffling cards in
    // the second variable, hand, is used for 
    // making a players and and same with 
    // hand2
    int deck [52]; 
    int hand1 [26]; 
    int hand2 [26]; 

    //this loop makes a series of cards
    //for the game
    for ( int x = 0; x < 52; ++x )
    {
        deck [x] = x; //make cards
    }
    
    //this loop shuffles all cards by 
    //swaping every card 7 times
    //i used the < instead of the <=
    //to reduce CPU usage
    for ( int x = 0; x < 52; ++x )
    {
        for ( int y = 0; y < 8; ++y )
        {
            int temp = deck [x];
            int  randint = rand () % 52;
            deck [x] = deck [ randint ];
            deck [ randint ] = temp;
        }
    }
    
    //This for loop is used to deal all 26
    //cards per player to arrays hand1 & hand2
    for ( int x = 0; x < 26; ++x ) 
    //for ( int x = 0, y = 26; x < 26, y < 52; ++x, ++y ) 
    {
        hand1 [x] = deck [x];
        hand2 [x+26] = deck [x+26];
        //cout << hand1 [x] << "     " << hand2 [y] << endl;
    }

    //Due to the array hand1 and hand2 
    //being used i needed to rename 
    //the queues to something different
    Queue hand3;
    Queue hand4; 

    //Now that the ques have already
    //been created I can enqueue items
    //using the Enqueue function.
    //...assigning according values to
    //there respective hands because of 
    //the pre-shuffle
    for ( int x = 0; x < 26; ++x ) 
    //for ( int x = 0, y = 26; x < 26, y < 52; ++x, ++y ) 
        {
            hand3.Enqueue(hand1[x]);
            hand4.Enqueue(hand2[x+26]);
        }
            

    //Below is some testing code I 
    //performed to verify the 
    //queue and its contents are correct
    /*
    for ( int x = 0; x < 26; ++x ) 
        {
            cout << hand3.Dequeue() << " ";
        }
            cout << endl;
    for ( int y = 26; y < 52; ++y ) 
        {
            cout << hand4.Dequeue() << " ";
        }
            cout << endl;
        */    
            // Below code formats output to view deck
            /*
               for ( int x = 0; x < 52; ++x )
               {
               cout << deck [x] << " ";
               if (x == 10 || x == 20 || x == 30 || x == 40 ||x == 50 )
               cout << endl;
               }

             */
            
            //PRINT at begining of game
            cout << "Let the WAR begin!!! " << endl << endl;
            
            //The following variables are used
            //to make a card that can be compared
            //round is for counting number of rounds
            //ties is for chekecking number of ties 
            //per game
            int p1card = 0;
            int p2card = 0;
            int round = 0;
            int ties = 0;
            
            //If one of the hands become 
            //empty the game will be over
            //p1card will call the Dequeue
            //funciton to get the next card 
            //in queue and mod it by 13 to 
            //get the value so we can find 
            //ties and a winner per hand. 
            //display cards played and the 
            //number of cards in the
            //deck with some formatting
                

            while ( !hand3.Empty() && !hand4.Empty() )
            {
                p1card = hand3.Dequeue()%13;
                p2card = hand4.Dequeue()%13;
               
                //if P2 wins then enque cards
                if ( p1card < p2card )
                {
                    hand4.Enqueue(p2card);
                    hand4.Enqueue(p1card);

                    cout << setw(14) << right << Card(p1card) << " < "  << Card(p2card) << setw(10) << hand3.Count() << " - "  << hand4.Count() << endl;
                }
                //if P1 wins then enque cards
                else if ( p1card > p2card )
                {
                    hand3.Enqueue(p1card);
                    hand3.Enqueue(p2card);

                    cout << setw(14) << right << Card(p1card) << " > "  << Card(p2card) << setw(10) << hand3.Count() << "- "  << hand4.Count() << endl;
                }
                //if its a tie then discard card
                //and increment the number of ties
                //count number of total rounds
                else 
                {
                    cout << setw(14) << right << Card(p1card) << " = "  << Card(p2card) << setw(10) << hand3.Count() << " - "  << hand4.Count() << endl;
                    ++ties; 
                }
                ++round;
            }
            //whoever is empty first wins
            if (hand3.Empty())
            {
                cout << endl << "Player 2 wins!";
            }
            else
            {
                cout << endl << "Player 1 wins!";
            } 
            //display number of rounds and ties to the user
            cout << endl << "It took " << round << " hands, and there were " << ties << " ties." << endl; 
            return 0;
            }

