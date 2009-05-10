#include<iostream>


//A class describes how a rectangle looks.

class rectangle
{
public:
int length;
int width;
public:
void display()
{
std::cout<<length<<":"<<width<<std::endl;
}
void setlength(int d)
{
length=d;
}
void setwidth(int e)
{
width=e;
}
int calcarea()
{
return length*width;

}
void calcperimeter()
{
int perimeter;
perimeter= 2* (length+width);
std::cout<<"Perimeter=="<<perimeter<<std::endl;
}

};

int main()
{
int area1, area2;
rectangle r1,r2; //creates instances of the class rectangle.

r1.setlength(10);
r2.setlength(100);
r1.setwidth(20);
r2.setwidth(200);
r1.display();
r2.display();
area1=r1.calcarea();
area2=r2.calcarea();
std::cout<<area1<<":"<<area2<<std::endl;

r1.calcperimeter();
r2.calcperimeter();

return 0;
}
