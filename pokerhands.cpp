//Assignment 4 Haoran Zhang
/*This program analyzes the cards the user procides and 
 prints out the categoty of poker hand they represent*/

#include <iostream>
using namespace std;

//returns true if four of five cards have the same value
bool containsFourOfaKind(int cards[5]);

/*returns true if three of five cards have the same value and 
the other two also have the same value*/
bool containsFullHouse(int cards[5]);

//returns true if five cards can be sorted in order
bool containsStraight(int cards[5]);

//returns true if three of five cards have the same value
bool containsThreeOfaKind(int cards[5]);

//returns true if two pairs out of five cards seperately have the same value
bool containsTwoPair(int cards[5]);

//returns true if one pair out of five cards have the same value
bool containsPair(int cards[5]);

int main()
{
  int hand[5];

  cout<<"\nEnter five numeric cards, no face cards. Use 2-9.";
  for(int i=1;i<=5;i++)
  {
    cout<<"\nCard "<<i<<":";
    cin>>hand[i];
  }

  if(containsFourOfaKind(hand))
  {
    cout<<"\nFour of a kind!";
  }

  else if(containsFullHouse(hand))
  {
    cout<<"\nFull house!";
  }

  else if(containsStraight(hand))
  {
    cout<<"\nStraight!";
  }

  else if(containsThreeOfaKind(hand))
  {
    cout<<"\nThree of a kind!";
  }

  else if(containsTwoPair(hand))
  {
    cout<<"\nTwo pair!";
  }

  else if(containsPair(hand))
  {
    cout<<"\nPair!";
  }

  else
    cout<<"\nHigh card!";

  return 0;
}

bool containsFourOfaKind(int cards[5])
{
  int numRepeat[100];

  for(int i=2;i<=9;i++)
  {
    numRepeat[i]=0;
  }

  for(int j=1;j<=5;j++)
  {
    numRepeat[cards[j]]++;
  }

  for(int k=2;k<=9;k++)
  {
    if(numRepeat[k]==4)
      return true;
  }

  return false;
}

bool containsFullHouse(int cards[5])
{
  int numRepeat[100];
  bool threeSame=false, twoSame=false;

  for(int i=2;i<=9;i++)
  {
    numRepeat[i]=0;
  }

  for(int j=1;j<=5;j++)
  {
    numRepeat[cards[j]]++;
  }

  for(int k=2;k<=9;k++)
  {
    if(numRepeat[k]==3)
      threeSame=true;
    if(numRepeat[k]==2)
      twoSame=true;
  }
    
  return threeSame && twoSame;
}

bool containsStraight(int cards[5])
{
  int numRepeat[100];
  int unique[5];
  int num=0;

  for(int i=2;i<=9;i++)
  {
    numRepeat[i]=0;
  }
  
  for(int j=1;j<=5;j++)
  {
    numRepeat[cards[j]]++;
  }
  
  for(int k=1;k<=5;k++)
  {
    unique[k]=0;
  }
  
  for(int l=2;l<=9;l++)
  {
    if(numRepeat[l]==1)
    {
      unique[num]=l;
      num++;
    }
  }
  
  if(num!=5)
    return false;
  if(unique[4]-unique[0]==4)
    return true;
  else
    return false;
}

bool containsThreeOfaKind(int cards[5])
{
  int numRepeat[100];
  
  for(int i=2;i<=9;i++)
  {
    numRepeat[i]=0;
  }
  for(int j=1;j<=5;j++)
  {
    numRepeat[cards[j]]++;
  }
  for(int k=2;k<=9;k++)
  {
    if(numRepeat[k]==3)
      return true;
  }
}

bool containsTwoPair(int cards[5])
{
  int numRepeat[100];
  int numPair=0;

  for(int i=2;i<=9;i++)
  {
    numRepeat[i]=0;
  }
  
  for(int j=1;j<=5;j++)
  {
    numRepeat[cards[j]]++;
  }
  
  for(int k=2;k<=9;k++)
  {
    if(numRepeat[k]==2)
      numPair++;
  }
  
  if(numPair==2)
    return true;
  else
    return false;
}

bool containsPair(int cards[5])
{
  int numRepeat[100];
  int numPair=0;

  for(int i=2;i<=9;i++)
  {
    numRepeat[i]=0;
  }
  
  for(int j=1;j<=5;j++)
  {
    numRepeat[cards[j]]++;
  }
  
  for(int k=2;k<=9;k++)
  {
    if(numRepeat[k]==2)
      numPair++;
  }

  if(numPair==1)
    return true;
  else
    return false;
}
