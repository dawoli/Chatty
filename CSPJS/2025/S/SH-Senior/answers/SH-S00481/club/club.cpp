#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100010][5],cnt1,cnt2,cnt3,ch[100010],ans;
priority_queue<ll> val;
void solve(){
	cin>>n;
    cnt1=cnt2=cnt3=ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(max({a[i][1],a[i][2],a[i][3]})==a[i][1]){
            ch[i]=1;cnt1++;ans+=a[i][1];
        }else if(max({a[i][1],a[i][2],a[i][3]})==a[i][2]){
            ch[i]=2;cnt2++;ans+=a[i][2];
        }else if(max({a[i][1],a[i][2],a[i][3]})==a[i][3]){
            ch[i]=3;cnt3++;ans+=a[i][3];
        }
    }
    ll cid=0;
    if(cnt1>n/2) cid=1;
    if(cnt2>n/2) cid=2;
    if(cnt3>n/2) cid=3;
    if(cid>0){
        if(cid==1)
            for(int i=1;i<=n;i++)
                if(ch[i]==cid)
                    val.push(-a[i][1]+max(a[i][2],a[i][3]));
        if(cid==2)
            for(int i=1;i<=n;i++)
                if(ch[i]==cid)
                    val.push(-a[i][2]+max(a[i][1],a[i][3]));
        if(cid==3)
            for(int i=1;i<=n;i++)
                if(ch[i]==cid)
                    val.push(-a[i][3]+max(a[i][2],a[i][1]));
        while(val.size()>n/2){
            ans+=val.top();
            val.pop();
        }
        while(val.size()>0) val.pop();
    }
    cout<<ans<<endl;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll T;cin>>T;while(T--) solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}