#include<bits/stdc++.h>
using namespace std;


bool isDominating(vector<int>&arr){
    int n = arr.size();
    if(n == 0) return false;
    unordered_map<int, int>map;
    for(auto i: arr){
        int zeroC = __builtin_clz(i);
        int rem  = 32-zeroC;
        map[rem]++;
    }

    for(auto& [key, val]: map){
        if(val/n/2) return true;
    }
    return false;
}
int main(){
    vector<int>arr = {1, 3, 2, 4,5 ,62, 4, ,2};
    cout<<isDominating(arr) ? "Yes": "No"<<endl;
    return 0;
}