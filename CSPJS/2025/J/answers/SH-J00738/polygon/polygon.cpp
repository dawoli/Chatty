#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n;int a[25];
//24pts
bool x1520=true;
long long qp(long long a,long long k){
	long long ans=1;
	long long p=a;
	while(k){
		if(k&1) ans=ans*p%M;
		p=p*p%M;
		k>>=1;
	}
	return ans;
}
//40pts
bool x110=true;
int cnt;
//int ch[25];
int ans;
void solve(int step,int sum,int pre){
	if(step>n){
		if(cnt>=3 && sum>2*pre){
//			for(int i=1;i<=cnt;i++)
//				cout<<ch[i]<<" ";cout<<endl;
			ans++;
		}
		return;
	}
	++cnt;
//	ch[cnt]=a[step];
	solve(step+1,sum+a[step],a[step]);
	--cnt;
	solve(step+1,sum,pre);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;if(n>20) x110=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=2) x1520=false;
	}
	if(x1520){
		cout<<qp(2,n)-(n-1)*n/2-(n+1)<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	if(x110){
		solve(1,0,0);
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
