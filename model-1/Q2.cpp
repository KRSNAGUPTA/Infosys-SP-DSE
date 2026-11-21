// Q2 (Medium): Longest Balanced Window

// You are given an array of n integers and an integer K. Find the length of the longest contiguous subarray in which max − min ≤ K.

// Input: First line n K. Second line contains the array.
// Output: A single integer.
// Constraints: 1 ≤ n ≤ 2·10^5; 0 ≤ K ≤ 10^9; values are between 0 and 10^9.

// Sample input:
// 5 3
// 1 3 2 6 4

// Sample output:
// 3

#include<bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int k, vector<int>&arr){
    int maxE = *max_element(arr.begin()+i, arr.begin()+j+1);
    int minE = *min_element(arr.begin()+i, arr.begin()+j+1);
    cout<<i<<" "<<j<<" "<<maxE<<" "<<minE<<endl;
    return maxE - minE <= k;
}
int maxWindow(int k, vector<int>&arr){
    int n = arr.size();
    int i =0;
    int j = 0;
    int ans = 0;
    while(j<n){
        if(valid(i,j, k, arr)){
            ans = max(ans, j-i+1);
            j++;
        }else{
            i++;
            while(!valid(i, j, k, arr)){
                i++;
            }
        }
    }
    return ans;
}
int main(){
    int n, k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i = 0 ; i < n; i++){
        int x;
        cin>>x;
        arr[i] =x;
    }
    cout<<endl<<maxWindow(k, arr)<<endl;
    return 0;
}