#include<bits/stdc++.h>
const long long MOD=998244353;
using namespace std;
long long c[505],n,m,ans=0;
bool s[505],pc[505];
long long z[505],t[505];
long long ln[505];
void find(long long x){
	if(x==n+1){
		long long de=0;
		for(long long i=1;i<=n;i++){
			if(de>=c[ln[i]] || s[i]==0)	de++;
		}	
		/*for(int i=1;i<=n;i++)	cout<<ln[i]<<" ";
		cout<<endl;
		cout<<de<<endl;*/
		if(n-de>=m){
			ans=(ans+1)%MOD;
		}
		return ;
	}
	for(long long i=1;i<=n;i++){
		if(pc[i]==0){
			pc[i]=1;
			ln[x]=i;
			find(x+1);
			pc[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	z[0]=1;
	for(long long i=1;i<=500;i++)	z[i]=z[i-1]*i%MOD;
	cin>>n>>m;
	string ss;
	cin>>ss;
	for(long long i=1;i<=n;i++){
		if(ss[i-1]=='1')	s[i]=1;
		else s[i]=0;
	}
	for(long long i=1;i<=n;i++)	cin>>c[i];
	bool flag=1;
	for(long long i=1;i<=n;i++)	flag=flag && s[i];
	if(m==n){
		for(long long i=1;i<=n;i++){
			if(c[i]==0)	flag=0;
		}
		if(flag)	cout<<z[n];
		else	cout<<0;
		return 0;
	}
	find(1);
	cout<<ans;
	return 0;
}

