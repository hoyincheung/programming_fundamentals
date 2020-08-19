//Assignment 6 Haoran Zhang
//This program performs some simple tasks with pointers
#include <iostream>
using namespace std;

/*This function checks if the value of the accepted parameter 
is negative; if it is, then set it to zero*/
void noNegatives(int *x);

//This function swap the two int that the arguments point to
void swap(int *num1, int *num2);

int main()
{
  int x, y; //create two int variables named x and y
  int *p1; //create an int pointer named p1

  p1=&x; //store the address of x in p1
  *p1=99; //use p1 to set the value of x to 99

  cout<<x<<endl; //using cout and x, display the value of x
  cout<<*p1<<endl; //using cout and the pointer p1, display the value of x

  p1=&y; //store the address of y into p1
  *p1=-300; //use p1 to set the value of y to -300

  int temp; //create two new variables: an int named temp
  int *p2; //and an int pointer named p2

  p2=&x; //use temp, p1, and p2 to swap the values in x and y
  temp=*p1;
  *p1=*p2;
  *p2=temp;

  noNegatives(&x); //call the function twice: once with the address of x as the argument
  noNegatives(&y); //and once with the address of y

  cout<<*p2<<endl; //use p2 to display the values in x and y
  p2=&y;
  cout<<*p2<<endl;

  int a[2]; //create an int array named 'a' with two elements
  
  p2=&x; //use p2 to initialize the first element of a with the value of x
  *a=*p2;
  
  p2=&y; //use p2 to initialize the second element of a with the value of y
  *(a+1)=*p2;

  cout<<a<<endl;//using cout, display the address of the first element in a
  cout<<a+1<<endl;//using cout, display the address of the second element in a

  p1=a; //Use p1, p2, and temp to swap the values in the two elements of array 
  p2=a+1;
  temp=*p1;
  *p1=*p2;
  *p2=temp;
  
  cout<<a[0]<<endl; //display the values of the two elements
  cout<<a[1]<<endl;

  swap(&x,&y); //call the swap function with the addresses of x and y
  cout<<x<<endl<<y<<endl; //then print their values

  swap(a,a+1); /*call the swap function with the address 
                of the two elements in array 'a'*/ 
  cout<<a[0]<<endl<<a[1]<<endl; //then print their values
 
  return 0;
}

void noNegatives(int *x)
{
  if(*x<0)
    *x=0;
}

void swap(int *num1, int *num2)
{
  int temp;
  
  temp=*num1;
  *num1=*num2;
  *num2=temp;
}
