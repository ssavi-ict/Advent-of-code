#include <bits/stdc++.h>

using namespace std;

// string pp = "AKQJT98765432"; // Part 1 Priority
string pp = "AKQT98765432J"; // Part 2 Priority

char findKind(string hand){
    vector<int>counter;
    int countJ = 0;
    for(int i=0; i<hand.size(); i++){
        if(hand[i] == 'J') { hand[i] = '#'; countJ++; continue; }
        if(hand[i] == '#') continue;
        int same = 1;
        for(int j=i+1; j<hand.size() ;j++){
            if(hand[i] == hand[j]) {
                hand[j] = '#'; same++;
            }
        }
        counter.push_back(same);
    }
    sort(counter.begin(), counter.end());
    if(counter.size() == 0) counter.push_back(countJ); // Part 2
    else counter[(counter.size() - 1)] += countJ; // Part 2
    
    if(counter.size() == 1 && counter[0] == 5) return '5';
    if(counter.size() == 2 && counter[1] == 4) return '4';
    if(counter.size() == 2 && counter[1] == 3) return 'F';
    if(counter.size() == 3 && counter[2] == 3) return '3';
    if(counter.size() == 3 && (counter[1] == 2 && counter[2] == 2)) return 'T';
    if(counter.size() == 4 && counter[3] == 2) return 'O'; 
    return 'H';
}

inline bool compare(string a, string b){
    for(int i=0; i<a.size(); i++){
        if(a[i] == b[i]) continue;
        for(int j=0; j<pp.size(); j++){
            if(a[i] == pp[j]) return false;
            if(b[i] == pp[j]) return true;
        }
    }
    return true;
}

vector<string>kinddb[7];
unordered_map<string, int>umap;

int main(){
    string hand;
    int bid;
    while(cin>>hand>>bid){
        umap[hand] = bid;
    }
    
    string kstr = "HOT3F45";
    for(int i=0; i<kstr.size(); i++){
        for(auto it:umap){
            char kindV = findKind(it.first);
            // cout<<it.first<<' '<<kindV<<endl;
            if(kstr[i] == kindV) kinddb[i].push_back(it.first);
        }   
    }
    
    long long sum = 0;
    int rank = 1;
    for(int i=0; i<kstr.size(); i++){
        sort(kinddb[i].begin(), kinddb[i].end(), compare);
        for(int j=0; j<kinddb[i].size(); j++){
            cout<<kinddb[i][j]<<' '<<umap[kinddb[i][j]]<<endl;
            sum += (rank * umap[kinddb[i][j]]);
            rank++;
        }
    }
    cout<<sum<<endl;
}
