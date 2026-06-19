#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n,q,ans;
string ta,tb,tc;
string sa[MAXN];
string sb[MAXN];
string chg(int stp,int sel,string a){
    if(sa[sel].length()+stp-1>a.length()){
        return "0";
    }
    for(int i=0;i<sa[sel].length();i++){
        if(sa[sel][i]==a[stp+i]){
            a[stp+i]=sb[sel][i];
        }else{
            return "0";
        }
    }
    return a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>sa[i]>>sb[i];
    }
    while(q--){
        if(n>=10000){
            cout<<0<<endl;
            continue;
        }
        ans=0;
        cin>>ta>>tb;
        for(int i=0;i<ta.length();i++){
            for(int j=1;j<=n;j++){
                tc=chg(i,j,ta);
                if(tb==tc){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}