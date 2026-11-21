// Q1 (Easy): Grid Query Operations

// You are given an n × m grid of integers. Then q queries follow, each of one of these types:

// 1 r x: add x to every cell of row r (1-indexed).
// 2 r: print the sum of all cells in row r.
// 3 c: print the maximum value in column c.

// Input: First line n m. Next n lines contain the grid. Next line contains q. Then q query lines.
// Output: One line for each type 2 or type 3 query.
// Constraints: 1 ≤ n, m ≤ 300; 1 ≤ q ≤ 10^5; |values| ≤ 10^9. Use 64-bit sums.
// Sample input:

// 2 3
// 1 2 3
// 4 5 6
// 4
// 2 1
// 3 2
// 1 1 10
// 2 1

// Sample output:

// 6
// 5
// 36
#include<bits/stdc++.h>
using namespace std;
void addX(int row, int x, vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();

    for(int i=0; i < n; i++){
        grid[row-1][i] += x;
    }
}

long long sumR(int row, vector<vector<int>>&grid){
    int m = grid.size();
    int n = grid[0].size();
    long long sum = 0;
    for(int i=0; i < n; i++){
        sum+=grid[row-1][i];
    }
    return sum;
}

int maxC(int col, vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    int mxC = 0;
    for(int i=0; i <m; i++){
        mxC= max(mxC, grid[i][col-1]);
    }

    return mxC;
}
int main(){
    int n, m;
    cin>>n;
    cin>>m;
    vector<vector<int>>grid(n, vector<int>(m, 0));
    for(int i=0; i <n; i++){
        for(int j=0; j<m; j++){
            int num = 0;
            cin>>num;
            grid[i][j]=num;
        }
    }

    int q;
    cin>>q;

    while(q--){
        int type;
        cin >>type;
        if(type==1){
            //r x 
            int r, x;
            cin>>r>>x;
            
            addX(r,x, grid);

        }else if(type == 2){
            int r;
            cin>>r;
            cout<<sumR(r, grid)<<endl;
        }else{
            int c;
            cin>>c;
            cout<<maxC(c, grid)<<endl;
        }
    }
    cout<<endl;
    return 0;
}