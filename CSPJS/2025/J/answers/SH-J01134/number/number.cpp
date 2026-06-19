#include<bits/stdc++.h>
using namespace std;
 string s,a;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<sizeof(s);i++){
        if(s[i]>='0' && s[i]<='9'){
            a+=s[i];
        }
    }
    sort(a.begin(),a.end(),cmp);
    cout<<a;
    return 0;
}
