#include <iostream>
#include <limits.h>
using namespace std;
int * rodCutCost(int * prices, int * usedCosts, int n,int *revenue){
    
    revenue[0] = 0;
    
    for(int i=1;i<=n;i++){
        int maxRevenue = INT_MIN;
        for(int j=1;j<=i;j++){
            maxRevenue = max(maxRevenue, prices[j] + revenue[i-j] - usedCosts[i]);
        }
        revenue[i] = maxRevenue;

    }
    return revenue;
    
}