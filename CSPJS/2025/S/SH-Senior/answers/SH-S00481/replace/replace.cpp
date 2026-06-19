#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
struct ObjP{
    string s;
    ll id,len;
    vector<ll> nxt;
} bf[200010],aft[200010];

void calNxtBF(ll id){
    bf[id].nxt.push_back(-2);
    for(int i=1;i<bf[id].len;i++){
        ll tmp=bf[id].nxt[i-1];
        while(tmp>=0&&bf[id].s[tmp+1]!=bf[id].s[i])
            tmp=bf[id].nxt[tmp];
        bf[id].nxt.push_back(tmp+1);
        //cout<<tmp+1<<endl;
    }
    //cout<<endl;
}
void calNxtAFT(ll id){
    aft[id].nxt.push_back(-2);
    for(int i=1;i<aft[id].len;i++){
        ll tmp=aft[id].nxt[i-1];
        while(tmp>=0&&aft[id].s[tmp+1]!=aft[id].s[i])
            tmp=aft[id].nxt[tmp];
        aft[id].nxt.push_back(tmp+1);
        //cout<<tmp+1<<endl;
    }
    //cout<<endl;
}
string tBF,tAFT;
ll l,lft,rt;
ll check(ll id){//tmpBF:pos BF;tmpAFT:posAFT
    ll cnt=0,posBF=0,posAFT=0;
    for(int i=0;i<l;i++){
        posBF++;
        while(posBF>0&&bf[id].s[posBF]!=bf[id].s[i])
            posBF=bf[id].nxt[posBF-1]+1;
        posAFT++;
        while(posAFT>0&&aft[id].s[posAFT+1]!=aft[id].s[i])
            posAFT=aft[id].nxt[posAFT];
        if(posBF==bf[id].len){
            if(posAFT==aft[id].len){
                if(i>=rt&&i-aft[id].len+1<=lft) cnt++;
                posAFT=aft[id].nxt[posAFT];
            }
            posBF=bf[id].nxt[posBF];
        }else if(posAFT==aft[id].len){
            posAFT=aft[id].nxt[posAFT];
        }
    }
    return cnt;
}

void solve(){
	cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>bf[i].s>>aft[i].s;
        aft[i].id=i;aft[i].len=aft[i].s.length();
        bf[i].id=i;bf[i].len=bf[i].s.length();
        calNxtBF(i);calNxtAFT(i);
    }
    while(q--){
        cin>>tBF>>tAFT;
        ll ans=0;l=tBF.length();
        lft=0,rt=l-1;
        while(tBF[lft]==tAFT[lft]) lft++;
        while(tBF[rt]==tAFT[rt]) rt--;
        for(int i=1;i<=n;i++) ans+=check(i);
        cout<<ans<<endl;
    }
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ll T;T=1;while(T--) solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
