/* Question 2
PART A 
"0-4" === 7 ways

1. 1-1-1-1
2. 1-1-2
3. 1-2-1
4. 2-1-1
5. 2-2
6. 1-3
7. 3-1

PART B
BASE CASES 
V[0] = 1 ways
V[1] = 1 ways
V[2] = 2 ways

GENERAL CASE

V[K] = V[K-1] + V[K-2] + V[K-3]
e.g 
V[4] = V[3] + V[2] + V[1]
V[4] = 4 + 2 + 1
V[4] = 7 ways

*/

// PART C
int countWays(int n){
    int V[n+1];
    V[0] = 1;
    V[1] = 1;
    V[2] = 2;
    // cout<<"array:";
    // cout<<"[";
    for(int i=3;i<n+1;i++){
        V[i] = V[i-1] + V[i-2] + V[i-3];
        // cout<<V[i];

        // if(i==n){
        //     continue;
        // }
        // cout<<",";

    }
    // cout<<"]"<<endl;
    return V[n];
}