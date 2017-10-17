// CS 536, PROJECT 4, Ravela Smyth  

#include <stack>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


string infixToPostfix(string exp);
string postfixToPrefix(string exp); 
bool precedence(char a, char b);
double evaluatePostfix(string exp); 
string removespaces(string a);
 
int main() 
{ 
    string exp; 
    ifstream file;
    file.open("input.txt");

    cout << "infix\t\t\tprefix\t\tpostfix\t\tvalue\n\n";

    while(getline(file, exp)) {
	cout << removespaces(exp) 
	     << (exp.length() > 14 ? "\t\t": "\t\t\t") << postfixToPrefix(infixToPostfix(exp)) 
             << (postfixToPrefix(infixToPostfix(exp)).length() > 7 ? "\t": "\t\t") <<infixToPostfix(exp) 
             << (infixToPostfix(exp).length() > 7 ? "\t": "\t\t")<<evaluatePostfix(infixToPostfix(exp)) << '\n';
	}

   file.close();  
}

string removespaces(string a)
{ string b;
	for (int i= 0; i < a.length(); i++)
		if(a[i] != ' ') b += a[i];	
	return b;
}

string infixToPostfix(string exp)
{
	stack<char> hold;
	string postfix; 
	for (int i = 0; i<exp.length(); i++) 
	{
		if (exp[i] >= 'A' && exp[i] <= 'Z') postfix += exp[i]; 
		else if (exp[i] == '(') hold.push(exp[i]);
		else if (exp[i] == ')') {while (hold.top() != '(') {postfix += hold.top(); hold.pop();} hold.pop();}
		else if (exp[i] != ' ' ) {
			while (!hold.empty() && !precedence(exp[i], hold.top()) && hold.top() != '(') 
				{postfix += hold.top(); hold.pop();} 
			hold.push(exp[i]); 
		}
	}

	while (!hold.empty()){postfix += hold.top(); hold.pop();} 

	return postfix;   

}

string postfixToPrefix(string exp) 
{
	stack<string> hold;
	string prefix; 
	for (int i = 0; i<exp.length(); i++) {
		if (exp[i] >= 'A' && exp[i] <= 'Z') { hold.push(string(1, exp[i]));}
		else if (exp[i] != ' ' ) {string A = hold.top();  hold.pop(); string B = hold.top(); hold.pop(); hold.push(exp[i] + B + A);}; 	
	} 
	return hold.top(); 
}

bool precedence(char a, char b) {return (a == '*' || a == '/') && ( b == '+' || b == '-') ? true:false;}


double evaluatePostfix(string exp) {
	stack<double> hold;
	double value; 
	for (int i = 0; i<exp.length(); i++) 
	{
		if (exp[i] >= 'A' && exp[i] <= 'Z') hold.push(exp[i]-'A'+2);
		else { 
		    double A = hold.top();  hold.pop(); double B = hold.top(); hold.pop();
		    switch (exp[i])
			{
			case '+':
			  hold.push(B+A);      
			  break;
			case '-':
			  hold.push(B-A);
			  break;
			case '*':
			  hold.push(B*A);
			  break;
			case '/':
			  hold.push(B/A);
			  break;
			}
		};  
	}
	return hold.top(); 
}

