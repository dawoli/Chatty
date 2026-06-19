#include<bits/stdc++.h>
using namespace std;

const int N = 5e3+10;
const long long S = 998244353;
long long n;
long long a[N];
long long b[N];
long long ans;

long long p(long long x){
	if(n-x<x) x = n-x;
	long long res = 1;
	for(long long i = 1;i<=x;i++){
		res = res*(n-i+1)/i;
	}
	return res%S;
}
void dfs(int k,int s,int m,int l,bool f){
	if(k == n+1) return;
	if(l>=3&&s>2*m&&f){
//		cout<<k<<' '<<s<<' '<<m<<' '<<l<<endl;
		ans++;
	}
//	cout<<k<<' '<<s<<' '<<m<<' '<<l<<endl;
	dfs(k+1,s+a[k+1],m>a[k+1]?m:a[k+1],l+1,true);
	dfs(k+1,s,m,l,false);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	if(b[1] == n){
		for(long long i = n-3;i>=1;i--){
			long long s = p(i);
			ans+=s;
		}
		ans++;
	}
	else dfs(0,0,0,0,0);
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

