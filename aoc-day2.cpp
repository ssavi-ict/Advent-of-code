#include <bits/stdc++.h>

using namespace std;

int makeint(string s){
    int number = 0;
    for(int i=0; i<s.size(); i++){
        number = number * 10;
        number += (s[i] - '0');
    }
    return number;
}

int main(){
    string str;
    int sum  = 0, id = 1;
    long long longsum  = 0;
    while(getline(cin, str)){
        if(str == "q") break;
        cout<<str<<endl;
        int red = 0, green = 0, blue = 0;
        bool sfound = false, cfound = false;
        string color = "";
        int number;
        for(int i=0; i<str.size(); i++){
            if(str[i] == ':') { cfound = true; continue; }
            else if(cfound){
                if(str[i] == ' '){
                    if(color[0] >= '0' && color[1]<='9'){
                        number = makeint(color);
                        // cout<<str<<' '<<color<<' '<<number<<endl;
                    }
                    color = "";
                }
                else if(str[i] == ',' || str[i] == ';'){
                    if(color[0] == 'r') red = max(red, number);
                    if(color[0] == 'b') blue = max(blue, number);
                    if(color[0] == 'g') green = max(green, number);
                    color = ""; number = 0;
                }
                else{
                    color += str[i];
                }
            }
        }
        if(color[0] == 'r') red = max(red, number);
        if(color[0] == 'b') blue = max(blue, number);
        if(color[0] == 'g') green = max(green, number);
        // cout<<red<<' '<<green<<' '<<blue<<endl;
        if(red <= 12 && green <= 13 && blue <= 14) {
            cout<<id<<endl;
            sum += id;
        }
        longsum += (red * green * blue);
        id++;
    }
    cout<<sum<<' '<<longsum<<endl;
}
