```
cpp
#include <bits/stdc++.h>

using namespace std;

string digits[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
    string str;
    int sum  = 0;
    while(cin>>str){
        if(str == "q") break;
        cout<<str<<endl;
        int n = str.size();
        int first_d = -1, last_d = -1;
        int fid = -1, sid = -1;
        for(int i=0; i<n; i++){
            if(str[i] >='0' && str[i] <= '9'){
                fid = i;
                first_d = str[i] - '0'; break;
            }
        }

        // Uncomment for Part #2
        /*for(int i=0; i<9; i++){
            int id = str.find(digits[i]);
            if(id != -1){
                if(id < fid || fid == -1){
                    fid = id;
                    first_d = i + 1;
                }
            }
        }*/
        
        for(int i=n-1; i>=0; i--){
            if(str[i] >='0' && str[i] <= '9'){
                sid = i;
                last_d = str[i] - '0'; break;
            }
        }

        // Uncomment for Part #2
        /*for(int i=0; i<9; i++){
            int id = str.find(digits[i], sid + 1);
            while (id != -1) {
                sid = id;
                last_d = i + 1;
                id = str.find(digits[i], id + 1);
            }
        }*/
        
        cout<<first_d<<' '<<last_d<<endl;
        
        int number = first_d*10 + last_d;
        sum += number;
    }
    cout<<sum<<endl;
}
```
