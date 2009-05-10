
#include<iostream>
using namespace std;
#include "word.h"
#include "list.h"
#include "tree.h"

int main()
{
        Word testword;
        Tree test_tree;
        cout << " in main " << testword << endl;
        
        testword = " plane ";
        test_tree.InsertWord(testword);

        testword = "car";
        test_tree.InsertWord(testword);
        testword = "boat";
        test_tree.InsertWord(testword);
        
        List testlist;
        
        testword = "johnclark";
        testlist.insert( testword );
        testword = "charlymurphey";
        testlist.insert( testword );
        testword = "rickjames";
        testlist.insert( testword );
        testword = "berserker";
        testlist.insert( testword );
        
        cout << "Testing member function access of testword "<< endl;
        cout << testword.Soundex() << endl;
        cout << endl << "Testing find function, looking for a word reference" <<
            endl; 
        cout << testlist.find(testword) << endl;
        cout << endl << "Testing grabbing first and third member of a list" <<
            endl;
        cout << testlist[1] << endl;
        cout << testlist[3] << endl;
        cout << endl << "printing list..." << endl;
        cout << testlist << endl;
        
        cout << "cout test_tree[0]  from test_file.cpp = " << test_tree[0] << endl;
        return 0;
}
