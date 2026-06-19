#include<bits/stdc++.h>

using namespace std;

ifstream fin("employ.in");
ofstream fout("employ.out");
#define cin fin
#define cout fout
#define endl '\n'

using ll=long long;
const int N=5e2+9;
const int mod=998244353;
inline void AddAs(int &x,int y){if((x+=y)>=mod) x-=mod;}
inline void SubAs(int &x,int y){if((x-=y)<0) x+=mod;}
inline void MulAs(int &x,int y){x=1ll*x*y%mod;}
inline int Add(int x,int y){if((x+=y)>=mod) x-=mod;return x;}
inline int Sub(int x,int y){if((x-=y)<0) x+=mod;return x;}
inline int Mul(int x,int y){return 1ll*x*y%mod;}
inline int QPow(int x,int y){
	int res=1;
	while(y){
		if(y&1) MulAs(res,x);
		MulAs(x,x);
		y>>=1;
	}
	return res;
}
inline int Inv(int x){return QPow(x,mod-2);}

int fac[N],ifac[N];
inline void Init(int lim){
	fac[0]=1;
	for(int i=1;i<=lim;i++) fac[i]=Mul(fac[i-1],i);
	ifac[lim]=Inv(fac[lim]);
	for(int i=lim-1;~i;i--) ifac[i]=Mul(ifac[i+1],i+1);
}
inline int C(int n,int m){
	if(m>n||m<0) return 0;
	else return Mul(fac[n],Mul(ifac[m],ifac[n-m]));
}

int c[N],n,m;
char s[N];

signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];

	vector<int> p(n);
	iota(p.begin(),p.end(),1);
	
	int ans=0;
	do{
		int cnt=0,res=0;
		for(int i=1;i<=n;i++){
			int j=p[i-1];
			if(s[i]=='0'||cnt>=c[j]) cnt++;
			else res++;
		}
		if(res>=m) ans++;
	}while(next_permutation(p.begin(),p.end()));

	cout<<ans<<endl;

	return 0;
}