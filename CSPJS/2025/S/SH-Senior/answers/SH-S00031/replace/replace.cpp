#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
const ll M=5000009;
ll n,q,l1,l2,len,ans,cnt[2],qian,hou;
ll loc[M][2],border[M];
string s[N][3],t[N][3],u,v,tar,mod1,mod2;
void solve10(){
	for(ll tp=1;tp<=q;tp++){
		ans=0;
		u=" "+t[tp][1],v=" "+t[tp][2]; len=u.size()-1;
		for(ll i=1;i<=n;i++){
			if(s[i][1].size()>len) continue;
			for(ll loc=1;loc<=len-s[i][1].size()+1;loc++){
				bool isc=true;
				for(ll k=loc;k<=loc+s[i][1].size()-1;k++)
					if(u[k]!=s[i][1][k-loc]||v[k]!=s[i][2][k-loc]){isc=false; break;}
				if(isc==false) continue;
				for(ll k=1;k<loc;k++) if(u[k]!=v[k]){isc=false; break;}
				if(isc==false) continue;
				for(ll k=loc+s[i][1].size();k<=len;k++) if(u[k]!=v[k]){isc=false; break;}
				if(isc==false) continue;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}
void KMP(string s,string t,ll op){
	for(ll i=0;i<t.size();i++) border[i]=0,loc[i][op]=0; cnt[op]=0;
	ll j=0;
	for(ll i=2;i<t.size();i++){
		while(j&&t[i]!=t[j+1]) j=border[j];
		if(t[i]==t[j+1]) j++;
		border[i]=j;
	}
	j=0;
	for(ll i=1;i<s.size();i++){
		while(j&&s[i]!=t[j+1]) j=border[j];
		if(s[i]==t[j+1]) j++;
		if(j==t.size()-1) loc[++cnt[op]][op]=i,j=border[j];
	}
}
void solvekmp(){
	for(ll tp=1;tp<=q;tp++){
		ans=0;
		u=" "+t[tp][1],v=" "+t[tp][2]; len=u.size()-1;
		qian=0,hou=len+1;
		for(ll i=1;i<=len;i++) if(u[i]==v[i]) qian++; else break;
		for(ll i=len;i>=1;i--) if(u[i]==v[i]) hou--; else break;
		for(ll i=1;i<=n;i++){
			mod1=" "+s[i][1],mod2=" "+s[i][2];
			if(mod1.size()>len+1) continue;
			KMP(u,mod1,0LL); KMP(v,mod2,1LL); 
			ll nw0=1,nw1=1;
			while(nw0<=cnt[0]&&nw1<=cnt[1]){
				while(loc[nw0][0]<loc[nw1][1]&&nw0<=cnt[0]) nw0++;
				while(loc[nw0][0]>loc[nw1][1]&&nw1<=cnt[1]) nw1++;
				if(nw0<=cnt[0]&&nw1<=cnt[1]&&loc[nw0][0]==loc[nw1][1]){
					if(loc[nw0][0]-mod1.size()+1<=qian&&loc[nw0][0]+1>=hou) ans++;
					nw0++; nw1++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++) cin>>s[i][1]>>s[i][2],l1+=s[i][1].size(),l1+=s[i][2].size();
	for(ll i=1;i<=q;i++) cin>>t[i][1]>>t[i][2],l2+=t[i][1].size(),l2+=t[i][2].size();
	if(n<=100&&q<=100&&l1<=200&&l2<=200) solve10();
	else
		solvekmp(); 
	return 0;
}

