#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5*1e2+5,P=998244353;
int n,a[N];
ll ans;
void dfs(int now,int cnt,int k,int last){
	if(cnt==n+1){
		if(k>=3&&now>a[last]*2){
			ans++;
			ans%=P;
		}
		return ;
	}
	dfs(now,cnt+1,k,last);
	dfs(now+a[cnt],cnt+1,k+1,cnt);
}
int c(int x,int y){
	ll s=1;
	for(ll i=x;i>y;i--){
		s*=i;
		s/=(x-i+1);
	}
	return s%P;
}
void f(){
	int answ=0;
	for(int i=3;i<=n;i++){
		answ+=c(n,i);
		answ%=P;
	}
	cout<<answ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=true; 
	}
	if(n>=500&&!flag){
		f();
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(0,1,0,0);
	cout<<ans;
	return 0;
}
