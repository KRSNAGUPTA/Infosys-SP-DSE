    // Question 2: Planting Seeds in Pots
    // We are given two arrays:

    // seeds – representing the sizes of seeds.

    // pots – representing the capacities of pots.

    // A seed can be planted in a pot only if:

    // pot >= seed and pot < 2 * seed

    // Each pot can hold at most one seed, and each seed can be planted in at most one pot.

    // The task is to find the maximum number of seeds that can be planted.

    // Example:

    // seeds = [2, 3, 4]
    // pots  = [3, 5, 8]

    // Output: 2

    #include<bits/stdc++.h>
    using namespace std;
    using ll = long long;


    // DP with BitMask

    // int solve(int i, vector<int>&seeds, vector<int>&pots, int mask, vector<vector<int>>&dp ){
    //     if( i == seeds.size()) return 0;
    //     int maxS = 0;
    //     if(dp[i][mask]!= -1) return dp[i][mask];
    //     // cout<<"hello "<<i<<endl;
    //     for(int j =0; j < pots.size(); j++){
    //         if(((1&(mask>>j) )== 0) && pots[j] >= seeds[i] && (ll)pots[j] < ((ll)seeds[i])*2){
                
    //             int temp = solve(i+1, seeds, pots, (mask|(1<<j)), dp);
    //             maxS = max(maxS, 1+ temp);
    //         }
    //     }
    //     maxS = max(maxS, solve(i+1, seeds, pots,mask, dp));
    //     return dp[i][mask] = maxS;
    // }

    int getMaxSeed(int n, vector<int>&seeds, vector<int>&pots){

        // DP Solution

        // int mask = n;
        // vector<vector<int>>dp(n, vector<int>(1<<n, -1));
        // return solve(0,seeds, pots,0, dp);




        // greedy solution

        sort(seeds.begin(), seeds.end());
        sort(pots.begin(), pots.end());
        int i=0;
        int j=0;
        int count;
        while(i<n && j<n){
            int seed = seeds[i];
            int pot = pots[j];
            if(seed > pot) j++;
            if(seed < ((ll)pot)*2); i++; // pot is too big
            if(pot >= seed && pot < 2*1LL*seed){
                count++;
                i++;
                j++;
            }
        }
        return count;
    }

    int main(){
        // cout<<"INput"<<endl;
        int n;
        cin>>n;
        vector<int>seeds(n);
        vector<int>pots(n);
        for(int i=0; i < n; i++){
            int temp;
            cin>>temp;
            seeds[i] = temp;
        }
        for(int i=0; i < n; i++){
            int temp;
            cin>>temp;
            pots[i] = temp;
        }

        cout<<getMaxSeed(n, seeds, pots)<<endl;
    }