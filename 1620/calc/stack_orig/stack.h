/* File stack.h */

#ifndef STACK_H
#define STACK_H

class Stack
{
    public:
        Stack(void);
        ~Stack(void);
        bool Empty(void) const;
        void Push(const int);
        int Pop(void);
        int Peek(void) const;
    private:
        int cap;
        int * arr;
        int top;
        //copy construction
};
#endif
