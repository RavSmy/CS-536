// CS 536, PROJECT 6, Ravela Smyth  

#include <iostream> 
#include <cstdlib>
#include <queue>
using namespace std;

#define SIZE 50 

void sort(int numbers[], int size); 
int digAti(int num, int i);

int main() 
{ 
    srand(time(0));
    int numbers[SIZE];

    cout << "Random Numbers Unsorted ~~ \n"; 
    for(int i = 0 ; i < SIZE ; i++) {
        numbers[i] = rand()%889 + 111;
        cout << numbers[i] << "    ";
        if ((i+1)%10 == 0) cout << '\n';   
    }

    sort(numbers, SIZE); 
    
    cout << "\nRandom Numbers Sorted ~~ \n"; 
    for(int i = 0 ; i < SIZE ; i++) {
        cout << numbers[i] << "    ";
        if ((i+1)%10 == 0) cout << '\n';   
    }

}

void sort(int numbers[], int size){
    queue <int> digits[10]; 
    int digit; 


    for(int k = 0 ; k < 3; k++){

        // Queue them in ith order
        for (int i = 0 ; i < size ; i++) {
            // get digit
            digit = digAti(numbers[i], k);
            digits[digit].push(numbers[i]);
        }

        // Deque
        for (int p = 0, i=0 ; p < 10 ; p++) {
            while (!digits[p].empty()) { numbers[i++]=digits[p].front(); digits[p].pop();} 
        } 

   }

}

int digAti(int num, int i){
    if ( i == 0) return (num%100)%10;
    else if (i == 1) return (num%100)/10;
    return num / 100;    

}
