#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,Mod=1e9+10597,Base=10111,M=5e6+10;
vector<long long>hs1[N],hs2[N]; string s1[N],s2[N],t1,t2;
int l[N]; long long p[M],h1[M],h2[M];
long long gets1(int k,int l,int r) {
    if(!l) return hs1[k][r];
    return (hs1[k][r]-hs1[k][l-1]*p[r-l+1]%Mod+Mod)%Mod;
}
long long gets2(int k,int l,int r) {
    if(!l) return hs2[k][r];
    return (hs2[k][r]-hs2[k][l-1]*p[r-l+1]%Mod+Mod)%Mod;
}
long long gett1(int l,int r) {
    if(!l) return h1[r];
    return (h1[r]-h1[l-1]*p[r-l+1]%Mod+Mod)%Mod;
}
long long gett2(int l,int r) {
    if(!l) return h2[r];
    return (h2[r]-h2[l-1]*p[r-l+1]%Mod+Mod)%Mod;
}
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    p[0]=1;
    for(int i=1;i<=M-5;i++) p[i]=p[i-1]*Base%Mod;
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>s1[i]>>s2[i],l[i]=s1[i].size(),hs1[i].resize(l[i]),hs1[i][0]=s1[i][0]-'a'+1;
        for(int j=1;j<l[i];j++) hs1[i][j]=(hs1[i][j-1]*Base%Mod+s1[i][j]-'a'+1)%Mod;
        hs2[i].resize(l[i]),hs2[i][0]=s2[i][0]-'a'+1;
        for(int j=1;j<l[i];j++) hs2[i][j]=(hs2[i][j-1]*Base%Mod+s2[i][j]-'a'+1)%Mod;
    }
    while(q--) {
        cin>>t1>>t2;
        int l1=t1.size(),l2=t2.size();
        if(l1!=l2) { cout<<"0\n"; continue; }
        h1[0]=t1[0]-'a'+1;
        for(int i=1;i<l1;i++) h1[i]=(h1[i-1]*Base%Mod+t1[i]-'a'+1)%Mod;
        h2[0]=t2[0]-'a'+1;
        for(int i=1;i<l1;i++) h2[i]=(h2[i-1]*Base%Mod+t2[i]-'a'+1)%Mod;
        long long cnt=0;
        for(int i=1;i<=n;i++)
            if(l[i]==l1&&gets1(i,0,l[i]-1)==gett1(0,l1-1)&&gets2(i,0,l[i]-1)==gett2(0,l1-1)) cnt++;
        //cout<<cnt<<'\n';
        for(int i=0;i<l1;i++) {
            if(gett1(0,i)!=gett2(0,i)) break;
            //cout<<i<<'\n';
            for(int j=1;j<=n;j++) {
                if(l[j]+i>=n) continue;
                if(gett1(i+1,l[j]+i)!=gets1(j,0,l[j]-1)) continue;
                if(gett2(i+1,l[j]+i)!=gets2(j,0,l[j]-1)) continue;
                if(gett1(l[j]+i+1,l1-1)==gett2(l[j]+i+1,l1-1)) cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
