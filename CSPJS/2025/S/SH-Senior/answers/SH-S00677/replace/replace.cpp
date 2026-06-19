#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009,L=5000009,C1=137,C2=211,MOD=1e9+7;
const ll SL=2009;
string s[N][2],t[N][2];
ll n,q,h1[SL][2],h2[SL][2];
vector<ll> ch[L+L];
ll gh(string str){
	ll h1=0,h2=0;
	for(ll i=0;i<str.size();i++){
	    h1=(h1*C1+(str[i]-'0'))%MOD;
		h2=(h2*C2+(str[i]-'0'))%MOD;
	}
	return h1*MOD+h2;
}
ll ksm(ll d,ll z){
	ll ans=1;
	while(z){
		if(z&1)ans=ans*d%MOD;
		d=d*d%MOD;
		z/=2;
	}
	return ans;
}
bool canLLlog(){
	ll l2=0;
	for(ll i=1;i<=q;i++)l2+=t[i][0].size()+t[i][1].size();
	return l2<=2000;
}
ll gsh1(ll id,ll l,ll r){
	return ((h1[r][id]-h1[l-1][id]*ksm(C1,r-l+1))%MOD+MOD)%MOD;
}
ll gsh2(ll id,ll l,ll r){
	return ((h2[r][id]-h2[l-1][id]*ksm(C2,r-l+1))%MOD+MOD)%MOD;
}
void solveLLlog(){
	map<pair<ll,ll>,ll> mp;
	for(ll i=1;i<=n;i++){
		ll gh1=gh(s[i][0]),gh2=gh(s[i][1]); 
//		cout<<i<<" "<<(gh1/MOD)<<" "<<(gh1%MOD)<<" "<<(gh2/MOD)<<" "<<(gh2%MOD)<<"\n";
	    mp[make_pair(gh1,gh2)]++;
	}
	for(ll i=1;i<=q;i++){
//		cout<<"checking "<<i<<"\n";
		if(t[i][0].size()!=t[i][1].size()){
			cout<<0<<"\n";
			continue;
		}
		for(ll id=0;id<2;id++){
			for(ll j=0;j<t[i][id].size();j++){
				h1[j+1][id]=(h1[j][id]*C1+(t[i][id][j]-'0'))%MOD;
				h2[j+1][id]=(h2[j][id]*C2+(t[i][id][j]-'0'))%MOD;
//				cout<<id<<" "<<(j+1)<<" "<<h1[j+1][id]<<" "<<h2[j+1][id]<<"\n";
			}
		}
		ll l=0,r=t[i][0].size()-1;
		while(l<t[i][0].size()&&t[i][0][l]==t[i][1][l])l++;
		while(r>l&&t[i][0][r]==t[i][1][r])r--;
		ll ans=0;
		if(l>r){
			for(ll lb=1;lb<=t[i][0].size();lb++){
				for(ll rb=lb;rb<=t[i][0].size();rb++){
					ll sh=gsh1(0,lb,rb)*MOD+gsh2(0,lb,rb);
					ans+=mp[make_pair(sh,sh)];
				}
			}
		}else{
			l++,r++;
			for(ll lb=1;lb<=l;lb++){
				for(ll rb=r;rb<=t[i][0].size();rb++){
					ll sh0=gsh1(0,lb,rb)*MOD+gsh2(0,lb,rb);
					ll sh1=gsh1(1,lb,rb)*MOD+gsh2(1,lb,rb);
//					cout<<lb<<" "<<rb<<" "<<(sh0/MOD)<<" "<<(sh0%MOD)<<" "<<(sh1/MOD)<<" "<<(sh1%MOD)<<"\n";
					ans+=mp[make_pair(sh0,sh1)];
				}
			}
		}
		cout<<ans<<"\n";
	}
}
bool B(){
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<2;j++){
			ll cnta=0,cntb=0;
			for(ll k=0;k<s[i][j].size();k++){
				if(s[i][j][k]=='a')cnta++;
				else if(s[i][j][k]=='b')cntb++;
			}
			if(cnta!=s[i][j].size()-1||cntb!=1)return 0;
		}
	}
	for(ll i=1;i<=q;i++){
		for(ll j=0;j<2;j++){
			ll cnta=0,cntb=0;
			for(ll k=0;k<t[i][j].size();k++){
				if(t[i][j][k]=='a')cnta++;
				else if(t[i][j][k]=='b')cntb++;
			}
			if(cnta!=t[i][j].size()-1||cntb!=1)return 0;
		}
	}
	return 1;
}
void solveB(){
	for(ll i=1;i<=n;i++){
		ll yb1=0,yb2=0;
		while(s[i][0][yb1]!='b')yb1++;
		while(s[i][1][yb2]!='b')yb2++;
		ch[yb2-yb1+L].push_back(s[i][0].size());
	}
	for(ll i=1;i<=q;i++){
		if(t[i][0].size()!=t[i][1].size()){
			cout<<0<<"\n";
			continue;
		}
		ll yb1=0,yb2=0;
		while(t[i][0][yb1]!='b')yb1++;
		while(t[i][1][yb2]!='b')yb2++;
		ll fd=yb2-yb1+L;
		ll l=-1,r=ch[fd].size();
		while(l+1!=r){
			ll mid=(l+r)/2;
			if(ch[fd][mid]<=t[i][0].size())l=mid;
			else r=mid;
		}
		cout<<(l+1)<<"\n";
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(ll i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(ll i=1;i<=q;i++)cin>>t[i][0]>>t[i][1];
	if(canLLlog())solveLLlog();
	else if(B())solveB();
	else cout<<"wo bu hui\n";
	return 0;
}
