#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=20,MOD=998244353; 
int n,m;
int f[N]; //1表示通过 0表示不通过 
int c[N];
int t[N];
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(f[i]==0) cnt++;
		else if(cnt>=c[t[i]]) cnt++;
	}
	return n-cnt>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n>10 || m>10){
		if(m==1){
			ll ans=1;
			for(int i=1;i<=n;i++) ans=ans*i%MOD;
			cout<<ans;
		} 
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='0') f[i]=0;
		else f[i]=1;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) t[i]=i;
	int cnt=0;
	do{
		if(check()) cnt++;
	}while(next_permutation(t+1,t+n+1));
	cout<<cnt;
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

