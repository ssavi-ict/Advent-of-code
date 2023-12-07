#include <bits/stdc++.h>

using namespace std;

int getNumber(string num){
    int number = 0;
    for(int i=0; i<num.size(); i++){
        number *= 10;
        number += (num[i] - '0');
    }
    return number;
}

vector<int>v1, v2;

long long populate(string & line1, vector<int> & v){
    string number = "";
    long long bignumber = 0;
    for(int i=0; i<line1.size(); i++){
        if(line1[i] >= '0' && line1[i]<='9') {
            bignumber *= 10;
            bignumber += (line1[i] - '0');
            number += line1[i];
        }
        else if(number.size() > 0){
            v.push_back(getNumber(number));
            number = "";
        }
    }
    if(number.size() > 0){
        v.push_back(getNumber(number));
        number = "";
    }
    return bignumber;
}

int main(){
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    long long b1 = populate(line1, v1);
    long long b2 = populate(line2, v2);
    
    int ans = 0;
    for(int i=0; i<v1.size(); i++){
        int item1 = v1[i], item2 = v2[i];
        int count = 0;
        for(int j=0; j<=item1; j++){
            int multiply = j * (item1 - j);
            if(multiply > item2) count++;
        }
        
        if(count){
            if(ans == 0) ans = count;
            else ans *= count;
        }
    }
    cout<<"Part 1: "<<ans<<endl;
    
    long long count = 0;
    for(int j=0; j<=b1; j++){
        long long multiply = j * (b1 - j);
        if(multiply > b2) count++;
    }
    cout<<"Part 2: "<<count<<endl;
}
