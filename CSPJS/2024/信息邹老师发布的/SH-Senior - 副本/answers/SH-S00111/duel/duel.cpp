#include<bits/stdc++.h>
using namespace std;
int n,r[100005];
int s[100005],tmp,ans;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>r[i];
        ++s[r[i]];
    }
    for(int i=0;i<=1e5;++i){
        if(tmp==0) tmp+=s[i];
        else{
            if(tmp>s[i]) ans+=s[i];
            else ans+=tmp,tmp=s[i];
        }
    }
    cout<<n-ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
