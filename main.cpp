#include <iostream>
#include"q1.h"
#include"q2.h"
#include"q3.h"
using namespace std;
void printArray(int * arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int  main(){
    // Question 1
    cout<<"Question 1"<<endl;
    int n = 5;
    int prices[] = {1, 5, 8, 9, 10};
    int costs[] = {1, 2, 3, 4, 1};
    int r[n+1];
    for (int i = 0; i < n+1; i++) {
        r[i] = 0;
    }
    int * revenue = rodCutCost(prices, costs, n,r);
    printArray(revenue, n+1);
    // Question 2 - Part C
    cout<<"Question 2 - Part C"<<endl;
    int k = 8;
    cout<<"Number of ways to climb "<<k<<" steps: "<<countWays(k)<<endl;
    //Question 3 - Part C
    cout<<"Question 3- Part C"<<endl;
    string X = "character";
    int len = X.length();
    cout<<"Longest Palindromic Subsequence: "<<longestPalindrome(X,len)<<endl;



    return 0;
   
}