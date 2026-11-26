#include<bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> &nums, int k) {
        unordered_map<int, int>map;
        map[0] = 1;
        int count=0;
        int pre =0;
        for(int i=0; i < nums.size(); i++){
            pre^= nums[i];
            if(map.find(pre^k) != map.end()){
                count+=map[pre^k];
            }
            map[pre]++;

        }
        return count;
    }
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i <n; i++){
        int temp;
        cin>>temp;
        nums[i] = temp;
    }
    int k;
    cin>>k;
    cout<<subarraysWithXorK(nums, k)<<endl;
    return 0;
}