#include <bits/stdc++.h>
using namespace std;
string s;
int cnt=0;
int mul=10;
int ans[1000010];
int op;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]-'0'<=9){
            ans[cnt]=s[i]-'0';
            cnt++;
        }
    }
    sort(ans,ans+cnt);
    for(int i=cnt-1;i>=0;i--){
        cout<<ans[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
