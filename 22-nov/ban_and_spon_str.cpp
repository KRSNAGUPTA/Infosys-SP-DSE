// Question 1: Minimum Cost with Ban and Sponsor Strings
// We are given:

// An integer N representing the number of rows.

// A cost matrix with N rows and 4 columns, corresponding to the characters a, b, c, and d.

// Two comma-separated strings: ban and sponsor.

// The task is to determine the minimum total cost while following the restrictions involving the banned and sponsored characters.

// Example:

// N = 2

// 5 1 1 1
// 5 1 1 1

// ban = ba,cc,dd
// sponsor = a

// Output: 6




#include<bits/stdc++.h>
using namespace std;
int getBitMask(string s){
    int mask = 0;
    for(int i=0; i < s.size(); i++){
        int c = s[i]-'a';
        mask = mask |(1 << c);
    }
    return mask;
}
bool isSpon(int mask, int i){
    // i-1;
    return 0 != (1&mask>>i);
}

vector<vector<vector<int>>>dp;
int solve(int i, int prevC, vector<vector<int>>&arr, vector<vector<bool>>&banS, int currM, int& targetMask){
    if(i==arr.size()){
        if(currM == targetMask) return 0;
        return INT_MAX;
    }
    if(dp[i][prevC][currM] != -1) return dp[i][prevC][currM];
    int minCost = INT_MAX;
    for(int currC = 0; currC <4; currC++){
        if(prevC != 4 && banS[prevC][currC]) continue;
        int mask = currM;
        if(isSpon(targetMask, currC)){
            mask = currM |(1<<currC);
        }
        int currCost =  solve(i+1, currC, arr,banS, mask, targetMask);

        if(currCost != INT_MAX){
            currCost += arr[i][currC];
            minCost = min(minCost, currCost);
        }
    }
    return dp[i][prevC][currM] = minCost;
}
int getMinCost(int n, vector<vector<int>>&arr, string& ban, string &spo){
    if(n == 0) return 0;
    vector<vector<bool>>banS(4, vector<bool>(4,false));
    for(int i= 0; i < ban.size(); i+=3){
        cout<<i<<" "<<ban.size()<<endl;
        banS[ban[i]-'a'][ban[i+1]-'a'] = true;
    }
    dp.assign(n+1, vector<vector<int>>(5, vector<int>(32,-1)));
    int mask = getBitMask(spo);
    return solve(0, 4,arr, banS,0,mask);
}



int main(){
    int n;
    cin >> n;
    vector<vector<int>>arr(n, vector<int>(4, 0));
    for(int i=0; i < n; i++){
        for(int j=0; j < 4; j++){
            int cost;
            cin>>cost;
            arr[i][j] = cost;
        }
    }
    string ban, spo;
    // getline(cin, ban);
    // getline(cin, spo);
    cin>>ban;
    cin>>spo;

    cout<<getMinCost(n, arr, ban, spo)<<endl;
}