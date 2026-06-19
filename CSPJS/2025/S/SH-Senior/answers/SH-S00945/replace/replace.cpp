#include<bits/stdc++.h>
using namespace std;
long long n,m,q,l,r,nw,wn,ta,tb,tt,mm,ans;
char s[5000009],t[5000009];
const long long B=37,mod=1000000009;
unordered_map<long long,int> a,b[200009],to[200009];
unordered_map<long long,int>::iterator it;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%s%s",s+1,t+1);
        m=strlen(s+1);
        l=1;r=m;
        while(l<=m&&s[l]==t[l])l++;
        while(r&&s[r]==t[r])r--;
        if(r>=l){
            nw=0;wn=0;
            for(int j=l;j<=r;j++){
                wn++;
                nw=(nw*B+s[j]-'a'+1)%mod;
            }
            wn++;
            nw=(nw*B+29)%mod;
            for(int j=l;j<=r;j++){
                wn++;
                nw=(nw*B+t[j]-'a'+1)%mod;
            }
            nw+=wn*mod;
            auto ii=a.insert(make_pair(nw,++ta));
            if(!ii.second)ta--,tt=ii.first->second;
            else tt=ta;
            nw=0;wn=0;
            for(int j=l-1;j;j--){
                wn++;
                nw=(nw*B+s[j]-'a'+1)%mod;
            }
            nw+=wn*mod;
            mm=nw;
            nw=0;wn=0;
            for(int j=r+1;j<=m;j++){
                wn++;
                nw=(nw*B+s[j]-'a'+1)%mod;
            }
            nw+=wn*mod;
            ii=b[tt].insert(make_pair(mm,++tb));
            if(!ii.second)tb--,mm=ii.first->second;
            else mm=tb;
            ii=to[mm].insert(make_pair(nw,1));
            if(!ii.second)ii.first->second++;
        }
    }
    while(q--){
        scanf("%s%s",s+1,t+1);
        m=strlen(s+1);
        l=1;r=m;
        while(l<=m&&s[l]==t[l])l++;
        while(r&&s[r]==t[r])r--;
        if(r>=l){
            nw=0;wn=0;
            for(int j=l;j<=r;j++){
                wn++;
                nw=(nw*B+s[j]-'a'+1)%mod;
            }
            wn++;
            nw=(nw*B+29)%mod;
            for(int j=l;j<=r;j++){
                wn++;
                nw=(nw*B+t[j]-'a'+1)%mod;
            }
            nw+=wn*mod;
            if(!a[nw]){
                puts("0");
                continue;
            }
            tt=a[nw];
            unordered_map<long long,int> ss;
            ss[0]=1;
            ans=0;
            nw=0;wn=0;
            for(int j=r+1;j<=m;j++){
                wn++;
                nw=(nw*B+s[j]-'a'+1)%mod;
                ss.insert(make_pair(nw+wn*mod,1));
            }
            if(b[tt][0]){
                mm=b[tt][0];
                for(auto k:to[mm]){
                    if(ss.find(k.first)!=ss.end())ans+=k.second;
                }
            }
            nw=0;wn=0;
            for(int j=l-1;j;j--){
                wn++;
                nw=(nw*B+s[j]-'a'+1)%mod;
                mm=nw+wn*mod;
                if(!b[tt][mm])continue;
                mm=b[tt][mm];
                for(auto k:to[mm]){
                    if(ss.find(k.first)!=ss.end())ans+=k.second;
                }
            }
            printf("%lld\n",ans);
        }
        else puts("0");
    }
}
