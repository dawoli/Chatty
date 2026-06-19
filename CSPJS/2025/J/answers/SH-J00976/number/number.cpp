#include<bits/stdc++.h>
using namespace std;
int a[1000000],cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            a[cnt++]=s[i]-'0';
    }
    sort(a,a+cnt);
    while(cnt--){
        cout<<a[cnt];
    }
    return 0;
}
