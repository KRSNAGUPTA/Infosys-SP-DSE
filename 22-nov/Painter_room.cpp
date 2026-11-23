// Problem 1: Painter – Room Decoration
// A painter must decorate N rooms. For each room i, the amount of paint required is liters[i] liters.

// Paint can be bought in two ways:

// Individual liters: each liter costs a.

// Large buckets: each bucket has capacity S liters and costs b.

// The painter may buy more paint than required for a room, but any leftover paint from that room cannot be reused for any other room. In other words, each room’s paint purchase is independent.

// Find the minimum total cost to paint all N rooms.

// Input
// An integer N — number of rooms.

// An array liters of length N — paint required for each room.

// An integer a — cost of one liter of paint.

// An integer S — capacity of one large bucket (in liters).

// An integer b — cost of one large bucket.

// Output
// A single integer: the minimum total cost to paint all rooms.

// Constraints (typical)
// 1 <= N <= 10^5

// 1 <= liters[i] <= 10^9

// 1 <= a, S, b <= 10^9

// Examples
// Example 1

// text
// N = 1
// liters = [7]
// S = 4
// a = 1
// b = 5
// Output: 7

// Explanation: Buying 7 individual liters costs 7 * 1 = 7. A bucket costs 5 for 4 liters; buying two buckets costs 10, which is worse.

// Example 2 (corrected)

// text
// N = 1
// liters = [10]
// S = 6
// a = 2
// b = 1
// Output: 2

// Explanation: Buy two large buckets. Each bucket gives 6 liters for cost 1, so two buckets give 12 liters for cost 2. Only 10 liters are needed, and the remaining 2 liters are discarded. This is cheaper than any combination using individual liters.

// Example 3 (multi-room)

// text
// N = 2
// liters = [5, 8]
// S = 4
// a = 3
// b = 10


#include<bits/stdc++.h>
using namespace std;
double getMinCost(int n, vector<int>&liters, int a, int s, int b){
    if(n == 0) return 0;

    int totalC = 0;
    double smallPer = a;
    double largePer = (b+0.0)/s;

    for(auto& ltr: liters){
        int currCost = 0;
        // buy all one liters;
        int allOne = ltr*a;
        // // buy all Large
        int allLarge = ceil(ltr/s) * b;
        // currCost = min(currCost, allOne);
        // currCost = min(currCost, allLarge);
        if(smallPer < largePer){
            totalC += allOne;
            continue;
        }

        int currLtr = ltr;
        while(currLtr > 0){
            if(currLtr > s){
                currLtr -= s;
                currCost +=b; 
            }else{
                int allOneCostRem = currLtr*a;
                currLtr = 0;
                if(allOneCostRem < b){
                    currCost += allOneCostRem;
                }else{
                    currCost += b;
                }
            }
        }
        totalC+=currCost;
    }

    return totalC;
}

int main(){
    int n;
    cin>>n;
    vector<int>liters(n);
    for(int i=0; i<n; i++){
        int ltr;
        cin >>ltr;
        liters[i] = ltr;
    }
    int a, s, b;
    cin>>a>>s>>b;
    cout<<getMinCost(n, liters, a, s, b)<<endl;
}