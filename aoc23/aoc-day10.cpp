#include <bits/stdc++.h>

using namespace std;

vector<string>grid;
queue<pair<int, int>>Q;
map<pair<int, int>, bool>umap;

int main(){
    string str;
    while(cin>>str){
        grid.push_back(str);
    }
    int sx, sy;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            if(grid[i][j] == 'S'){
                sx = i, sy = j; break;
            }
        }
    }

    int cx = sx, cy = sy;
    umap[{sx, sy}] = true;
    Q.push({sx, sy});
    
    while(!Q.empty()){
        int row = Q.front().first, column = Q.front().second; 
        Q.pop();
        char current_pipe = grid[row][column];
        
        if (row > 0 && (current_pipe == 'S' || current_pipe == '|' || current_pipe == 'L' || current_pipe == 'J')&& (grid[row - 1][column] == '|' || grid[row - 1][column] == '7' || grid[row - 1][column] == 'F') && umap.find(make_pair(row - 1, column)) == umap.end()){
            umap[make_pair(row - 1, column)] = true;
            Q.push(make_pair(row - 1, column));
    }
        
        if (row < (grid.size() - 1) && (current_pipe == 'S' || current_pipe == '|' || current_pipe == '7' || current_pipe == 'F') && (grid[row + 1][column] == '|' || grid[row + 1][column] == 'L' || grid[row + 1][column] == 'J') && umap.find(make_pair(row + 1, column)) == umap.end()){
            umap[make_pair(row + 1, column)] = true;
            Q.push(make_pair(row + 1, column));
        }
        
        if (column > 0 && (current_pipe == 'S' || current_pipe == '-' || current_pipe == '7' || current_pipe == 'J') && (grid[row][column - 1] == '-' || grid[row][column - 1] == 'L' || grid[row][column - 1] == 'F') && umap.find(make_pair(row, column - 1)) == umap.end()){
            umap[make_pair(row, column - 1)] = true;
            Q.push(make_pair(row, column - 1));
        }
        
        if (column < (grid[row].size() - 1) && (current_pipe == 'S' || current_pipe == '-' || current_pipe == 'L' || current_pipe == 'F') && (grid[row][column + 1] == '-' || grid[row][column + 1] == 'J' || grid[row][column + 1] == '7') && umap.find(make_pair(row, column + 1)) == umap.end()){
            umap[make_pair(row, column + 1)] = true;
            Q.push(make_pair(row, column + 1));
        }
    }
    
    int len = umap.size() / 2;
    cout<<len<<endl;
    
}
