//Haoran Zhang Assignment 7
//this program is consists of 5 functions to deal with c-strings

#include <iostream>
#include <cstring>
using namespace std;

/*this function returns the last index where 
  the target char can be found in the string*/
int lastIndexOf(char *s, char target);

/*this function alters any string that 
  is passed in by reversing*/
void reverse(char *s);

/*this function finds all instances of the char target in the string 
  and replaces them with replacementChar,then returns the number of 
  replacements it makes*/
int replace(char *s, char target, char replacementChar);

/*this function returns the index in string s 
  where the substring can first be found*/
int findSubstring(char *s, char substring[]); 

/*this function returns true if the argument string is a palindrome. 
  It returns false if it is not*/
bool isPalindrome(char *s);

void reverseWords(char *s);

int main()
{
  char string[100];
  char targetChar;
  int lastIndex;

  cout<<"\nEnter a string: ";
  cin>>string;
  cout<<"\nA target character in the above string: ";
  cin>>targetChar;
  
  lastIndex=lastIndexOf(string,targetChar);
  
  cout<<"\nThe last index of the target character in the string is "<<lastIndex<<" ."<<endl;



  char reveseString[100];
  cout<<"\nA string to reverse: ";
  cin>>reveseString;
  
  reverse(reveseString);



  char originalString[100];
  char targetLetter;
  char replacement;
  int counter;

  cout<<"\nA string to replace: ";
  cin.get(); 
  cin.getline(originalString,100);
  
  cout<<"\nA target charecter in the above string: ";
  cin>>targetLetter;
  cout<<"\nReplacement character: ";
  cin>>replacement;
  
  counter=replace(originalString, targetLetter, replacement);

  cout<<"\nNumber of replacement: "<<counter<<endl;


  
  char searchString[100];
  char substring[100];
  int  subIndex;

  cout<<"\nA string to search for substring: ";
  cin>>searchString;
  cout<<"\nA substring in the above string: ";
  cin>>substring;
  subIndex=findSubstring(searchString,substring);

  cout<<"\nThe substring can be found at index "<<subIndex<<endl;



  char palindrome[100];
  bool status;

  cout<<"\nEnter a Palindrome: ";
  cin>>palindrome;
  
  status=isPalindrome(palindrome);

  if(status==true)
    cout<<"\nIt is a palindrome.";
  else
    cout<<"\nIt is not a palindrome.";



  char String[100];

  cout<<"\nEnter a string to be reversed: ";
  cin.get();
  cin.getline(String,100);
  
  reverseWords(String);

  
  return 0;
}

int lastIndexOf(char *s, char target)
{
  int length;
  length=strlen(s);

  for(int i=0; i<length; i++)
  {
    if(target==s[i])
      return i;
  }
  return -1;
}

void reverse(char *s)
{
  int length;
  length=strlen(s);
  char tem;

  for(int i=0; i<length/2; i++)
  {
    tem=s[length-1-i];
    s[length-1-i]=s[i];
    s[i]=tem;
  }
  cout<<"\nThe revesed string: "<<s<<endl;
}

int replace(char *s, char target, char replacementChar)
{
  int length;
  int count=0;  
  length=strlen(s);

  for(int i=0; i<length; i++)
  {
    if(target==s[i])
    {
      s[i]=replacementChar;
      count++;
    }
  }
  cout<<"\nA replaced string: "<<s<<endl;

  return count;
}

int findSubstring(char *s, char substring[])
{
  int j;
  int slength, sublength, index=-1;
  slength=strlen(s);
  sublength=strlen(substring);
  
  for(int i=0;i<slength;i++)
  {
    int k=i;
    for(j=0; j<sublength; j++)
    {
      if(s[k]!=substring[j])
      {
        break;
      }
      k++;
    }

    if(j==sublength)
    {
      index=i;
      break;
    }
  }

  return index; 
}

bool isPalindrome(char *s)
{
  int length;
  bool status;

  length=strlen(s);
  for(int i=0; i<length/2; i++)
  {
    if(s[i]!=s[length-1-i])
    {
      status=false;
      break;
    }
    status=true;
  }

  return status;
}  

void reverseWords(char *s)
{
  int length=strlen(s);
  int count=0;
  for (int i=0;i<length;i++)
  {
    if (s[i]==' ')
      count++;
  }
  if (count==0)
  {
   cout<<s<<endl;
   return;
  }
  int space[count];
  int k=0;
  for (int i=0;i<length;i++)
  {
    if (s[i]==' '){
      space[k]=i;
      k++;}
  }
  char string[length];
  k=count-1;
  int i=0;
  for (int j=space[count-1]+1;j<length;j++)
  {
    string[i]=s[j];
    i++;
  }
  string[i]=' ';
  i++;
  while(k>0)
  {
    for (int j=space[k-1]+1;j<space[k];j++)
    {
      string[i]=s[j];
      i++;
    }
    string[i]=' ';
    i++;
    k--;
  }

  for (int j=0;j<space[0];j++)
    {
      string[i]=s[j];
      i++;
    }
    string[i]='\0';
  cout<<string<<endl;
}
