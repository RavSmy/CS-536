#include <iostream>
#include <string> 
#include <fstream>
using namespace std;

int count(int arr[], int target, int first, int last);
bool isPal(string s, int first, int last);
string reverse(string s, int first, int last);
int lastspace(string s, int last);

int main()
{
	int count1[] = { 3, 9, 2, 7, 9, 4, 4, 3, 9 }; 	int count2[] = { 6 }; 	int count3[] = { 4, 6, 2, 3 }; 	int count4[] = { 12 };
	string a = "radar", b = "x", c = "aba", d = "xx", e = "ab", f = "abc", g = "123321", h = "xx1x";
	string aa = "Hello World", bb = "Goodbye", cc = "When in the course of human events";
	
	//cout << "Counts:   " << count(count1, 9, 0, 8) << ", " << count(count1, 4, 0, 8) << ", " << count(count2, 6, 0, 1) << ", " << count(count3, 9, 0, 3) << ", " << count(count4, 5, 0, 0) << '\n';
	//cout << "Palindrome:   " << isPal(a, 0, a.length() - 1) << ", " << isPal(b, 0, b.length() - 1) << ", " << isPal(c, 0, c.length() - 1) << ", " << isPal(d, 0, d.length() - 1) << ", " << isPal(e, 0, e.length() - 1) << ", " << isPal(f, 0, f.length() - 1) << ", " << isPal(g, 0, g.length() - 1) << ", " << isPal(h, 0, h.length() - 1) << '\n';
	cout << "Reverse:    " << reverse(aa, 0, aa.length() - 1) << ", " << reverse(bb, 0, bb.length() - 1) << ", " << reverse(cc, 0, cc.length() - 1) << "\n";
}

int count(int arr[], int target, int first, int last)
{
	if (first == last) return arr[last] == target ? 1 : 0;
	else return (arr[first] == target ? 1 : 0) + count(arr, target, first + 1, last);

}

bool isPal(string s, int first, int last)
{
	if (first == last || first == last - 1) return s[first] == s[last] ? true : false;
	else return (s[first] == s[last] ? true : false) && isPal(s, first + 1, last - 1);
}

string reverse(string s, int first, int last)
{
	int position = lastspace(s, last);
	string xtract;
	if (position == 0) { for (int i = position - 1; i <= last; i++) xtract += s[i]; return xtract; }
	else { for (int i = position + 1; i <= last; i++) xtract += s[i]; return xtract + ' ' + reverse(s, 0, position - 1); }
}

int lastspace(string s, int last)
{
	int position = 0;
	for (int i = 0; i < last; i++) if (s[i] == ' ') position = i;
	return position;
}
