#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,ans;
int d[5009];
bool ok[29];
void solve0(){
	if(d[1]+d[2]>d[3]){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
void dfs(int step){
	if(step==n+1){
		int sum=0,maxn=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(ok[i]){
				sum+=d[i];
				maxn=max(maxn,d[i]);
				cnt++;
			}
		}
		if(sum>maxn*2&&cnt>=3){
			ans++;
		}
		return;
	}
	dfs(step+1);
	ok[step]=1;
	dfs(step+1);
	ok[step]=0;
}
void solve1(){
	dfs(1);
	cout<<ans;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	sort(d+1,d+1+n);
	if(n<=3){
		solve0();
		return 0;
	}
	else if(n<=20){
		solve1();
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++){
		ans*=2;
		ans%=Mod;
	}
	ans-=n*(n-1)/2;
	ans=((ans%Mod)+Mod)%Mod;
	ans-=n;
	ans=((ans%Mod)+Mod)%Mod;
	ans-=1;
	ans=((ans%Mod)+Mod)%Mod;
	cout<<ans;
	return 0;
}
