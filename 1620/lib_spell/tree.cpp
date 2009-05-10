/*File Tree.cpp*/
#include<iostream>
#include "list.h"
#include "word.h"
#include "tree.h"
using namespace std;

    //default tree constructor.  uses defalt tree construction
    //valus found in the tree.h file.  
    Tree::Tree (void)
    {
        root = new Node();
    }
   
    //recursive function called till all nodes are deleted
    Tree::~Tree(void)
    {
        chop( root );
    }
    
    //this function calls itself till it reaches the end of the
    //left hand side of the tree.  then checks the right and
    //deletes the right node and kills the parent.  So it
    //starts at the top and goes to the bottom.  deletes from 
    //bottom left to right
    void Tree::chop( Tree::Node * N )
    {   
        if( N )
        {
            //cout << N->data << endl;
            chop (N->left);
            chop (N->right);
            delete N;
        }
    }

    void Tree::insert( const Word word )
    {
        //cout << " In insert " << endl;
        Node * par=NULL;
        Node * curr=trav( word, par );
        if (!curr)
        {
            curr = new Node ();
            curr->words.insert( word );
            //curr = new Node( word );
            if (!par)
                root=curr;
            else if (par->data < word)
                par->right = curr;
            else
                par->left=curr;
        }
    }

 
    //Currently my traverse function recieves a word & and
    //appears to be mutated on arrival.  I have made it
    //constant to avoid this.  however I will need Mr. Clark's 
    //help tomorrow to see what is happening.  the traverse
    //function is supposed to traverse the tree and return 
    //whether the tree contains a word that is being traversed
    //exists or not.  returns the locatoin in tree for a node
    //that is less than curr data.
    Tree::Node * Tree::trav (const Word & word, Node * &par)const
    {
        Node * curr = root;
        par = NULL;
        
        
        while ( curr && (curr->data) != word)
        {
            //Below comments fully test data is accessable in list
            //cout << " In trav " << curr->data << endl;
            //cout << curr->words << endl;
            //cout << "in trav while " << endl;
            par = curr;
            curr = word < curr->data ? curr->left : curr->right;
        }
        return curr;
    }
    
   
    //Insert word will insert a word in a list by getting the
    //propper location by traversing the tree for the proper
    //soundex code.  wich will contain a node with words that
    //sounds alike.  then add that word to the list of simmaler
    //sounding words.  If the node is non existant then make
    //a new node for storing words.  Then i have to insert a 
    //word in the list at that node.  
    void Tree::InsertWord ( const Word & word )
    {   
        Word code = word.Soundex();
        Node * par = NULL;
        //cout << " in InsertWord " << endl;
        Node * curr = trav ( code, par );

        
        if (!curr)
        {
            curr = new Node ();
            curr->data = code;
            //curr = 
                curr->words.insert(word);
            if(!par)
                root = curr;
            else if ( word < par->data )
                par->left = curr;
            else
                par->right = curr;
        }
    }

    //this function will make it so that we can grab the 
    //pointer to the list in the node so we can print the
    //list etc.  

    List* Tree::operator [] ( const Word & word )
    {
        //cout << "ADDRESS OF par NODE words" << &(par->words) << endl;
        //cout << "ADDRESS OF curr NODE words" << &(curr->words) << endl;

        Word word1;
        static List list1;

        word1 = word.Soundex();
        Node * par = NULL;
        Node * curr = trav(word1, par );
        //cout << list1 << endl;
        //cout << "ADDRESS OF curr NODE words" << &(curr->words) << endl;
        cout << "Address of curr->words = " << &(curr->words) << endl;
        cout << "Address of curr = " << &curr << endl;
        cout << "Address of list1 = " << &(list1) << endl;
        cout << "Potental list of words (curr->words) = " << endl;
        //cout << curr->words << endl;
        
        if (!curr)
        {
            //cout << "!curr "<< &list1 << endl;
            //cout << "!curr " << list1[0] << endl;
            //cout << "addr of null = " << NULL << endl;
            //cout << curr->words << endl;
            return ( &(list1) );
        }
        else
        {
            //cout << "curr "<< &list1 << endl;
            return ( &(curr->words) );
        }
        

/*
        static  List list1;
        cout << " this is list[0] item " << list1[0] << endl;
        Node * par=NULL;
        Word code = word.Soundex();
        Node * curr = trav(code, par );
        cout << " this is curr->words[0] item " << curr->words << endl;
        
        //cout << " before ! " << endl;
        //cout << (curr->data) << endl;
        //cout << "IM IN THE [] OPERATOR ! " << endl;
        
        return (curr ? &(curr->words) : &(list1));
  */      
           }
    

