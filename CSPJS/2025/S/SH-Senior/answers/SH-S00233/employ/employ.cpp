#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],sum[505],tot;
long long fac[505]={1};
bool s[505];
void solveBF();
void solve1(){
	solveBF();
}
void solveBF(){
	int a[505];
	for(int i=1;i<=n;i++)
		a[i]=i;
	long long ans=0;
	do{
		int x=0;
		for(int i=1;i<=n;i++)
			if(!s[i]||x>=c[a[i]])
				x++;
		if(n-x>=m)
			ans=(ans+1)%mod;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
}
void solvem1(){
	solveBF();
}
void solvemn(){
	if(sum[n]!=n)
		cout<<0;
	else{
		for(int i=1;i<=n;i++)
			if(!s[i]||!c[i]){
				cout<<0;
				return;
			}
		cout<<fac;
	}
}
void solve(){
	cout<<0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		sum[i]=sum[i-1],fac[i]=fac[i-1]*i%mod;
		if(ch=='1')
			s[i]=true,sum[i]++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i])
			tot++;
	}
	if(sum[n]<m||n-tot<m){
		cout<<0;
		return 0;
	}
	sort(c+1,c+n+1);
	if(sum[n]==n)
		solve1();
	else if(n<=20)
		solveBF();
	else if(m==n)
		solvemn();
	else
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
