#include<bits/stdc++.h>
using namespace std;


// Given an array [1...n] of integers. A dominating group is a subset of integers which have same bit length (except leading zeros)
// and the group size is > N / 2. return if exists or -1.

// g++ dom-group.cpp -o main && ./main

// for 32 Bit 
int getBitLen(int x){
    return x == 0 ? 1 : 32 - __builtin_clz(x); // for x == 0 gives undefined
}
int isDominating(vector<int>&arr){
    int n = arr.size();
    if(n == 0) return false;
    unordered_map<int, int>map;
    for(auto i: arr){
        int bitLen  = getBitLen(i);
        map[bitLen]++;
    }

    for(auto& [key, val]: map){
        if(val*2 > n) return key;
    }
    return -1;
}
int main(){
    vector<int>arr =  {4, 5, 6, 7, 8, 9, 1}; // ans 3
    cout<<isDominating(arr)<<endl;
    vector<int>arr2 = {1, 2,4}; // ans -1
    cout<<isDominating(arr2)<<endl; 
    return 0;
}