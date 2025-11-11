// Problem: Recursion I - factorial, power, print patterns, count digits, sum of array
// Demonstrates basic recursive concepts.

#include <bits/stdc++.h>
using namespace std;

// Factorial
int fact(int n){ return (n<=1)?1:n*fact(n-1); }

// Power
int power(int a,int b){ return (b==0)?1:a*power(a,b-1); }

// Print increasing
void printInc(int n){ if(n==0) return; printInc(n-1); cout<<n<<" "; }

// Print decreasing
void printDec(int n){ if(n==0) return; cout<<n<<" "; printDec(n-1); }

// Count digits
int countDigits(int n){ if(n==0) return 0; return 1+countDigits(n/10); }

// Sum of array
int sumArray(const vector<int>& a,int i=0){ if(i==(int)a.size()) return 0; return a[i]+sumArray(a,i+1); }

int main(){
    cout<<"fact(5)="<<fact(5)<<"\n";
    cout<<"pow(2,5)="<<power(2,5)<<"\n";
    printInc(5); cout<<"\n"; printDec(5); cout<<"\n";
    cout<<"Digits in 1234: "<<countDigits(1234)<<"\n";
    cout<<"Sum of [1,2,3,4]: "<<sumArray({1,2,3,4})<<"\n";
    return 0;
}
