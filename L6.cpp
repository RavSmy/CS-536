// CS 536, PROJECT 5, Ravela Smyth  


#include <iostream>
#include <string> 
using namespace std;
 
int count(int arr[], int target, int first, int last);
bool isPal(string s, int first, int last);
string reverse(string s, int first, int last );
int lastspace(string s, int last);

int main() 
{ 

    string s = "ello all";
    cout << reverse(s, 0, s.length() -1 ); 

}

int count(int arr[], int target, int first, int last)
{
    if (first == last) return arr[0] == target ? 1 : 0; 
    else return (arr[first] == target ? 1 : 0) + count(arr, target, first+1, last);
     
}

bool isPal(string s, int first, int last) 
{
    if (first == last || first == last - 1) return s[first] == s[last] ? true : false;
    else return (s[first] == s[last] ? true : false) && isPal(s, first + 1, last - 1); 
}

string reverse(string s, int first, int last )
{
     int position = lastspace(s, last);
     string xtract; 
     if (position == 0) {for (int i = position-1; i <= last; i++) xtract+=s[i]; return xtract;}
     else {for (int i = position+1; i <= last; i++) xtract+=s[i]; return xtract + ' ' + reverse(s, 0, position-1);  }
} 

int lastspace(string s, int last) 
{
    int position = 0;    
    for (int i = 0 ; i < last; i++) if (s[i] == ' ') position = i;
    return position; 
}
