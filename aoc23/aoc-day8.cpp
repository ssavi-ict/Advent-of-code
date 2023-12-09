#include <bits/stdc++.h>

using namespace std;

string ins;
unordered_map<string, pair<string, string>>routes;
vector<string>starter;
int bucket[1000001];

void joinNet(string str){
    //TNX = (BBN, MXH)
    string from = str.substr(0, 3);
    string left = str.substr(7, 3);
    string right = str.substr(12, 3);
    routes[from] = make_pair(left, right);
    if(str[2] == 'A') starter.push_back(from);
}

int main(){
    string str;
    while(getline(cin, str)){
        if(str.size() == 0) continue;
        if(str.size() != 16 && (str[0]=='R' || str[0]=='L')){
            ins = str; continue;
        }
        joinNet(str);
    }
    cout<<ins<<endl;
    string start = "AAA", end = "ZZZ";  // Part 1
    int id = 0, count = 0;
    while(start != end){
        if(id == ins.size()) id = 0;
        if(ins[id] == 'L') start = routes[start].first;
        else if(ins[id] == 'R') start = routes[start].second;
        id++; count++;
    }
    cout<<count<<endl;
    
    
    
}
