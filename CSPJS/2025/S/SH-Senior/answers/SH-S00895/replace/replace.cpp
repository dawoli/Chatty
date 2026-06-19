#include<bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define down(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll INF=1e15;
const ull BASE=240441620163;
void file(){
	 freopen("replace.in","r",stdin);
	 freopen("replace.out","w",stdout);
}
//本人最后一个赛季，祭~
//感谢八年来OI带来的欢乐，以及不一样的人生经历~
const ll N=5000009;
ll n,q;
ull powB[N],H1[N],H2[N];
ull p1H[N],p2H[N];
string s1[N],s2[N];
string t1[N],t2[N];
ull get_H(string s){
	ull H=0;
	ll len=s.size();
	rep(i,0,len-1)H=H*BASE+s[i]-'a';
	return H;
}
void input(){
	cin>>n>>q;
	rep(i,1,n){
		cin>>s1[i]>>s2[i];
		H1[i]=get_H(s1[i]);
		H2[i]=get_H(s2[i]);
	}
	powB[0]=1;
	rep(i,1,N-4)powB[i]=powB[i-1]*BASE; 
}
ll lens1[N];
void solveBF(){
	rep(i,1,n)lens1[i]=s1[i].size();
	rep(iQ,1,q){
		string p1,p2;
		cin>>p1>>p2;
		if(p1.size()!=p2.size()){
			cout<<0<<endl;
			continue;
		}
		p1H[0]=p2H[0]=0;
		ll lenp1=p1.size();
		ll lenp2=p2.size();
		rep(i,1,lenp1){
			p1H[i]=p1H[i-1]*BASE+p1[i-1]-'a';
			p2H[i]=p2H[i-1]*BASE+p2[i-1]-'a';	
		}
		ll res=0;
		rep(i,1,lenp1){
			rep(j,1,n){
				ll len1j=lens1[j];
				if(i+len1j-1>lenp1)continue;
				ll r=i+len1j-1;
				ll l=i;
				ull H=p1H[r]-p1H[l-1]*powB[r-l+1];
				if(H!=H1[j])continue;
				ull endH=p1H[l-1]*powB[lenp1-i+1]+H2[j]*powB[lenp1-r]+p1H[lenp1]-p1H[r]*powB[lenp1-r];
//				cout<<i<<" "<<j<<" "<<l<<" "<<r<<" "<<H<<" "<<H1[j]<<endl;
				if(endH!=p2H[lenp2])continue;
				res++;
			}
		}
		cout<<res<<endl;
	}
}
int main(){
	file();
	input();
	solveBF();
	return 0;
}


