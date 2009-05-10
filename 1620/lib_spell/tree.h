/*File tree.h*/
#include<iostream>
#include "list.h"
#include "word.h"
using namespace std;

#ifndef TREE_H
#define TREE_H


//this is a class for creating a tree.  A tree has two node
//pointers each pointing to null; a list or words and a word
//for containing the soundex.  Information on the member 
//functions will be in the tree.cpp.
class Tree
{
    private:
        class Node 
        {
            public:
                Node * left;
                Word data;
                List words;
                Node * right;
                Node ( Node * p = NULL, Word d = "default",
                         Node * n = NULL )
                    : left(p), data(d), right(n) {;;;}
        };

       Node * root;

    public:
        Tree(void);
        ~Tree(void);
        void chop( Node *);
        //void remove ( const Word );
        //void print ( ostream & ) const;
        //bool find ( const Word & );
        void InsertWord( const Word & );
        void insert (const Word );
        Node * trav ( const Word &, Node * &) const; 
        List* operator [] ( const Word & );
        

 };


#endif
