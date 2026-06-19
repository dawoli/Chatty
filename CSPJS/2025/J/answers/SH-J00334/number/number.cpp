#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    int len=0;
    int v[100001];
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            v[len]=s[i]-'0';
            len++;
        }
    }
    sort(v,v+len);
    while(len--){
        cout<<v[len];
    }
    return 0;
}
