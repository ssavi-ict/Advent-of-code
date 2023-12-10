#include <bits/stdc++.h>

using namespace std;

long long getNumber(string str){
    long long number = 0, n = str.size();
    int i = (str[0] == '-') ? 1 : 0;
    
    for(; i<n; i++){
        number *= (long long)10;
        number += (long long)(str[i] - '0');
    }
    if(str[0] == '-') number = -number;
    return number;
}

pair<int, long long> getLastNum(vector<long long> & num){
    long long total  = 0;
    vector<long long>diff, last, first;
    while(true){
        long long gap; long long total = 0;
        first.push_back(num[0]);
        for(int i=1; i<num.size(); i++){
            gap = (num[i] - num[i-1]);
            diff.push_back(gap);
        }
        last.push_back(num.back());
        int j = 0;
        for(j=0; j<diff.size(); j++){
            if(diff[j] != 0) break;
        }
        if(j == diff.size()) break;
        num.clear(); num = diff; diff.clear();
    }
    long long lnum = 0, fnum = 0;
    for(int i=0; i<last.size(); i++){
        lnum += last[i];
    }
    for(int i=first.size()-1; i>=0; i--){
        fnum = (first[i] - fnum);
    }
    return make_pair(fnum, lnum);
}

int main(){
    string str;
    long long ansl = 0, ansf = 0;
    while(getline(cin, str)){
        stringstream ss(str);
        vector<long long>numbers; string s;
        while(ss >> s){
            numbers.push_back(getNumber(s));
        }
        pair<int, long long> pNum = getLastNum(numbers);
        cout<<pNum.first<<' '<<pNum.second<<endl;
        ansf += pNum.first;
        ansl += pNum.second;
    }
    cout<<ansf<<' '<<ansl<<endl;
}
