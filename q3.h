#include <iostream>
#include <string>
using namespace std;

//Question-3 - Part C

int generateLPS(char** b, string X, int i, int j, int** S) {
  if (i > j)
    return 0; //row > col
  else if (i == j)
    return 1; // row == col
  else if (X[i] == X[j]) {
    b[i][j] = '/';
    return 2 + generateLPS(b, X, i + 1, j - 1, S);
  } else {
    if (S[i + 1][j] > S[i][j - 1]) { // same col down row
      b[i][j] = '^';
      return generateLPS(b, X, i + 1, j, S);
    } else { // same row prev col
      b[i][j] = '<';
      return generateLPS(b, X, i, j - 1, S);
    }
  }
}

string longestPalindrome(string X, int n){
    int ** S = new int*[n];
    char ** b = new char*[n];
    for(int i=0;i<n;i++){
        S[i] = new int[n];
        b[i] = new char[n];
    }
    for(int i=0;i<n;i++){
        S[i][i] = 1;
    }
    for(int i = n-2;i>=0;i--){
        for (int j = i+2;j<n;j++){
            if(X[i]==X[j]){
                S[i][j] = 2 + S[i+1][j-1];
            }
            else{
                S[i][j] = max(S[i+1][j],S[i][j-1]);

            }
        }   
    }
    generateLPS(b,X,0,n-1,S);
    string lps(S[0][n-1],'\0');
    int i = 0;
    int j = n-1;
    // backtrack the direction array b to find the longest palindrome
    while (i <= j) {
        if (b[i][j] == '/') {
            lps[i] = X[i];
            lps[j] = X[j];
            i++;
            j--;
        } else if (b[i][j] == '^') {
            lps[i] = X[i + 1];
            i++;
        } else {
            lps[j] = X[j - 1];
            j--;
        }
    }

    for(int i=0;i<n;i++){
        delete [] S[i];
        delete [] b[i];
    }
    delete [] S;
    delete [] b;
    return lps;

}