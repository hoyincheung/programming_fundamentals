//Assignment 8 Haoran Zhang
//This program asks team names whose numbers are decided by users and wins amount 
//then prints out the wins from highest to lowest
#include <iostream>
#include <cstring>
using namespace std;

struct WinRecord
{
  int wins;
  char *name=NULL;
};

/*this program reads in a line of text and returns it 
  in a dynamically allocated array*/
char* getLine();

//this function reads in and stores the names and wins provided by the user
void initializeData(WinRecord *standings,int size);

/*this function sorts the wins as well as the corresponding team names 
form highest to lowest*/
void sortData(WinRecord *standings,int size);

//this function prints out the sorted wins and the corresponding team names
void displayData(WinRecord *standings,int size);

int main()
{
  int size;
  WinRecord *record=NULL;

  cout<<"\nHow many teams will be entered?"<<endl;
  cin>>size;

  record= new WinRecord[size];
  
  initializeData(record,size);
  sortData(record,size);
  displayData(record,size);

  for(int i=0; i<size; i++)  
  {                          
    delete [] record[i].name;
    record[i].name=NULL;
  }
  delete [] record;
  record=NULL;

  return 0;
}

char* getLine()
{
  const int size=100;

  char Name[size];

  cin.get();
  cin.getline(Name,size);
  
  int length=strlen(Name);

  char *rAddress= new char[length+1];

  strncpy(rAddress,Name,length);

  //returns the address of the dynamically allocated arry
  return rAddress;
}
  
void initializeData(WinRecord *standings,int size)
{
  for(int i=0;i<size;i++)
  {
    cout<<"\nEnter team #"<<i+1<<":";
    standings[i].name=getLine(); 
    cout<<"\nEnter the wins for team #"<<i+1<<":";
    cin>>standings[i].wins;
  }
}

void sortData(WinRecord *standings,int size)
{  
  bool swapped;
  WinRecord temStandings;

  do
  {
     swapped=false;
     for(int j=0;j<size-1;j++)
     {
       if(standings[j].wins<standings[j+1].wins)
       {
         temStandings=standings[j];
         
         standings[j]=standings[j+1];
          
         standings[j+1]=temStandings;

         swapped=true;
       }
     }        
   }while(swapped);
}

void displayData(WinRecord *standings,int size)
{
  cout<<"\nLeague Standings;"<<endl;
  for(int k=0;k<size;k++)
  {
    cout<<standings[k].name<<":"<<standings[k].wins<<endl;
  }
}
