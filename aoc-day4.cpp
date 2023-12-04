// Part 1

#include<bits/stdc++.h>

using namespace std;

int getNumber(string str){
    // cout<<str<<endl;
    int num = 0;
    for(int i=0; i<str.size(); i++){
        num *= 10;
        num += (str[i] - '0');
    }
    return num;
}

int main(){
    string str;
    long long sum  = 0;
    int bairer = 0;
    
    while(getline(cin, str)){
        bairer++;
        int len = str.size();
        string text = "";
        long long check = 0;
        bool start = false, delim = false;
        unordered_map<int, bool>umap;
        umap.clear();
        
        for(int i=0; i<=len; i++){
            if(i == len || str[i] == '|' || str[i] == ' ')  { delim = true; }
            else if(str[i] >= '0' && str[i] <= '9') { text += str[i]; delim = false;}
            else if(str[i] == ':') { text = ""; start = true;}
            else text = "";
            
            if(str[i] == '|') check = 1;
            if(text.size() > 0 && start && delim){
                int number = getNumber(text);
                if(check){
                    if(umap.find(number) != umap.end()) {
                        check = (check == 0) ? 1 : check * 2;
                        // cout<<bairer<<' '<<check<<endl;
                    }
                }
                else{
                    umap[number] = true;
                }
                text = "";
            }
        }
        if(check != 0)
            sum += (check / 2ll);
    }
    cout<<sum<<endl;
}
