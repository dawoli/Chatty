#include <bits/stdc++.h>

using namespace std;

vector<int> v;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(char i:s){
        if(i>='0'&&i<='9'){
            v.push_back(i-'0');
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i:v){
        cout<<i;
    }
    cout<<endl;
    return 0;
}