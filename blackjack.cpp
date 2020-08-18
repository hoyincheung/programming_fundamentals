//Assignment 2 Haoran Zhang
//This program plays the game Blackjack
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  const int MIN_VALUE=1;
  const int MAX_VALUE=11;

  int numRand1, numRand2, numRand, total=0;
  char answerA, answerB;
  unsigned seed=time(0);

  srand(seed);
  
  do
  { 
    numRand1=(rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    numRand2=(rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    cout << "\nFirst cards: " << numRand1 << "," << numRand2;
    total=numRand1+numRand2;
    cout << "\nTotal: " << total;
  
    do
    {
      cout << "\nDo you want to play another card?(y for yes, n for no)" << endl;
      cin >> answerA;

      if (answerA=='y')
      {
        numRand=(rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        cout << "\nCard: " << numRand;
        total+=numRand;
        cout << "\nTotal: " << total;
      }  
       
      if (total>=21)
      {
        cout << "\nBust!";
        break;
      }
    } while (answerA=='y');
    
    cout << "\nWould you like to play again?(y for yes, no for no)"<<endl;
    cin >> answerB;

  } while (answerB=='y');

  return 0;
}
