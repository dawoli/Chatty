#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
string s[100005],s2[100005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>s[i]>>s2[i];
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        ll pos1=-1,pos2=(ll)a.size();
        for(ll i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                break;
            }
            pos1=i;
        }
        for(ll i=a.size()-1;i>=0;i--){
            if(a[i]!=b[i]){
                break;
            }
            pos2=i;
        }
        ll ans=0;
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<a.size();j++){
                string t="",t2="";
                for(ll k=j;k<min((ll)a.size(),j+(ll)s[i].size());k++){
                    t+=a[k];
                    t2+=b[k];
                }
                if(t==s[i]&&t2==s2[i]&&j-1<=pos1&&j+(ll)s[i].size()>=pos2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}