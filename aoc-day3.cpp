// Part - 1

#include <bits/stdc++.h>

using namespace std;

int dx[8] = {0, 0, -1, 1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};

int main(){
    string str;
    int sum  = 0, id = 1;
    long long longsum  = 0;
    vector<string>grid;
    while(cin>>str){
        grid.push_back(str);
    }
    
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>>affected(m, vector<bool>(n, false));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == '.') continue;
            if(grid[i][j] >= '0' && grid[i][j] <= '9') continue;
            // if(grid[i][j] == '*'){  // Part-II
                for(int ii=0; ii<8; ii++){
                    int u = dx[ii] + i;
                    int v = dy[ii] + j;
                    if(u >= 0 && v >= 0 && u < m && v < n && (grid[u][v] >= '0' && grid[u][v] <= '9')){
                        affected[u][v] =  true;
                    }
                }
            // }
        }
    }
    long long totalSum = 0;
    for(int i=0; i<m; i++){
        int number = 0;
        bool take = false;
        for(int j=0; j<n; j++){
            if(grid[i][j] >= '0' && grid[i][j] <= '9'){
                number *= 10;
                number += (grid[i][j] - '0');
                if(affected[i][j]) take = true;
            }
            else{
                totalSum += number;
                if(take) {
                    // cout<<number<<endl;
                    sum += (long long)number;
                }
                number = 0;
                take = false;
            }
        }
        totalSum += number;
        if(take) {
            // cout<<number<<endl;
            sum += (long long)number;
        }
    }
    cout<<sum<<endl;
}
