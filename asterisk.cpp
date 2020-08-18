//Assignment 1:Haoran Zhang
//This program prints out as many asterisks as the user wants

#include <iostream>
using namespace std;

int main()
{
  int numAsterisk;
  char answer='y';

  while(answer=='y')
  {
    cout<<"\nHow many asterisks do you want to print out?"<<endl;
    cin>>numAsterisk;
    cout<<endl;

    for(int i=0;i<numAsterisk;i++)
    {
      cout<<"*";
    }
    cout<<endl;
    cout<<"\nDo you want to go again?(y for yes, n for no)"<<endl;
    cin>>answer;
  }
  
  return 0;
}
