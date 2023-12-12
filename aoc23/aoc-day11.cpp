#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>>coord;
int arr[500];

int main(){
    vector<string>grid;
    string str;
    int i = 0;
    while(getline(cin, str)){
        bool hash = false;
        string new_str = "";
        for(int j=0; j<str.size(); j++){
            if(str[j] == '#') {
                hash = true; break;
            }
            new_str += ".";
        }
        if(!hash){
            grid.push_back(new_str);
        }
        grid.push_back(str);
    }

    for(int j=0; j<grid[0].size(); j++){
        bool hash = false;
        for(int i=0; i<grid.size(); i++){
            if(grid[i][j] == '#') { hash = true; break; }
        }
        if(!hash){
            arr[j] = true;
        }
    }
    
    vector<string>newGrid;
    int col = grid[0].size();
    for(int i=0; i<grid.size(); i++){
        string temp = "";
        for(int j=0; j<col; j++){
            temp += grid[i][j];
            if(arr[j]) temp += ".";
        }
        newGrid.push_back(temp);
        grid[i].clear();
    }
    
    grid = newGrid;
    
    
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            // cout<<grid[i][j];
            if(grid[i][j] == '#') {
                coord.push_back({i, j});
            }
        }
        // cout<<endl;
    }

    int sum = 0, c = 0;
    for(i=0; i<coord.size(); i++){
        for(int j=i+1; j<coord.size(); j++){
//            cout<<c<<endl; c++;
            sum += abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second);
        }
    }
    cout<<sum<<endl;
    
    vector<pair<int, int>>p2coord;
    for(int j=0; j<grid[0].size(); i++){
        for(int i=0; i<grid.size(); j++){
            if(grid[i][j] == '#'){
                
            }
        }
    }
    
}
