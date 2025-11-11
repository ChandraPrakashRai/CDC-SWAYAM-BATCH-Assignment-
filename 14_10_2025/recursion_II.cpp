// Problem: Recursion II - pivot index, remove duplicates, fibonacci, tower of hanoi
// Demonstrates intermediate recursion applications.

#include <bits/stdc++.h>
using namespace std;

// Fibonacci
int fib(int n){ if(n<=1) return n; return fib(n-1)+fib(n-2); }

// Remove duplicates recursively
string removeDupRec(const string& s,int i=0,string seen=""){
    if(i==(int)s.size()) return "";
    char c=s[i];
    if(seen.find(c)!=string::npos) return removeDupRec(s,i+1,seen);
    return c+removeDupRec(s,i+1,seen+c);
}

// Tower of Hanoi
void towerOfHanoi(int n,char from,char to,char aux){
    if(n==0) return;
    towerOfHanoi(n-1,from,aux,to);
    cout<<"Move "<<n<<" from "<<from<<" to "<<to<<"\n";
    towerOfHanoi(n-1,aux,to,from);
}

// Find pivot index (sum left=right)
int pivotIndex(vector<int>& a,int i=0,int leftSum=0,int total=0){
    if(i==0){ for(int x:a) total+=x; }
    if(i==(int)a.size()) return -1;
    total -= a[i];
    if(leftSum==total) return i;
    return pivotIndex(a,i+1,leftSum+a[i],total);
}

int main(){
    vector<int> a={1,7,3,6,5,6};
    cout<<"Pivot index: "<<pivotIndex(a)<<"\n";
    cout<<"Fib(6): "<<fib(6)<<"\n";
    cout<<"RemoveDup('abacb')="<<removeDupRec("abacb")<<"\n";
    towerOfHanoi(3,'A','C','B');
    return 0;
}
