//Assignment 3,Haoran Zhang
//This program guess a number the user chosen between 1 and 100

#include <iostream>
using namespace std;

void playOneGame( );
bool shouldPlayAgain();
char getUserResponseToGuess(int guess);
int getMidpoint(int &low, int &high);

int main()
{
  cout<<"\nThink of a number between 1 and 100.";
  do
  {
    playOneGame();
  }while(shouldPlayAgain());

  return 0;
}

int getMidpoint(int &low, int &high)
{
  int midP=(high+low)/2;

  return midP;
}

char getUserResponseToGuess(int guess)
{
  char answer;
  cout<<"\nIs it "<<guess<<"?(h for higher,l for lower,c for correct)"<<endl;
  cin>>answer;

  return answer;
}

void playOneGame()
{  
 int LOW=1, HIGH=100, mid;
 char response;

 do
 {
   mid=getMidpoint(LOW,HIGH);
   response=getUserResponseToGuess(mid);
  
   if(response=='h')
     LOW=mid;
   else if(response=='l')
     HIGH=mid;
   else
     cout<<"\nGreat!";
  }while(response!='c');
}

bool shouldPlayAgain()
{
  char choice;
  bool status;
  cout<<"\nDo you want to play again?(y for yes,n for no)"<<endl;
  cin>>choice;

  if(choice=='y')
    status=true;
  else
    status=false;

  return status;
}
