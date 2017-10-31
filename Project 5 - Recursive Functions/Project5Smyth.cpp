#include <iostream>
#include <string> 
#include <fstream>
using namespace std;

int count(int arr[], int target, int first, int last);
bool isPal(string s, int first, int last);
string reverse(string s, int first, int last);

int main()
{
	int count1[] = { 3, 9, 2, 7, 9, 4, 4, 3, 9 }; 	int count2[] = { 6 }; 	int count3[] = { 4, 6, 2, 3 }; 	int count4[] = { 12 };
	string a = "radar", b = "x", c = "aba", d = "xx", e = "ab", f = "abc", g = "123321", h = "xx1x";
	string aa = "Hello World", bb = "Goodbye", cc = "When in the course of human events";

	cout << "Counts:   " << "\n{ 3, 9, 2, 7, 9, 4, 4, 3, 9 } (target 9) -- " << count(count1, 9, 0, 8) << "\n{ 3, 9, 2, 7, 9, 4, 4, 3, 9 } (target 4) -- " << count(count1, 4, 0, 8) << "\n{ 6 } (target 6) -- " << count(count2, 6, 0, 1) << "\n{ 4, 6, 2, 3 } (target 9) -- " << count(count3, 9, 0, 3) << "\n{ 12 } (target 5) -- " << count(count4, 5, 0, 0) << "\n\n";
	cout << "Palindrome:   " << "\nradar -- " << isPal(a, 0, a.length() - 1) << "\nx -- "  << isPal(b, 0, b.length() - 1) << "\naba-- "  << isPal(c, 0, c.length() - 1) << "\nxx-- "  << isPal(d, 0, d.length() - 1) << "\nab -- "  << isPal(e, 0, e.length() - 1) << "\nabc -- "  << isPal(f, 0, f.length() - 1) << "\n123321 -- " << isPal(g, 0, g.length() - 1) << "\nxx1x -- " << isPal(h, 0, h.length() - 1) << "\n\n";
	cout << "Reverse:    " << "\nHello World -- " << reverse(aa, 0, aa.length() - 1) << "\nGoodbye -- "  << reverse(bb, 0, bb.length() - 1) << "\nWhen in the course of human events -- "  << reverse(cc, 0, cc.length() - 1) << "\n";
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
	int position = s.find(' ', first);
	string xtract;
	if (position == -1) { for (int i = first; i <= last; i++) xtract += s[i]; return xtract; }
	else { 
		for (int i = first; i <= position - 1; i++) xtract += s[i]; 
		return reverse(s, position+1, last) + ' ' + xtract; }
}
