#include <bits/stdc++.h>
using namespace std;
priority_queue<int> num;
string s;
int main(){
    ifstream fin("number.in");
    ofstream fout("number.out");
    fin>>s;
    for(int i=0;i<s.size();++i){
        if(s[i]<='9'&&s[i]>='0'){
            num.push(int(s[i]-'0'));
        }
    }
    while(!num.empty()){
        fout<<num.top();
        num.pop();
    }
    fout<<endl;
    return 0;
}